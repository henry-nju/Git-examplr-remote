#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <math.h>
//a = left  , w = up , s = down ,d = right ;
int chart[5][5];

int main(int args, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          600, 600, SDL_WINDOW_SHOWN);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 145;
    rect.h = 145;
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Surface *base = SDL_LoadBMP("2048picture/base.bmp");
    SDL_BlitSurface(base, NULL, surface, &rect);
    SDL_UpdateWindowSurface(window);
    SDL_Surface *p2 = SDL_LoadBMP("2048picture/2.bmp");
    SDL_Surface *p4 = SDL_LoadBMP("2048picture/4.bmp");
    SDL_Surface *p8 = SDL_LoadBMP("2048picture/8.bmp");
    SDL_Surface *p16 = SDL_LoadBMP("2048picture/16.bmp");
    SDL_Surface *p32 = SDL_LoadBMP("2048picture/32.bmp");
    SDL_Surface *p64 = SDL_LoadBMP("2048picture/64.bmp");
    SDL_Surface *p128 = SDL_LoadBMP("2048picture/128.bmp");
    SDL_Surface *p256 = SDL_LoadBMP("2048picture/256.bmp");
    SDL_Surface *p512 = SDL_LoadBMP("2048picture/512.bmp");
    SDL_Surface *p1024 = SDL_LoadBMP("2048picture/1024.bmp");
    SDL_Surface *p2048 = SDL_LoadBMP("2048picture/2048.bmp");
    SDL_Surface *blank = SDL_LoadBMP("2048picture/blank.bmp");

    SDL_Event event;
    SDL_UpdateWindowSurface(window);

    memset(chart, 0, sizeof(chart));
    srand((unsigned)time(NULL));
    int random_number;
    int random_x;
    int random_y;
    random_x = rand() % 4;
    random_number = rand() % 2;
    random_y = rand() % 4;
    chart[random_x][random_y] = (random_number + 1) * 2;
    int sign = 0;
    while (!sign)
    {
        random_x = rand() % 4;
        random_number = rand() % 2;
        random_y = rand() % 4;
        if (chart[random_x][random_y] == 0)
        {
            sign = 1;
            chart[random_x][random_y] = (random_number + 1) * 2;
        }
    }
    sign = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", chart[i][j]);
            if (chart[i][j] == 2)
            {
                rect.x = j * 150;
                rect.y = i * 150;
                SDL_BlitSurface(p2, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 4)
            {
                rect.x = j * 150;
                rect.y = i * 150;
                SDL_BlitSurface(p4, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 8)
            {
                rect.x = j * 150;
                rect.y = i * 150;
                SDL_BlitSurface(p8, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 16)
            {
                rect.x = j * 150;
                rect.y = i * 150;
                SDL_BlitSurface(p16, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 32)
            {
                rect.x = j * 150;
                rect.y = i * 150;
                SDL_BlitSurface(p32, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 64)
            {
                rect.x = j * 150;
                rect.y = i * 150;
                SDL_BlitSurface(p64, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 128)
            {
                rect.x = j * 150 + 2;
                rect.y = i * 150 + 2;
                SDL_BlitSurface(p128, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 256)
            {
                rect.x = j * 150 + 2;
                rect.y = i * 150 + 2;
                SDL_BlitSurface(p256, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 512)
            {
                rect.x = j * 150 + 2;
                rect.y = i * 150 + 2;
                SDL_BlitSurface(p512, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 1024)
            {
                rect.x = j * 150 + 2;
                rect.y = i * 150 + 2;
                SDL_BlitSurface(p1024, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
            else if (chart[i][j] == 2048)
            {
                rect.x = j * 150 + 2;
                rect.y = i * 150 + 2;
                SDL_BlitSurface(p2048, NULL, surface, &rect);
                SDL_UpdateWindowSurface(window);
            }
        }
        printf("\n");
    }

    int quit = 0;
    int whetherchange = 0;
    int beforechanged = 0;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_UP)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        beforechanged = 0;
                        for (int j = 1; j < 4; j++)
                        {
                            if (chart[j][i] != 0)
                            {
                                for (int l = j - 1; l >= 0; l--)
                                {
                                    if (chart[l][i] != 0)
                                    {
                                        if (chart[l][i] == chart[j][i] && beforechanged == 0)
                                        {
                                            chart[l][i] = chart[l][i] * 2;
                                            chart[j][i] = 0;
                                            whetherchange = 1;
                                            beforechanged = 1;
                                            break;
                                        }
                                        else if (chart[l][i] == chart[j][i] && beforechanged == 1)
                                        {
                                            chart[l + 1][i] = chart[j][i];
                                            chart[j][i] = 0;
                                            beforechanged = 0;
                                            break;
                                        }
                                        else if (l != j - 1)
                                        {
                                            chart[l + 1][i] = chart[j][i];
                                            chart[j][i] = 0;
                                            whetherchange = 1;
                                            beforechanged = 0;
                                            break;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    else if (l == 0)
                                    {
                                        chart[0][i] = chart[j][i];
                                        chart[j][i] = 0;
                                        whetherchange = 1;
                                        beforechanged = 0;
                                    }
                                }
                            }
                        }
                    }
                    if (whetherchange == 1)
                    {
                        while (!sign)
                        {
                            random_x = rand() % 4;
                            random_number = rand() % 2;
                            random_y = rand() % 4;
                            if (chart[random_x][random_y] == 0)
                            {
                                sign = 1;
                                chart[random_x][random_y] = (random_number + 1) * 2;
                            }
                        }
                        sign = 0;
                        whetherchange = 0;
                    }
                }
                else if (event.key.keysym.sym == SDLK_LEFT)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        beforechanged = 0;
                        for (int j = 1; j < 4; j++)
                        {
                            if (chart[i][j] != 0)
                            {
                                for (int l = j - 1; l >= 0; l--)
                                {
                                    if (chart[i][l] != 0)
                                    {
                                        if (chart[i][l] == chart[i][j] && beforechanged == 0)
                                        {
                                            chart[i][l] = chart[i][l] * 2;
                                            chart[i][j] = 0;
                                            whetherchange = 1;
                                            beforechanged = 1;
                                            break;
                                        }
                                        else if (chart[i][l] == chart[i][j] && beforechanged == 1)
                                        {
                                            chart[i][l + 1] = chart[i][j];
                                            chart[i][j] = 0;
                                            beforechanged = 0;
                                            break;
                                        }
                                        else if (l != j - 1)
                                        {
                                            chart[i][l + 1] = chart[i][j];
                                            chart[i][j] = 0;
                                            whetherchange = 1;
                                            beforechanged = 0;
                                            break;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    else if (l == 0)
                                    {
                                        chart[i][0] = chart[i][j];
                                        chart[i][j] = 0;
                                        whetherchange = 1;
                                        beforechanged = 0;
                                    }
                                }
                            }
                        }
                    }
                    if (whetherchange == 1)
                    {
                        while (!sign)
                        {
                            random_x = rand() % 4;
                            random_number = rand() % 2;
                            random_y = rand() % 4;
                            if (chart[random_x][random_y] == 0)
                            {
                                sign = 1;
                                chart[random_x][random_y] = (random_number + 1) * 2;
                            }
                        }
                        sign = 0;
                        whetherchange = 0;
                    }
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)

                {
                    for (int i = 3; i >= 0; i--)
                    {
                        beforechanged = 0;
                        for (int j = 2; j >= 0; j--)
                        {
                            if (chart[i][j] != 0)
                            {
                                for (int l = j + 1; l < 4; l++)
                                {
                                    if (chart[i][l] != 0)
                                    {
                                        if (chart[i][l] == chart[i][j] && beforechanged == 0)
                                        {
                                            chart[i][l] = chart[i][l] * 2;
                                            chart[i][j] = 0;
                                            whetherchange = 1;
                                            beforechanged = 1;
                                            break;
                                        }
                                        else if (chart[i][l] == chart[i][j] && beforechanged == 1)
                                        {
                                            chart[i][l - 1] = chart[i][j];
                                            chart[i][j] = 0;
                                            beforechanged = 0;
                                            break;
                                        }
                                        else if (l != j + 1)
                                        {
                                            chart[i][l - 1] = chart[i][j];
                                            chart[i][j] = 0;
                                            whetherchange = 1;
                                            beforechanged = 0;
                                            break;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    else if (l == 3)
                                    {
                                        chart[i][3] = chart[i][j];
                                        chart[i][j] = 0;
                                        whetherchange = 1;
                                        beforechanged = 0;
                                    }
                                }
                            }
                        }
                    }
                    if (whetherchange == 1)
                    {
                        while (!sign)
                        {
                            random_x = rand() % 4;
                            random_number = rand() % 2;
                            random_y = rand() % 4;
                            if (chart[random_x][random_y] == 0)
                            {
                                sign = 1;
                                chart[random_x][random_y] = (random_number + 1) * 2;
                            }
                        }
                        sign = 0;
                        whetherchange = 0;
                    }
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    for (int i = 3; i >= 0; i--)
                    {
                        beforechanged = 0;
                        for (int j = 2; j >= 0; j--)
                        {
                            if (chart[j][i] != 0)
                            {
                                for (int l = j + 1; l < 4; l++)
                                {
                                    if (chart[l][i] != 0)
                                    {
                                        if (chart[l][i] == chart[j][i] && beforechanged == 0)
                                        {
                                            chart[l][i] = chart[l][i] * 2;
                                            chart[j][i] = 0;
                                            whetherchange = 1;
                                            beforechanged = 1;
                                            break;
                                        }
                                        else if (chart[l][i] == chart[j][i] && beforechanged == 1)
                                        {
                                            chart[l - 1][i] = chart[j][i];
                                            chart[j][i] = 0;
                                            beforechanged = 0;
                                            break;
                                        }
                                        else if (l != j + 1)
                                        {
                                            chart[l - 1][i] = chart[j][i];
                                            chart[j][i] = 0;
                                            whetherchange = 1;
                                            beforechanged = 0;
                                            break;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    else if (l == 3)
                                    {
                                        chart[3][i] = chart[j][i];
                                        chart[j][i] = 0;
                                        whetherchange = 1;
                                        beforechanged = 0;
                                    }
                                }
                            }
                        }
                    }
                    if (whetherchange == 1)
                    {
                        while (!sign)
                        {
                            random_x = rand() % 4;
                            random_number = rand() % 2;
                            random_y = rand() % 4;
                            if (chart[random_x][random_y] == 0)
                            {
                                sign = 1;
                                chart[random_x][random_y] = (random_number + 1) * 2;
                            }
                        }
                        sign = 0;
                        whetherchange = 0;
                    }
                }
                SDL_BlitSurface(base, NULL, surface, &rect);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        printf("%d ", chart[i][j]);
                        if (chart[i][j] == 2)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p2, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 4)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p4, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 8)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p8, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 16)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p16, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 32)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p32, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 64)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p64, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 128)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p128, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 256)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p256, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 512)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p512, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 1024)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p1024, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 2048)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(p2048, NULL, surface, &rect);
                        }
                        else if (chart[i][j] == 0)
                        {
                            rect.x = j * 150;
                            rect.y = i * 150;
                            SDL_BlitSurface(blank, NULL, surface, &rect);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
        SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(base);
    SDL_FreeSurface(p2);
    SDL_FreeSurface(p4);
    SDL_FreeSurface(p8);
    SDL_FreeSurface(p16);
    SDL_FreeSurface(p32);
    SDL_FreeSurface(p64);
    SDL_FreeSurface(p128);
    SDL_FreeSurface(p256);
    SDL_FreeSurface(p512);
    SDL_FreeSurface(p1024);
    SDL_FreeSurface(p2048);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}