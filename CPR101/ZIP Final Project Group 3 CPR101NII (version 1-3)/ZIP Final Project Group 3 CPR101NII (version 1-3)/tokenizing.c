#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "tokenizing.h"

#define BUFFER_SIZE 1000

// Tokenizing words/phases and sentense in a string by using specific characters to be delimiter //
void tokenizing()
{
	/* Version 1 */
	char words[BUFFER_SIZE];
	char* nextWord = NULL;
	int wordCounter;

	printf("*** Start of Tokenizing Word DEMO ***\n");
	do										  // Loop until the user types 'q' to quit
	{
		printf("Type a few words separated by space (q - to quit): \n");
		fgets(words, BUFFER_SIZE, stdin);     // Read the user input into the words array
		words[strlen(words) - 1] = '\0';      // Remove the newline character at the end of the string
		if (strcmp(words, "q") != 0)		  // If the user didn't type 'q' to quit
		{
			nextWord = strtok(words, " ");    // Tokenize the string into words separated by space
			wordCounter = 1;				  // Initialize the word counter

			while (nextWord)				  // Loop until there are no more words
			{
				printf("Word #%d is \'%s\'\n",
					wordCounter++, nextWord); // Print the current word
				nextWord = strtok(NULL, " "); // Get the next word
			}
		}
	} while (strcmp(words, "q") != 0);
	printf("*** End of Tokenizing words DEMO ***\n\n");

	/* Version 2 */
	char phrases[BUFFER_SIZE];
	char* nextPhrases = NULL;
	int phrasesCounter;

	printf("*** Start of Tokenizing Phrases DEMO ***\n");
	do										     // Loop until the user types 'q' to quit
	{
		printf("Type a few phrases separated by comma (q - to quit):\n");
		fgets(phrases, BUFFER_SIZE, stdin);	     // Read the user input into the phrases array
		phrases[strlen(phrases) - 1] = '\0';     // Remove the newline character at the end of the string
		if ((strcmp(phrases, "q") != 0))         // If the user didn't type 'q' to quit
		{
			// Tokenize the string into phrases separated by comma
			nextPhrases = strtok(phrases, ",");
			phrasesCounter = 1;				     // Initialize the phrase counter
			while (nextPhrases)				     // Loop until there are no more phrases
			{
				printf("Phrase #%d is \'%s\'\n", // Print the current phrase
					phrasesCounter++, nextPhrases);
				nextPhrases = strtok(NULL, ","); // Get the next phrase
			}
		}
	} while (strcmp(phrases, "q") != 0);	     // Continue the loop until the user types 'q' to quit
	printf("*** End of Tokenizing Phrases DEMO ***\n\n");

	/* Version 3 */
	char sentences[BUFFER_SIZE];
	char* nextSentence = NULL;
	int sentencesCounter;

	printf("*** Start of Tokenizing Sentences DEMO ***\n");
	do										      // Loop until the user types 'q' to quit
	{
		printf("Type a few sentences separated by dot (q - to quit);\n");
		fgets(sentences, BUFFER_SIZE, stdin);     // Read the user input into the sentence array
		sentences[strlen(sentences) - 1] = '\0';  // Remove the newline character at the end of the string
		if (strcmp(sentences, "q") != 0)		  // If the user didn't type 'q' to quit
		{
			// Tokenize the string into sentences separated by comma
			nextSentence = strtok(sentences, ".");
			sentencesCounter = 1;			      // Initialize the sentence counter
			while (nextSentence)				  // Loop until there are no more sentences
			{
				printf("Sentence #%d is \'%s\'\n",// Print the current sentence
					sentencesCounter++, nextSentence);
				nextSentence = strtok(NULL, "."); // Get the next sentence
			}
		}
	} while (strcmp(sentences, "q") != 0);        // Continue the loop until the user types 'q' to quit
	printf("*** End of Tokenizing Sentences DEMO ***\n\n");


}