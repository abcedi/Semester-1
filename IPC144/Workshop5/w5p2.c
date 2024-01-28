/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012  
#define MAX_YEAR 2022  
#define LOG_DAYS 3  

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year, month;
    int i;

    printf("General Well-being Log\n");
    printf("======================\n");

    while (1)
    {
        i = 1;

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            i = 0;
        }

        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
            i = 0;
        }

        if (i)
        {
            break;
        }
    }

    printf("\n*** Log date set! ***\n");

    double mRating, eRating;
    double mTotal = 0.0, eTotal = 0.0;

    int day;

    for (day = 1; day <= LOG_DAYS; day++)
    {
        printf("\n%d-", year);

        switch (month)
        {
        case 1:
            printf("JAN");
            break;
        case 2:
            printf("FEB");
            break;
        case 3:
            printf("MAR");
            break;
        case 4:
            printf("APR");
            break;
        case 5:
            printf("MAY");
            break;
        case 6:
            printf("JUN");
            break;
        case 7:
            printf("JUL");
            break;
        case 8:
            printf("AUG");
            break;
        case 9:
            printf("SEP");
            break;
        case 10:
            printf("OCT");
            break;
        case 11:
            printf("NOV");
            break;
        case 12:
            printf("DEC");
            break;
        }

        printf("-%02d\n", day);

        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &mRating);

            if (mRating < 0.0 || mRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }
        while (mRating < 0.0 || mRating > 5.0);

        mTotal += mRating;

        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eRating);

            if (eRating < 0.0 || eRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }
        while (eRating < 0.0 || eRating > 5.0);

        eTotal += eRating;
    }

    double overall_total = mTotal + eTotal;

    printf("\nSummary\n");
    printf("=======\n");

    printf("Morning total rating: %6.3lf\n", mTotal);
    printf("Evening total rating: %6.3lf\n", eTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", overall_total);

    printf("Average morning rating: %4.1lf\n", mTotal / LOG_DAYS);
    printf("Average evening rating: %4.1lf\n", eTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", overall_total / (LOG_DAYS * 2));

    return 0;

}



