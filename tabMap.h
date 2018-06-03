#ifndef TABMAP_H_INCLUDED
#define TABMAP_H_INCLUDED

#define HEIGHT 11
#define WIDTH 11


enum tabEvents
{
    tabEnd = 0,

    attack = 1,
    ghost = 10,
    mummy = 11,
    minotaur = 12,
    skeleton = 13,
    priest = 14,

    empty = 2,
    rest = 20,
    cry = 21,

    treasure = 3,
    gold = 30,
    potion = 31,

    challenge = 4,
    life = 40,
    will = 41,
    might = 42,

    figure = 5,

    secret = 6,

    visited = 8,

};

int lottery(int first, int last);
void tabGenerator(int t[HEIGHT][WIDTH]);
void tabShow(int t[HEIGHT][WIDTH]);

#endif // TABMAP_H_INCLUDED
