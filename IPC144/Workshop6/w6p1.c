/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
    double netIncome;
    int numberOfItems;
    double itemCost[10];
    int itemPriority[10];
    char itemFinanceOptions[10];
    double totalCost = 0;
    int i;
    
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < 500)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (netIncome > 400000)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
    }
    while (netIncome < 500 || netIncome > 400000);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &numberOfItems);
        if (numberOfItems < 1 || numberOfItems > 10)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    }
    while (numberOfItems < 1 || numberOfItems > 10);
    
    for (i = 0; i < numberOfItems; i++)
    {
        printf("\nItem-%d Details:\n", i + 1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);
            if (itemCost[i] < 100.0)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        }
        while (itemCost[i] < 100.0);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i]);
            if (itemPriority[i] < 1 || itemPriority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }
        while (itemPriority[i] < 1 || itemPriority[i] > 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinanceOptions[i]);
            if (itemFinanceOptions[i] != 'y' && itemFinanceOptions[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        }
        while (itemFinanceOptions[i] != 'y' && itemFinanceOptions[i] != 'n');

        totalCost += itemCost[i];
    }

    printf("\nItem Priority Financed        Cost\n"); 
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numberOfItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, itemPriority[i], itemFinanceOptions[i], itemCost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}


