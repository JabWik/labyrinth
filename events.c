#include "events.h"
#include <stdio.h>

void fight(stats enemy)
{
    while(enemy.health > 0 && player.health > 0)
    {
        printf("statsy z walki:");
        enemy.health += -player.attackpoints;
        player.health += -enemy.attackpoints;
    }

    if(player.health <= 0)
    {
        printf("you are dead\n");
        exit(0);
    }
}

int action() //moving on the map
{
    int x;
    static int foolish = 0;

    printf("\n\n\nW którą stronę chcesz iść?");

choice:

    if (foolish > 2)
    {
        printf("\n\n\nZginąłeś przez własną głupotę!!!");
        getchar();
        exit(0);
    }
    printf("\n1. Na zachód.\n2. Na wschód.\n3. Na północ.\n4. Na południe.\n5. Popełnij samobójstwo.\n");

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
        printf("Nie wygłupiaj się!!!");
        goto choice;
    }
    }
}


void event(int *p, bool *quit) //map events
{
    int number = *p;


    switch(number)
    {
    case tabEnd:
    {
        char password[15] = "TETRIANDOCH";
        char userword[15];
        int ch=0;

        int i = 0;

        printf("\nPodaj hasło, śmiertelniku!");
        while(ch != '\n')
        {
            printf("test");
            ch = getchar();
            userword[i] = ch;
            if(i==0)
                ch=0;
            ++i;
        }
        userword[i] = '\0';
        printf("Twoje hasło: %s", userword);

        //scanf("%c", ch);
        *quit = true;

        break;
    }


    case visited:
    {

        printf("Już tutaj byłeś! Musisz iść dalej...");
        break;
    }
    case start:
    {
        printf("YOLO");
        break;
    }
    case ghost:
    {
        printf("wpadles na królika\n");
        //fight();
        break;
    }
    case mummy:
    {
        stats mummy;
        mummy.attackpoints = 10;
        mummy.health = 100;

        fight(mummy);
        break;
    }
    case minotaur:
    {
        break;
    }
    case skeleton:
    {
        break;
    }
    case priest:
    {
        break;
    }
    case rest:
    {
        break;
    }
    case cry:
    {
        break;
    }
    case gold:
    {
        break;
    }
    case potion:
    {
        break;
    }
    case life:
    {
        break;
    }
    case will:
    {
        break;
    }
    case might:
    {
        break;
    }
    case figure:
    {
        break;
    }
    case secret:
    {
        switch(lottery(1,3))
        {
        case 1:
        {
            printf("miau");
            break;
        }
        case 2:
        {
            printf("hahu");
            break;
        }
        case 3:
        {
            printf("wrrr");
            break;
        }
        }

        break;
    }
    default:
    {
        break;
    }

    }
}
