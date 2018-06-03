#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stats.h"
#include "tabMap.h"

struct stats player;

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
    printf("\n1. W lewo.\n2. W prawo.\n3.W górę.\n4. W dół.\n5. Popełnij samobójstwo.\n");
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

int fight(int who)
{
    struct stats enemy;
    enemy.attackpoint = 1;
    enemy.healt = 10;
    while(enemy.healt > 0 && player.healt > 0)
    {
        printf("statsy z walki");
        enemy.healt += -player.attackpoint;
        player.healt += -enemy.attackpoint;
    }
}

void event(int number)
{
    switch(number)
    {
    case tabEnd:
    {
        printf("wygrales\n");
        exit(0);
    }
    case attack:
    {
        printf("wpadles na królika\n");
        fight(number);
        break;
    }
    default:
    {
        break;
    }
    }
}


int main()
{
    srand(time(NULL));

    int choice;
    printf("1.nowa gra\n2.naziwsko\nanykey.quit\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
        printf("1.pierwszapostac\n2.drugapostac\n");
        scanf("%d",&choice);
        player.healt = 100;
        player.attackpoint = 2;
        break;
    }
    case 2:
    {
        printf("wiktoria jabłońska\n");
        return 0;
    }
    default:
    {
        return 0;
    }
    }

    int tab[HEIGHT][WIDTH];
    tabGenerator(tab);

    int *ptr = &tab[5][5];
    tabShow(tab);
    while(1)
    {
        ptr += action();
        event( *ptr );
        //printf("%d\n", *ptr);
    }
    return 0;
}
