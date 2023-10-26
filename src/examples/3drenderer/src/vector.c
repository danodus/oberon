#include <math.h>

#include "vector.h"

vec3_t vec3_rotate_x(vec3_t v, fix16_t angle) {
    vec3_t rotated_vector = {
        .x = v.x,
        .y = fix16_mul(v.y, fix16_cos(angle)) - fix16_mul(v.z, fix16_sin(angle)),
        .z = fix16_mul(v.y, fix16_sin(angle)) + fix16_mul(v.z, fix16_cos(angle))
    };
    return rotated_vector;
}

vec3_t vec3_rotate_y(vec3_t v, fix16_t angle) {
    vec3_t rotated_vector = {
        .x = fix16_mul(v.x, fix16_cos(angle)) - fix16_mul(v.z, fix16_sin(angle)),
        .y = v.y,
        .z = fix16_mul(v.x, fix16_sin(angle)) + fix16_mul(v.z, fix16_cos(angle))
    };
    return rotated_vector;
}

vec3_t vec3_rotate_z(vec3_t v, fix16_t angle) {
    vec3_t rotated_vector = {
        .x = fix16_mul(v.x, fix16_cos(angle)) - fix16_mul(v.y, fix16_sin(angle)),
        .y = fix16_mul(v.x, fix16_sin(angle)) + fix16_mul(v.y, fix16_cos(angle)),
        .z = v.z,
    };
    return rotated_vector;
}
