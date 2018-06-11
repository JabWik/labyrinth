#include "global.h"
#include <stdbool.h>

int main()
{
    srand(time(NULL));

    bool quit = false;
    int choice;

    player.goldpoint = 0;
    player.victorypoint = 0;

    printf("1.nowa gra\n2.naziwsko\nanykey.quit\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
        printf("1.pierwszapostac\n2.drugapostac\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            player.health = 200;
            player.attackpoints = 10;
            player.will = 5;
            player.might = 15;
            break;
        }
        case 2:
        {
            player.health = 100;
            player.attackpoints = 20;
            player.will = 15;
            player.might = 5;
            break;
        }
        default:
        {
            printf("Zginąłeś");
            return 0;
        }
        }//end switch
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

    while(!quit)
    {
        event(ptr, &quit);
        *ptr = 8;
        if (quit == true){break;}
        ptr += action();
        tabShow(tab);
    }

    FILE *f = fopen("summary", "w");

    fprintf(f, "\nMapa przebytego labiryntu:\n\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            fprintf(f,"%d ",tab[i][j]);
        }
        fprintf(f,"\n");
    }

    fprintf(f, "HP %i", player.health);
    fprintf(f, "Zdobyte złoto: %i", player.goldpoint);
    fprintf(f, "Zdobyte punkty: %i", player.victorypoint);

    fclose(f);

    return 0;
}
