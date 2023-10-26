#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>
#include <libfixmath/fix16.h>

#include "array.h"
#include "display.h"

#include "array.h"
#include "vector.h"
#include "mesh.h"

triangle_t* triangles_to_render = NULL;

vec3_t camera_position = { .x = 0, .y = 0, .z = -5 };

fix16_t fov_factor;

bool is_running = false;

int previous_frame_time = 0;

void setup(void) {

    camera_position = (vec3_t){ .x = fix16_from_float(0), .y = fix16_from_float(0), .z = fix16_from_float(-5) };

    fov_factor = fix16_from_float(640);

    // Allocate the required memory in bytes to hold the color buffer
    color_buffer = (uint16_t*) malloc(sizeof(uint16_t) * window_width * window_height);

    // Creating a SDL texture that is used to display the color buffer
    color_buffer_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB4444,
        SDL_TEXTUREACCESS_STREAMING,
        window_width,
        window_height
    );

    // Loads the cube values in the mesh data structures
    // load_cube_mesh_data();
#ifdef LOCAL
    load_obj_file_data("./assets/f22.obj");
#else
    load_f22_mesh_data();
#endif
}

void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                is_running = false;
            break;
    }
}

// Function that receives a 3D vector and returns a projected 2D point
vec2_t project(vec3_t point) {
    vec2_t projected_point = {
        .x = fix16_div(fix16_mul(fov_factor, point.x), point.z),
        .y = fix16_div(fix16_mul(fov_factor, point.y), point.z)
    };
    return projected_point;
}

void update(void) {

    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - previous_frame_time);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
        SDL_Delay(time_to_wait);
    }

    previous_frame_time = SDL_GetTicks();

    // Initialize the array of triangles to render
    triangles_to_render = NULL;

    mesh.rotation.x += fix16_from_float(0.1);
    mesh.rotation.y += fix16_from_float(0.0);
    mesh.rotation.z += fix16_from_float(0.0);

    // Loop all triangle faces of our mesh
    int num_faces = array_length(mesh.faces);
    for (int i = 0; i < num_faces; i++) {
        face_t mesh_face = mesh.faces[i];

        vec3_t face_vertices[3];
        face_vertices[0] = mesh.vertices[mesh_face.a - 1];
        face_vertices[1] = mesh.vertices[mesh_face.b - 1];
        face_vertices[2] = mesh.vertices[mesh_face.c - 1];

        triangle_t projected_triangle;

        // Loop all three vertices of this current face and apply transformations
        for (int j = 0; j < 3; j++) {
            vec3_t transformed_vertex = face_vertices[j];

            transformed_vertex = vec3_rotate_x(transformed_vertex, mesh.rotation.x);
            transformed_vertex = vec3_rotate_y(transformed_vertex, mesh.rotation.y);
            transformed_vertex = vec3_rotate_y(transformed_vertex, mesh.rotation.z);

            // Translate the vertex away from the camera
            transformed_vertex.z -= camera_position.z;

            // Project the current vertex
            vec2_t projected_point = project(transformed_vertex);

            // Scale and translate the projected points to the middle of the screen
            projected_point.x += fix16_from_float(window_width / 2);
            projected_point.y += fix16_from_float(window_height / 2);

            projected_triangle.points[j] = projected_point;
        }

        // Save the projected triangle in the array of triangles to render
        array_push(triangles_to_render, projected_triangle);
    }
}

void render(void) {
    clear_color_buffer(0xF000);

    draw_grid();

    // Loop all projected triangles and render them
    int num_triangles = array_length(triangles_to_render);
    for (int i = 0; i < num_triangles; i++) {
        triangle_t triangle = triangles_to_render[i];

        // Draw vertex points
        draw_rect(fix16_to_int(triangle.points[0].x), fix16_to_int(triangle.points[0].y), 3, 3, 0xFFF0);
        draw_rect(fix16_to_int(triangle.points[1].x), fix16_to_int(triangle.points[1].y), 3, 3, 0xFFF0);
        draw_rect(fix16_to_int(triangle.points[2].x), fix16_to_int(triangle.points[2].y), 3, 3, 0xFFF0);

        // Draw unfilled triangles
        draw_triangle(
            fix16_to_int(triangle.points[0].x),
            fix16_to_int(triangle.points[0].y),
            fix16_to_int(triangle.points[1].x),
            fix16_to_int(triangle.points[1].y),
            fix16_to_int(triangle.points[2].x),
            fix16_to_int(triangle.points[2].y),
            0xF0F0
        );
    }

    // Clear the array of triangles to render every frame loop
    array_free(triangles_to_render);

    render_color_buffer();

    SDL_RenderPresent(renderer);
}

void free_resources(void) {
    free(color_buffer);
    array_free(mesh.faces);
    array_free(mesh.vertices);
}

int main(void) {

    is_running = initialize_window();

    setup();

    while (is_running) {
        process_input();
        update();
        render();
    }

    destroy_window();
    free_resources();

    return 0;
}
