// White Box testing - Murphy's Law Tic-Tack-Toe 

#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 11
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Grid for playing board
   1 2 3
   4 5 6
   7 8 9
*/
char tttBoard[] = "0123456789"; // Tic Tack Toe board. 0 is not used.

void play(char* tttBoard, char player); // player takes a turn
void printBoard(char* tttBoard);		// result of play

int main() {

	printf("*** White Box testing ***\nMurphy's Law Tic-Tack-Toe\t(Ctrl-C to end program)\n\n\tPlaying Grid:  Enter number to mark X|O\n");
	printBoard(tttBoard);

	while (true) { // play continues until a player has won the game
		play(tttBoard, 'X'); // X takes a turn
		play(tttBoard, 'O'); // O takes a turn
	}
}
/*
* print out contents of playing board
*/
void printBoard(char* tttBoard) {
	for (size_t i = 1; i < 9; i += 3)
	{
		printf("\t%c %c %c\n", tttBoard[i], tttBoard[i + 1], tttBoard[i + 2]);
	}
}
/*
* player takes a turn
*/
void play(char* tttBoard, char player) {
	int gridPosition;
	printf("\nPlayer\n%c > ", player);
	if (scanf("%d", &gridPosition))
	{ // a number was successfully read from the stdin buffer
		if (gridPosition >= 1 && gridPosition <= 9)
		{ // entered grid position is within range
			tttBoard[gridPosition] = player; // update grid with player's mark
		}
		else
		{ // diagnostic message
			printf("Instead of %d, use grid position 1 - 9\n",gridPosition);
		}
	}
	else
	{   // scanf did not find a number!
		scanf("%*[^\n]%*c"); // purge the buffer to prevent scanf from infinitely looping
		// diagnostic message
		printf("Please enter a numeric value between 1 and 9.\n");
	}
	printBoard(tttBoard);

	// check if Row is a winner with all same player mark
	for (size_t i = 1; i < 9; i += 3)
	{
		if (tttBoard[i] == tttBoard[i + 1] && tttBoard[i + 1] == tttBoard[i + 2])
		{
			printf("%c is ROW %zd-%zd-%zd WINNER!\n", tttBoard[i], i, i + 1, i + 2);
		}
	}
	// check if Column is a winner with all same player mark
	for (size_t i = 1; i <= 3; i++)
	{
		if (tttBoard[i] == tttBoard[i + 3] && tttBoard[i + 3] == tttBoard[i + 6])
		{
			printf("%c is COLUMN %zd-%zd-%zd WINNER!\n", tttBoard[i], i, i + 3, i + 6);
		}
	}
	// check if Diagonal is a winner with all same player mark
	if (tttBoard[1] == tttBoard[5] && tttBoard[5] == tttBoard[9])
	{
		printf("%c is DIAGONAL 1-5-9 WINNER!\n", tttBoard[1]);
	}
	// check if Diagon Ally is a winner with all same player mark
	if (tttBoard[3] == tttBoard[5] && tttBoard[5] == tttBoard[7])
	{
		printf("%c is DIAGONAL 3-5-7 WINNER!\n", tttBoard[3]);
	}

	// check for game winner: all grid positionn have same player mark
	for (size_t i = 2; i <= 9; i++)
	{
		if (tttBoard[1] != tttBoard[i])
		{
			return; // end function
		}
	}
	printf("%c is GAME WINNER!\n", tttBoard[1]);
	exit(0); // end of game
}
