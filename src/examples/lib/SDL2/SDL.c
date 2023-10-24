#include "SDL.h"

#include "../io.h"

#define BASE_VIDEO  0x1000000

int SDL_Init(
    Uint32 flags
) {
    return 0;
}

SDL_Window * SDL_CreateWindow(
    const char * title,
    int x,
    int y,
    int w,
    int h,
    Uint32 flags
) {
    // clear the framebuffer
    for (unsigned int i = 0; i < 640*480*2; i += 4)
        MEM_WRITE(BASE_VIDEO + i, 0x00000000);

    return (SDL_Window *)(1);
}

SDL_Renderer * SDL_CreateRenderer(
    SDL_Window * window,
    int index,
    Uint32 flags) {
    
    return (SDL_Renderer *)(1);
}

static SDL_Keycode get_keycode(int scancode) {
    if (scancode == 0x76) {
        return SDLK_ESCAPE;
    } else {
        return SDLK_UNKNOWN;
    }
}

int SDL_PollEvent(SDL_Event * event) {
    event->type = SDL_FIRSTEVENT;
    if (key_avail()) {
        int scancode = get_key();
        if (scancode == 0xF0) {
            event->type = SDL_KEYUP;
            scancode = get_key();
            event->key.keysym.sym = get_keycode(scancode);
        } else {
            event->type = SDL_KEYDOWN;
            event->key.keysym.sym = get_keycode(scancode);
        }
        return 1;
    }
    return 0;
}

static Uint8 render_draw_color[4];
int SDL_SetRenderDrawColor(SDL_Renderer * renderer,
                   Uint8 r, Uint8 g, Uint8 b,
                   Uint8 a) {
    render_draw_color[0] = r;
    render_draw_color[1] = g;
    render_draw_color[2] = b;
    render_draw_color[3] = a;
    return 0;
}

int SDL_RenderClear(SDL_Renderer * renderer) {
    uint32_t c;
    c = render_draw_color[3] >> 4;
    c = (c << 4) | (render_draw_color[0] >> 4);
    c = (c << 4) | (render_draw_color[1] >> 4);
    c = (c << 4) | (render_draw_color[2] >> 4);
    c = (c << 4) | (render_draw_color[3] >> 4);
    c = (c << 4) | (render_draw_color[0] >> 4);
    c = (c << 4) | (render_draw_color[1] >> 4);
    c = (c << 4) | (render_draw_color[2] >> 4);

    for (unsigned int i = 0; i < 640*480*2; i += 4)
        MEM_WRITE(BASE_VIDEO + i, c);

    return 0;
}

void SDL_RenderPresent(SDL_Renderer * renderer) {
}