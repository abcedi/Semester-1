/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Abcedi Ilacas
Student ID#: 138180211
Email      : ailacas1@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef CORE_H
#define CORE_H
// Function prototypes
// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);
// Input integer function
int inputInt(void);
// Input a positive integer function
int inputIntPositive(void);
// Input integer within a range function
int inputIntRange(int low, int high);
// Input a character from a set of options function
char inputCharOption(const char* validChars);
// Input C string function
void inputCString(char* str, int min, int max);
// Display formatted phone number function
void displayFormattedPhone(const char* phone);

#endif