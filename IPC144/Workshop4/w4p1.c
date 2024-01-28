/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main()
{
    char loop;
    int iteration;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loop, &iteration);

        switch (loop)
        {
        case 'D':
            if (iteration < 3 || iteration > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            else
            {
                printf("DO-WHILE: ");
                int i = 0;
                do
                {
                    printf("D");
                    i++;
                } 
                while (i < iteration);
                printf("\n\n");
            }
            break;

        case 'W':
            if (iteration < 3 || iteration > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            else
            {
                printf("WHILE   : ");
                int i = 0;
                while (i < iteration)
                {
                    printf("W");
                    i++;
                }
                printf("\n\n");
            }
            break;

        case 'F':
            if (iteration < 3 || iteration > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            else
            {
                int i = 0;
                printf("FOR     : ");
                for (i = 0; i < iteration; i++)
                {
                    printf("F");
                }
                printf("\n\n");
            }
            break;

        case 'Q':
            if (iteration != 0) 
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            }
            break;

        default:
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
    } 
    while (!(loop == 'Q' && iteration == 0));

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;

}