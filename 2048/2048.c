#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int chart[5][5];

int main()
{
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
        }
        printf("\n");
    }

    int quit = 0;
    int input = 0;
    int whetherchange = 0;

    for (int q = 0; q < 20; q++)
    {
        scanf("%d", &input);
        whetherchange = 0;
        if (input = 1)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 1; j < 4; j++)
                {
                    if (chart[i][j] != 0)
                    {
                        for (int l = j - 1; l >= 0; l--)
                        {
                            if (chart[i][l] != 0)
                            {
                                if (chart[i][l] == chart[i][j])
                                {
                                    chart[i][l] = chart[i][l] * 2;
                                    chart[i][j] = 0;
                                    whetherchange = 1;
                                    break;
                                }
                                else if (l != j - 1)
                                {
                                    chart[i][l + 1] = chart[i][j];
                                    chart[i][j] = 0;
                                    whetherchange = 1;
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
                                break;
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
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    printf("%d ", chart[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}