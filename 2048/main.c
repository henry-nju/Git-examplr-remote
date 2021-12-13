#include <stdio.h>
#include <SDL2/SDL.h>

int main(int args, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          800, 600, SDL_WINDOW_SHOWN);

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Surface *image = SDL_LoadBMP("mainpicture1.bmp");

    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(rend);
    SDL_Texture *imagesurface = SDL_CreateTextureFromSurface(rend, image);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;

    SDL_Event event;
    int quit = 0;
    while (quit == 0)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (event.type == SDL_MOUSEMOTION)
            {
                rect.x = event.motion.x - (image->w / 2);
                rect.y = event.motion.y - (image->h / 2);
                SDL_FillRect(surface, NULL, 0);
                SDL_BlitSurface(image, NULL, surface, &rect);
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    printf("left\n");
                }
                else if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    printf("right\n");
                }
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_UP)
                {
                    printf("UP\n");
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    printf("down\n");
                }
                else if (event.key.keysym.sym == SDLK_LEFT)
                {
                    printf("left\n");
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    printf("right\n");
                }
            }
            SDL_UpdateWindowSurface(window);
        }
    }

    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}