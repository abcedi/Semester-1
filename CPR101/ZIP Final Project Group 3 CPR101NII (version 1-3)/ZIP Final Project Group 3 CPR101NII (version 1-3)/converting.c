// CONVERTING MODULE SOURCE
#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 80
#include "converting.h"

/*
Author: Lena Park, 
email: lpark9@myseneca.ca
ID: 127390235 
Date written: 2023.12.08
Course:CPR101
Project:Final
[executable filename]: converting.c
[title of program]: converting
Purpose: It is a function that converts a string of integers into ASCII integer variables.
*/

/* Version 1 */
void converting(void)
{
	printf("*** Start of Converting Strings to int Demo ***\n"); // prints text
	char intString[BUFFER_SIZE]; // collects input in the variable until 80 characters
	int intNumber; // to store the converted integer

	do 
	{
		printf("Type an int numeric string (q - to quit) :\n"); // prompts user to enter input or quit
		fgets(intString, BUFFER_SIZE, stdin); // read the user's input and store it in intString array. It reads up to BUFFER_SIZE - 1 (null terminator)
		
		intString[strlen(intString) - 1] = '\0'; // removes the null terminitor
		
		if (strcmp(intString, "q") != 0) // compares input and checks if user quits or else it converts the string of integers into ASCII - integer
		{
			intNumber = atoi(intString); // atio function is the converter
			printf("Converted number is %d\n", intNumber); // prints the result
		}
	} while (strcmp(intString, "q") != 0); // loops until user enters 'q'
	
	printf("*** End of Converting Strings to int Demo ***\n\n"); // ending message

	/* Version 2 */
	printf("*** Start of Converting Strings to double Demo ***\n");

	char doubleString[BUFFER_SIZE]; // Declares an array 'doubleString' double to store the input string. Collects input in the variable until 80 characters
	double doubleNumber; // To store the converted double numeric value.

	do 
	{
		printf("Type the double numeric string (q - to quit) :\n");
		
		fgets(doubleString, BUFFER_SIZE, stdin); // Uses the fget to read the input from user (stdin) and stores it to doubleString
		doubleString[strlen(doubleString) - 1] = '\0'; // Removes the newline character at the end of the string by setting it to '\0'.
		fflush(stdin);

		if ((strcmp(doubleString, "q") != 0)) // Checks if user didn't press "q"
		{
			doubleNumber = atof(doubleString); // It converts the string to a double using atof (ASCII to float) function and stores the result in doubleNumber.
			printf("Converted number is %f\n", doubleNumber); // prints the result in doubleNumber
		}

	} while (strcmp(doubleString, "q") != 0);; // Continues loop until "q" is pressed
	
	printf("*** End of Converting Strings to double Demo ***\n\n"); 
	

	/* Version 3 */

	printf("*** Start of Converting Strings to long Demo ***\n");
	char longString[BUFFER_SIZE]; // Declare an array doubleString of type double store the input string.
	long longNumber; // A variable doubleNumber of type double to store the converted numeric value.

	do
	{
		printf("Type the long numeric string (q - to quit) :\n");

		fgets(longString, BUFFER_SIZE, stdin); // Uses the fget to read the input from user (stdin) and stores it to longNumber
		longString[strlen(longString) - 1] = '\0'; // Removes the newline character at the end of the string by setting it to '\0'

		if ((strcmp(longString, "q") != 0)) // Checks if user didn't press "q"
		{
			longNumber = atoi(longString); // Converts the string to a long using atoi (ASCII to integer) function and stores the result in longNumber.
			printf("Converted number is %ld\n", longNumber); // Prints the converted long value.
		}
	} while (strcmp(longString, "q") != 0); // Continues loop until "q" is pressed

	printf("*** End of Converting Strings to long Demo ***\n\n");
	
}

