#include "sdl.h"

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