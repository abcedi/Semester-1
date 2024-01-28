/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Abcedi Ilacas
Student ID#: 138180211
Email      : ailacas1@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define maxLives 10
#define minLives 1
#define maxPathLength 70
#define minPathLength 10
#define multiples 5

struct playerInfo
{
    char symbol;
    int lives;
    int treasure[maxPathLength];
    int history[maxPathLength];
};

struct gameInfo
{
    int maxMoves;
    int pathLength;
    int bombs[maxPathLength];
    int treasure[maxPathLength];
};

int main(void)
{
    struct playerInfo player;
    struct gameInfo game;
    int i;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf("%c%*c", &player.symbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d%*c", &player.lives);

        if (player.lives < minLives || player.lives > maxLives)
        {
            printf("     Must be between 1 and 10!\n");
        }
    }
    while (player.lives <= minLives || player.lives >= maxLives);

    for (i = 0; i < maxPathLength; i++)
    {
        player.history[i] = 0;
        player.treasure[i] = 0;
    }

    printf("Player configuration set-up is complete\n");
    printf("\nGAME Configuration\n");
    printf("------------------\n");

    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", multiples, minPathLength, maxPathLength);
        scanf("%d%*c", &game.pathLength);

        if (game.pathLength <= minPathLength || game.pathLength >= maxPathLength || game.pathLength % multiples != 0)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", multiples, minPathLength, maxPathLength);
        }

    }
    while (game.pathLength <= minPathLength || game.pathLength >= maxPathLength || game.pathLength % multiples != 0);

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d%*c", &game.maxMoves);

        if (game.maxMoves < player.lives || game.maxMoves > ((int)game.pathLength * 0.75))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int)(game.pathLength * 0.75));
        }
    }
    while (game.maxMoves < player.lives || game.maxMoves > (int)(game.pathLength * 0.75));

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", multiples);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);


    for (i = 0; i < game.pathLength; i++)
    {
        if (i % multiples == 0)
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + multiples);
        }
        scanf("%d%*c", &game.bombs[i]);
    }
    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", multiples);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i++)
    {
        if (i % multiples == 0)
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + multiples);
        }
        scanf("%d%*c", &game.treasure[i]);
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    printf("\nGame:\n");
    printf("   Path Length: %d\n", game.pathLength);

    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]);
    }


    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasure[i]);
    }

    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}