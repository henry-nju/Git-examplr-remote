#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <math.h>

int main(int args, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          603, 603, SDL_WINDOW_SHOWN);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Surface *base = SDL_LoadBMP("2048picture/base.bmp");
    SDL_BlitSurface(base, NULL, surface, &rect);
    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);
    SDL_FreeSurface(base);
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}