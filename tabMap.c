#include "tabMap.h"

int lottery(int first, int last)
{
    return rand()%(1 + last - first) + first;
}

void tabGenerator(int t[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) //resetting the ends of the map
    {
        t[i][0] = 0;
        t[i][WIDTH-1] = 0;
    }
    for (int i = 0; i < WIDTH; i++)
    {
        t[0][i] = 0;
        t[HEIGHT-1][i] = 0;
    }

    for (int i = 1; i < HEIGHT-1; i++) //generating general map
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            t[i][j] = lottery(attack,figure);
        }
    }

    for (int i = 1; i < HEIGHT-1; i++) //generating special events variations under "attack event"
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            if(t[i][j] == attack)
            {
                t[i][j] = lottery(ghost,priest);
            }
        }
    }

    for (int i = 1; i < HEIGHT-1; i++) //generating special events variations under "empty event"
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            if(t[i][j] == empty)
            {
                t[i][j] = lottery(rest,cry);
            }
        }
    }

    for (int i = 1; i < HEIGHT-1; i++) //generating special events variations under "challenge"
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            if(t[i][j] == challenge)
            {
                t[i][j] = lottery(life,might);
            }
        }
    }

    for (int i = 1; i < HEIGHT-1; i++) //generating special events variations under "treasure"
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            if(t[i][j] == treasure)
            {
                t[i][j] = lottery(gold,potion);
            }
        }
    }

    for (int i = 0; i < 3; i++) // generating "password" event
    {
        t[lottery(1,10)][lottery(1,10)] = 6;
    }

    t[5][5] = start;

}

void tabShow(int t[HEIGHT][WIDTH]) //show map
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
