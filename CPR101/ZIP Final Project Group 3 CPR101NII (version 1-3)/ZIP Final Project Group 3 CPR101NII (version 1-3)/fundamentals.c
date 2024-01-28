// FUNDAMENTALS MODULE SOURCE

// Define preprocessor directives to suppress warnings
#define _CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE    80
#define NUM_INPUT_SIZE 10

#include "fundamentals.h"

// Function used for unit testsing to retrieve a character from a string at a specified position
char indexString(const char* buffer, size_t position) {
    // Check if the specified position is beyond the length of the string
    if (position >= strlen(buffer)) {
        // Adjust the position to the last index of the string
        position = strlen(buffer) - 1;
        printf("Error: Position Too Big\n");
    }
    // Return the character at the specified position
    return buffer[position];
}

// Main function for demonstrating the fundamentals of indexing strings
void fundamentals(void) {

    // Version 1 (V1) of the function

    printf("*** Start of Indexing Strings Demo ***\n");

    // Declare variables for input buffer, number input, and position
    char buffer1[BUFFER_SIZE];
    char numInput[NUM_INPUT_SIZE];
    size_t position;

    // (loop for user interaction)
    do {
        // Prompt the user to enter a string
        printf("Type not empty string (q - to quit):\n");
        // Read user input into the buffer
        fgets(buffer1, BUFFER_SIZE, stdin);
        // Remove the newline character at the end of the input
        buffer1[strlen(buffer1) - 1] = '\0';

        // Check if the user input is not 'q'
        if (strcmp(buffer1, "q") != 0) {
            // Prompt the user to input a position within the string
            printf("Type the character position within the string:\n");
            // Read user input for the position
            fgets(numInput, NUM_INPUT_SIZE, stdin);
            // Remove the newline character at the end of the input
            numInput[strlen(numInput) - 1] = '\0';
            // Convert the input into an integer that represents the position
            position = atoi(numInput);

            // Check if the position is beyond the length of the string
            if (position >= strlen(buffer1)) {
                // Adjust the position to the last index of the string
                position = strlen(buffer1) - 1;
                printf("Too big... Position reduced to max. available\n");
            }

            printf("The character found at %d position is \'%c\'\n", (int)position, buffer1[position]);
        }
    } while (strcmp(buffer1, "q") != 0);  // Continue the loop until the user inputs 'q'
    printf("*** End of Indexing Strings Demo ***\n\n");

    // V2
    printf("*** Start of Measuring Strings Demo ***\n");

    // Declare character array to store user input strings
    char buffer2[BUFFER_SIZE];

    // Loop to prompt the user for input
    do {
        // Prompt for user input
        printf("Type a string (q - to quit):\n");

        // Read user input and store it in the buffer
        fgets(buffer2, BUFFER_SIZE, stdin);

        // Remove the newline character at the end of the input
        buffer2[strlen(buffer2) - 1] = '\0';

        // Check if the entered string is not equal to "q"
        if (strcmp(buffer2, "q") != 0)
            printf("The length of \'%s\' is %d characters\n", buffer2, (int)strlen(buffer2));

        // Continue the loop if the entered string is not "q"
    } while (strcmp(buffer2, "q") != 0);

    printf("*** End of Measuring Strings Demo ***\n\n");

    // V3
    printf("*** Start of Copying Strings Demo ***\n");

    // Declare character arrays to store destination and source strings
    char destination[BUFFER_SIZE];
    char source[BUFFER_SIZE];

    // Start a loop to repeatedly perform string copying operations
    do {
        // Reset the destination string to an empty string
        destination[0] = '\0';
        printf("Destination string is reset to empty\n");

        // Prompt for user input (q - to quit)
        printf("Type the source string (q - to quit):\n");

        // Read user input and store it in the source buffer
        fgets(source, BUFFER_SIZE, stdin);

        // Remove the newline character at the end of the input
        source[strlen(source) - 1] = '\0';

        // Check if the entered source string is not equal to "q"
        if (strcmp(source, "q") != 0) {
            // Copy the contents of the source string to the destination string
            strcpy(destination, source);

            // Print the new destination string
            printf("New destination string is \'%s\'\n", destination);
        }

        // Continue the loop if the entered source string is not "q"
    } while (strcmp(source, "q") != 0);

    // Print a message to indicate the end of the program
    printf("*** End of Copying Strings Demo ***\n\n");


}
