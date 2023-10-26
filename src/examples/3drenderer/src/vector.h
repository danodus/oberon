#ifndef VECTOR_H
#define VECTOR_H

#include <libfixmath/fix16.h>

typedef struct {
    fix16_t x;
    fix16_t y;
} vec2_t;

typedef struct {
    fix16_t x;
    fix16_t y;
    fix16_t z;
} vec3_t;

vec3_t vec3_rotate_x(vec3_t v, fix16_t angle);
vec3_t vec3_rotate_y(vec3_t v, fix16_t angle);
vec3_t vec3_rotate_z(vec3_t v, fix16_t angle);

#endif
