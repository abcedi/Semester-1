/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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
#include "w8p2.h"

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
	} while (positiveNum <= 0);

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
	} while (positiveNum <= 0);

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg)
{
	double result = 0;
	if (lbs != NULL)
	{
		result = *lbs / LBS_TO_KG_CONVERSION;
		if (kg != NULL)
		{
			*kg = result;
		}
	}
	return result;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* g)
{
	int result = 0;
	if (lbs != NULL)
	{
		result = (int)(*lbs / LBS_TO_KG_CONVERSION * 1000);
		if (g != NULL)
		{
			*g = result;
		}
	}
	return result;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kg, int* g) {
	if (lbs != NULL)
	{
		if (kg != NULL)
		{
			*kg = *lbs / LBS_TO_KG_CONVERSION;
		}
		if (g != NULL)
		{
			*g = (int)(*lbs / LBS_TO_KG_CONVERSION * 1000);
		}
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(int servingSize, int totalGrams, double* result)
{
	double calcResult = (double)totalGrams / servingSize;
	if (result != NULL)
	{
		*result = calcResult;
	}
	return calcResult;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* servings, double* result)
{
	double calcResult = 0;
	if (price != NULL && servings != NULL && *servings > 0)
	{
		calcResult = *price / *servings;
		if (result != NULL)
		{
			*result = calcResult;
		}
	}
	return calcResult;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const int* calories, const double* servings, double* result)
{
	double calcResult = 0;
	if (price != NULL && calories != NULL && servings != NULL && *calories > 0 && *servings > 0)
	{
		calcResult = *price / (*calories * *servings);
		if (result != NULL)
		{
			*result = calcResult;
		}
	}
	return calcResult;
}

// 14. Derive a reporting detail record based on the cat food product data
void calculateReportData(struct ReportData* report, struct CatFoodInfo catFood)
{
	report->sku = catFood.sku;
	report->price = catFood.price;
	report->calories = catFood.calories;
	report->weightLbs = catFood.weight;

	convertLbsKg(&(catFood.weight), &(report->weightKg));
	convertLbsG(&(catFood.weight), &(report->weightG));

	report->servings = calculateServings(numOfGrams, report->weightG, &(report->servings));
	report->costPerServing = calculateCostPerServing(&(report->price), &(report->servings), &(report->costPerServing));
	report->costPerCalorie = calculateCostPerCal(&(report->price), &(report->calories), &(report->servings), &(report->costPerCalorie));
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", numOfGrams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData* report, int isCheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report->sku, report->price, report->weightLbs, report->weightKg, report->weightG, report->calories, report->servings, report->costPerServing, report->costPerCalorie);

	if (isCheapest)
	{
		printf(" ***");
	}
	printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct ReportData reports[], int size)
{
	int i, cheapestIndex = 0;
	for (i = 1; i < size; i++)
	{
		if (reports[i].costPerCalorie < reports[cheapestIndex].costPerCalorie)
		{
			cheapestIndex = i;
		}
	}
	for (i = 0; i < size; i++)
	{
		displayReportData(&reports[i], i == cheapestIndex);
	}

	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf", reports[cheapestIndex].sku, reports[cheapestIndex].price);

	printf("\n\nHappy shopping!\n");
}

// ----------------------------------------------------------------------------
// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFood[maxProducts];
	struct ReportData reports[maxProducts];

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

	displayReportHeader();

	for (i = 0; i < maxProducts; i++)
	{
		calculateReportData(&reports[i], catFood[i]);
	}

	displayFinalAnalysis(reports, maxProducts);

	return;
}