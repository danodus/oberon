#ifndef _SDL_H_
#define _SDL_H_

#define SDL_INIT_EVERYTHING 0
#define SDL_WINDOWPOS_CENTERED 0
#define SDL_WINDOW_BORDERLESS 0

typedef unsigned int Uint32;

typedef struct {
} SDL_Window;

typedef struct {
} SDL_Renderer;

int SDL_Init(
    Uint32 flags
);

SDL_Window * SDL_CreateWindow(
    const char * title,
    int x,
    int y,
    int w,
    int h,
    Uint32 flags
);

SDL_Renderer * SDL_CreateRenderer(
    SDL_Window * window,
    int index,
    Uint32 flags);

#endif // _SDL_H_
