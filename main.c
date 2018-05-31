#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stats.h"


#define HEIGHT 11
#define WIDTH 11

enum
{
    tabEnd,
    attack,
    empty,
    treasure,
    challenge,
    shop,
    visited,
    last,
    wolf,
    sheep,
    rabbit,
};


void tabGenerator(int t[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) //wyzerowywanie krańców mapy
    {
        t[i][0] = 0;
        t[i][WIDTH-1] = 0;
    }

    for (int i = 0; i < WIDTH; i++)
    {
        t[0][i] = 0;
        t[HEIGHT-1][i] = 0;
    }

    for (int i = 1; i < HEIGHT-1; i++) //generowanie ogólne mapy
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            t[i][j] = rand()%5 + 1;
        }
    }

    for (int i = 1; i < HEIGHT-1; i++) //szczegolny przypadek dla attack
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            if(t[i][j] == attack)
            {
                t[i][j] = rand()%3 + last;
            }
        }
    }
}

void tabShow(int t[HEIGHT][WIDTH]) //pokaz mape
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
}

int action()
{
    int x;
    static int foolish = 0;

    printf("\n\n\nW którą stronę chcesz iść?");
    choice:
    if (foolish > 3)
    {
        printf("Zginales przez wlasna glupote!!!");
        getchar();
        exit(0);
    }
    printf("\n1. W lewo.\n2. W prawo.\n3.W górę.\n4. W dół.\n5. Popełnij samobójstwo.");
    scanf("%d", &x);
    switch(x)
    {
        case 1:
        {
            return -1;
        }
        case 2:
        {
            return +1;
        }
        case 3:
        {
            return -WIDTH;
        }
        case 4:
        {
            return +WIDTH;
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
        foolish++;
        printf("Nie wyglupiaj sie!!!");
        goto choice;
        }
    }
}



int main()
{
    srand(time(NULL));

    int tab[HEIGHT][WIDTH];

    tabGenerator(tab);
    tab[5][5] = visited;

    int *ptr = &tab[5][5];

    tabShow(tab);

    ptr += action();
    printf("%d\n", *ptr);

    return 0;
}
