#ifndef _SDL_H_
#define _SDL_H_

#include <stdint.h>

#define SDL_INIT_EVERYTHING 0
#define SDL_WINDOWPOS_CENTERED 0
#define SDL_WINDOW_BORDERLESS 0

enum {
    SDLK_UNKNOWN = 0,
    SDLK_ESCAPE = '\033'
};

typedef enum
{
    SDL_FIRSTEVENT = 0,
    SDL_QUIT = 0x100,
    SDL_KEYDOWN = 0x300,
    SDL_KEYUP
} SDL_EventType;

typedef uint32_t Uint32;
typedef int32_t Sint32;
typedef uint8_t Uint8;

typedef Sint32 SDL_Keycode;

typedef struct {
} SDL_Window;

typedef struct {
} SDL_Renderer;

typedef struct SDL_Keysym {
    SDL_Keycode sym;
} SDL_Keysym;

typedef struct {
    SDL_Keysym keysym;
} SDL_KeyboardEvent;

typedef struct {
    SDL_EventType type;
    SDL_KeyboardEvent key;
} SDL_Event;

int SDL_Init(Uint32 flags);

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

int SDL_PollEvent(SDL_Event * event);

int SDL_SetRenderDrawColor(SDL_Renderer * renderer,
                   Uint8 r, Uint8 g, Uint8 b,
                   Uint8 a);

int SDL_RenderClear(SDL_Renderer * renderer);                   

void SDL_RenderPresent(SDL_Renderer * renderer);                   

#endif // _SDL_H_
