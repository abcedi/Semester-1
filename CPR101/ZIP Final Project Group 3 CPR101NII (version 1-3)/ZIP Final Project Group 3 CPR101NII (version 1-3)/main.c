#define _CRT_SECURE_NO_WARNINGS
#include "fundamentals.h"
#include "manipulating.h"
#include "converting.h"
#include "tokenizing.h"


int main(void)
{
	char buff[10]; // stores input of user upto 10
	do {
		printf("-----------------------------\n");
		printf("Choose your desired function:\n");
		printf("-----------------------------\n");

		printf("1 - Fundamentals\n"); // prints text
		printf("2 - Manipulation\n");
		printf("3 - Converting\n");
		printf("4 - Tokenizing\n");
		printf("0 - Exit\n");
		printf("Which module to run? \n");

		fgets(buff, 10, stdin); // reads input and stores to buff

		switch (buff[0]) // will call the function depending on input
		{
		case '1': fundamentals();
			break;

		case '2': manipulating();
			break;

		case '3': converting();
			break;

		case '4': tokenizing();
			break;
		}

	} while (buff[0] != '0'); // input 0 to quit

	return 0;
}