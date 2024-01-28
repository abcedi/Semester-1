/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
    double itemCost[100];
    int itemPriority[100];
    char itemFinanceOptions[100];
    double totalCost = 0;
    int i;

    int hasFinance = 0;
    int menuChoice, priorityChoice;
    double monthlyIncome = 0;
    int priorityHasFinance = 0;

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

    monthlyIncome = netIncome;

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

        if (itemFinanceOptions[i] == 'y')
        {
            hasFinance = 1;
        }

        totalCost += itemCost[i];
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numberOfItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, itemPriority[i], itemFinanceOptions[i], itemCost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", totalCost);

    monthlyIncome = netIncome;

    do
    {
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &menuChoice);

        switch (menuChoice)
        {
        case 1:           
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalCost);
            int totalMonths = (totalCost / monthlyIncome);
            if ((totalCost / monthlyIncome) - totalMonths > 0)
            {
                totalMonths++;
            }
            printf("Forecast: %d years, %d months\n", totalMonths / 12, totalMonths % 12);
            if (hasFinance)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            break;

        case 2:
            do
            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &priorityChoice);
                if (priorityChoice < 1 || priorityChoice > 3)
                {
                    printf("ERROR: Invalid priority selection. Please enter a value between 1 to 3.\n");
                }
            }
            while (priorityChoice < 1 || priorityChoice > 3);

            double filteredTotalCost = 0;
            priorityHasFinance = 0;
            for (i = 0; i < numberOfItems; i++)
            {
                if (itemPriority[i] == priorityChoice)
                {
                    filteredTotalCost += itemCost[i];
                    if (itemFinanceOptions[i] == 'y' || itemFinanceOptions[i] == 'Y')
                    {
                        priorityHasFinance = 1;
                    }
                }
            }

            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", priorityChoice);
            printf("Amount:   $%1.2lf\n", filteredTotalCost);
            int filteredTotalMonths = (filteredTotalCost / monthlyIncome); 
            if ((filteredTotalCost / monthlyIncome) - filteredTotalMonths > 0)
            {
                filteredTotalMonths++;
            }
            printf("Forecast: %d years, %d months\n", filteredTotalMonths / 12, filteredTotalMonths % 12);
            if (priorityHasFinance)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            break;

        case 0:
            printf("\nBest of luck in all your future endeavours!\n");
            return 0;

        default:
            printf("\nERROR: Invalid menu selection.\n");
            break;
        }
        

    }
    while (menuChoice != 0);



    return 0;
}

    


