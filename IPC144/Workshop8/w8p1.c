/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : Abcedi Ilacas
Student ID#: 138180211
Email      : ailacas1@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// System Libraries
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num)
{
	int positiveNum;
	do
	{
		scanf("%d%*c", &positiveNum);

		if (positiveNum <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}
	while (positiveNum <= 0);

	if (num != NULL)
	{
		*num = positiveNum;
	}

	return positiveNum;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num)
{
	double positiveNum;
	do
	{
		scanf("%lf%*c", &positiveNum);

		if (positiveNum <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}
	while (positiveNum <= 0);

	if (num != NULL)
	{
		*num = positiveNum;
	}

	return positiveNum;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numOfProducts);
	printf("NOTE: A 'serving' is %dg\n\n", numOfGrams);

	return;
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceDetails)
{
	struct CatFoodInfo catFood;

	printf("Cat Food Product #%d\n", sequenceDetails);
	printf("--------------------\n");

	printf("SKU           : ");
	getIntPositive(&catFood.sku);

	printf("PRICE         : $");
	getDoublePositive(&catFood.price);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&catFood.weight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&catFood.calories);

	return catFood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");

	return;
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);

	return;
}

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFood[maxProducts] = { {0} };

	int i;
	openingMessage(maxProducts);

	for (i = 0; i < maxProducts; i++)
	{
		catFood[i] = getCatFoodInfo(i + 1);
		printf("\n");
	}
	displayCatFoodHeader();

	for (i = 0; i < maxProducts; i++)
	{
		displayCatFoodData(catFood[i].sku, &catFood[i].price, catFood[i].calories, &catFood[i].weight);
	}

	return;
}