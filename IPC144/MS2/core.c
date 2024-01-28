/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <string.h>
//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//
#include "core.h"

// Clear the standard input buffer
void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!
	}
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}

// Input integer function
int inputInt(void)
{
	int value, scanfResult;
	int isValidInput = 0;
	char newLine;

	while (!isValidInput)
	{
		scanfResult = scanf("%d%c", &value, &newLine);

		if (scanfResult == 2 && newLine == '\n')
		{
			isValidInput = 1;
		}
		else
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	}
	return value;
}

// Input a positive integer function
int inputIntPositive(void)
{
	int value;
	do
	{
		value = inputInt();
		if (value <= 0)
		{
			printf("ERROR! Value must be > 0: ");
		}
	} while (value <= 0);
	return value;
}

// Input integer within a range function
int inputIntRange(int low, int high)
{
	int rangeInput;

	do
	{
		rangeInput = inputInt();

		if (!(rangeInput > low || rangeInput < high))
		{
			printf("ERROR! Value must be between %d and %d inclusive: ", low, high);
		}

	} while (!(rangeInput > low || rangeInput < high));

	return rangeInput;
}

// Input a character from a set of options function
char inputCharOption(const char* validChars)
{
	char value;
	int flag = 0;

	do
	{
		scanf(" %c", &value);
		clearInputBuffer();

		const char* chars = validChars;
		flag = 0;

		while (*chars != '\0' && flag == 0)
		{
			if (value == *chars)
			{
				flag = 1;
			}
			chars++;
		}
		if (flag == 0)
		{
			printf("ERROR: Character must be one of [%s]: ", validChars);
		}
	} while (flag == 0);

	return value;
}

// Input C string function
void inputCString(char* str, int min, int max)
{
	int lengthCount;
	char temp[100];

	do
	{
		scanf("%99[^\n]%*c", temp);
		lengthCount = strlen(temp);

		if (lengthCount >= max || lengthCount <= min)
		{
			if (max == min && lengthCount != max)
			{
				printf("ERROR: String length must be exactly %d chars: ", max);
			}
			else if (max != min && lengthCount > max)
			{
				printf("ERROR: String length must be no more than %d chars: ", max);
			}
			else if (lengthCount > max || lengthCount < min)
			{
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
			}
		}
	} while (lengthCount > max || lengthCount < min);

	strncpy(str, temp, max);
	str[max] = '\0';

	return;
}

// Display formatted phone number function
void displayFormattedPhone(const char* phone)
{
	int i;

	if (phone == NULL || strlen(phone) != 10)
	{
		printf("(___)___-____");
		return;
	}
	
	for (i = 0; i < 10; i++) {
		if (phone[i] < '0' || phone[i] > '9')
		{
			printf("(___)___-____");
			return;
		}
	}

	printf("(%c%c%c)%c%c%c-%c%c%c%c", phone[0], phone[1], phone[2], phone[3], phone[4], phone[5], phone[6], phone[7], phone[8], phone[9]);
}

