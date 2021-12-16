#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//1 = left  , 2 = up , 3 = down ,4 = right ;
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
    int beforechanged = 0;

    while (1)
    {
        scanf("%d", &input);
        whetherchange = 0;
        if (input == 4)
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