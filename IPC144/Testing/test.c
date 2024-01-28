#include <stdio.h>

#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MULTIPLES 5

struct Player {
    char symbol;
    int lives;
    int treasuresCollected;
    int history[MAX_PATH_LENGTH];
};

struct GameBoard {
    int pathLength;
    int maxMoves;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];
};

struct GameState {
    struct Player player;
    struct GameBoard board;
    int currentPosition;
    int movesRemaining;
};

// Function prototypes
void setupPlayer(struct GameState* gameState);
void setupGameBoard(struct GameState* gameState);
void setupGameSettings(struct GameState* gameState);
void displayGameBoard(const struct GameState* gameState);
void playGame(struct GameState* gameState);

// Main function
int main(void) {
    struct GameState gameState = { 0 };
    setupPlayer(&gameState);
    setupGameBoard(&gameState); // Corrected call
    setupGameSettings(&gameState); // Corrected call
    displayGameBoard(&gameState);
    playGame(&gameState);
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\nYou found %d treasures!\n", gameState.player.treasuresCollected);
    printf("You should play again and try to beat your score!\n");
    return 0;
}

void setupPlayer(struct GameState* gameState) {
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &gameState->player.symbol);
    do {
        printf("Set the number of lives (1-10): ");
        scanf("%d", &gameState->player.lives);
    } while (gameState->player.lives < MIN_LIVES || gameState->player.lives > MAX_LIVES);
    gameState->movesRemaining = gameState->player.lives; // Initially, moves remaining equals the number of lives
}

void setupGameBoard(struct GameState* gameState) {
    // Initialize all positions to 'no bomb' and 'no treasure'
    for (int i = 0; i < gameState->board.pathLength; i++) {
        gameState->board.bombs[i] = 0;
        gameState->board.treasures[i] = 0;
    }
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLES, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &gameState->board.pathLength);
        // Clear the input buffer to handle extra characters
        while (getchar() != '\n');
    } while (gameState->board.pathLength < MIN_PATH_LENGTH || gameState->board.pathLength > MAX_PATH_LENGTH || gameState->board.pathLength % MULTIPLES != 0);

    // Initialize all positions to 'no bomb' and 'no treasure'
    for (int i = 0; i < gameState->board.pathLength; i++) {
        gameState->board.bombs[i] = 0;
        gameState->board.treasures[i] = 0;
        gameState->player.history[i] = 0; // Initialize the player's history
    }
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    for (int i = 0; i < gameState->board.pathLength; i += MULTIPLES) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLES);
        for (int j = i; j < i + MULTIPLES && j < gameState->board.pathLength; j++) {
            scanf("%d", &gameState->board.bombs[j]);
        }
    }

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    for (int i = 0; i < gameState->board.pathLength; i += MULTIPLES) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLES);
        for (int j = i; j < i + MULTIPLES && j < gameState->board.pathLength; j++) {
            scanf("%d", &gameState->board.treasures[j]);
        }
    }
}

void setupGameSettings(struct GameState* gameState) {
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gameState->board.maxMoves);
        // Clear the input buffer to handle extra characters
        while (getchar() != '\n');
    } while (gameState->board.maxMoves < gameState->player.lives || gameState->board.maxMoves >(int)(gameState->board.pathLength * 0.75));
}

void displayGameBoard(const struct GameState* gameState) {
    printf("Game Board:\n");
    for (int i = 0; i < gameState->board.pathLength; i++) {
        if (i == gameState->currentPosition) {
            printf("%c", gameState->player.symbol);
        }
        else if (gameState->player.history[i] == 1) {
            if (gameState->board.bombs[i] == 1 && gameState->board.treasures[i] == 1) {
                printf("&");
            }
            else if (gameState->board.bombs[i] == 1) {
                printf("!");
            }
            else if (gameState->board.treasures[i] == 1) {
                printf("$");
            }
            else {
                printf(".");
            }
        }
        else {
            printf("-");
        }
    }
    printf("\n");
}

void playGame(struct GameState* gameState) {
    int move;
    // Main game loop
    while (gameState->player.lives > 0 && gameState->board.maxMoves > 0) {
        // Display game board
        displayGameBoard(gameState);

        // Prompt for the next move
        printf("Next Move [1-%d]: ", gameState->board.pathLength);
        scanf("%d", &move);
        move--; // Adjust for 0-based index
        // Clear the input buffer to handle extra characters
        while (getchar() != '\n');

        if (move < 0 || move >= gameState->board.pathLength) {
            printf("Invalid move!\n");
            continue;
        }

        if (gameState->player.history[move] == 1) {
            printf("You've already been here!\n");
            continue;
        }

        gameState->currentPosition = move;
        gameState->player.history[move] = 1;
        gameState->board.maxMoves--;

        if (gameState->board.bombs[move] == 1 && gameState->board.treasures[move] == 1) {
            gameState->player.lives--;
            gameState->player.treasuresCollected++;
            printf("Boom! But there's a treasure!\n");
        }
        else if (gameState->board.bombs[move] == 1) {
            gameState->player.lives--;
            printf("Boom! You hit a bomb!\n");
        }
        else if (gameState->board.treasures[move] == 1) {
            gameState->player.treasuresCollected++;
            printf("Hurray! You found a treasure!\n");
        }
        else {
            printf("Nothing here...\n");
        }

        // Game over conditions
        if (gameState->player.lives <= 0) {
            printf("You've run out of lives!\n");
            break;
        }

        if (gameState->board.maxMoves <= 0) {
            printf("You've run out of moves!\n");
            break;
        }
    }
}
