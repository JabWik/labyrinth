#include "events.h"
#include <stdio.h>


void fight(stats enemy) //fight
{
    while(enemy.health > 0 && player.health > 0)
    {
        printf("\nTwoje zdrowie: %i", player.health);
        printf("\nZdrowie przeciwnika: %i", enemy.health);
        enemy.health += -player.attackpoints;
        player.health += -enemy.attackpoints;
    }

    if(player.health <= 0)
    {
    printf("ZOSTAŁEŚ ZABITY\n");

    FILE *f = fopen("summary", "w");
    fprintf(f, "\nZginąłeś, pokonany przez straszliwą bestię... straciłeś wszystko co miałeś.");
    fclose(f);

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
        char password[30] = "TETRIANDOCH";
        char userword[30];

        printf("\nPodaj hasło, śmiertelniku!");

        scanf("%s", userword);

        int result;
        result = strcmp(userword, password);
        if (result == 0)
        {
            printf("WYGRAŁEŚ");
            *quit = true;
        }
        else
        {
            printf("PRZEGRAŁEŚ");
            FILE *f = fopen("summary", "w");
            fprintf(f, "\nZginąłeś, a nadzieja na wolność umarła razem z Tobą...");
            fclose(f);

            exit(0);
        }

        break;
    }


    case visited:
    {

        printf("Już tutaj byłeś! Musisz iść dalej...");
        break;
    }
    case start:
    {
        printf("Początek");
        break;
    }
    case ghost:
    {

        printf("DUCH");

        stats ghost;
        ghost.attackpoints = 5;
        ghost.health = 30;

        fight(ghost);

        player.victorypoint += 5;

        break;
    }
    case mummy:
    {
        printf("MUMIA");


        stats mummy;
        mummy.attackpoints = 10;
        mummy.health = 100;

        fight(mummy);

        player.victorypoint += 10;

        break;
    }
    case minotaur:
    {
        printf("MINOTAUR");

        stats minotaur;
        minotaur.attackpoints = 20;
        minotaur.health = 200;

        fight(minotaur);

        player.victorypoint =+ 20;

        break;
    }
    case skeleton:
    {
        printf("SKELETON");

        stats skeleton;
        skeleton.attackpoints = 15;
        skeleton.health = 150;

        fight(skeleton);

        player.victorypoint =+ 15;

        break;
    }
    case priest:
    {
        printf("KAPŁAN");

        stats priest;
        priest.attackpoints = 30;
        priest.health = 60;

        fight(priest);
        player.victorypoint = 30;

        break;
    }
    case rest:
    {
        printf("Znajdujesz komnatę.");

        player.might += 3;
        player.attackpoints += 5;

        break;
    }
    case cry:
    {
        printf("Wpadasz w rozpacz...");

        player.will -= 3;
        player.attackpoints -= 5;

        break;
    }
    case gold:
    {
        printf("Znalazłeś kupkę złota!");

        player.goldpoint += lottery(1,250);

        break;
    }
    case potion:
    {
        printf("Znalazłeś tajemniczą miksturę!");

        player.health += lottery(1,100);

        break;
    }
    case life:
    {
        int y = lottery(1,50);
        printf("Twoje życie: %i", player.health);
        printf("Punkty próby życia: %i", y);
        if (player.health < y)
        {
            printf("ZGINĄŁEŚ");
            exit(0);
        }
        else
        {
            printf("PRZEŻYŁEŚ");
            printf("Dostałeś złoto oraz wróciły Ci siły...");

            player.goldpoint += lottery(50,100);
            player.victorypoint +=10;

            player.health += 30;
        }

        break;
    }
    case will:
    {
        int y = lottery(6,14);
       printf("Twój duch: %i", player.will);
       printf("Punkty próby ducha: %i", y);
        if (player.will < y)
        {
            printf("ZGINĄŁEŚ");
            exit(0);
        }
        else
        {
            printf("PRZEŻYŁEŚ");
            printf("Dostałeś złoto oraz czujesz, że Ci się uda...");

            player.goldpoint += lottery(50,200);
            player.victorypoint +=10;

            player.attackpoints += 3;
        }

        break;
    }
    case might:
    {
        int y = lottery(6,14);
  printf("Twoje życie: %i", player.health);
     printf("Punkty próby życia: %i", y);
        if (player.health < y)
        {
            printf("ZGINĄŁEŚ");
            exit(0);
        }
        else
        {
            printf("PRZEŻYŁEŚ");
            printf("Dostałeś złoto oraz wróciły Ci siły...");

            player.goldpoint += lottery(50,100);
            player.victorypoint +=10;

            player.health += 30;
        }
        break;
    }
    case figure:
    {
        printf("Znajdujesz kapliczkę");

        int x;
        scanf("%d", &x);
        switch(x)
        {
        case 1:
            {
                printf("Jesteś pobłogosławiony!");

                player.health += 50;
                player.attackpoints += 10;
                player.might += 10;
                player.will += 10;

                player.victorypoint += 25;

                break;
            }

        default:
            {
                break;
            }
        }

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
