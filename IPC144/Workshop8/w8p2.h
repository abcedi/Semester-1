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

// ----------------------------------------------------------------------------
// defines/macros
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maxProducts 3
#define numOfGrams 64
#define LBS_TO_KG_CONVERSION 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int sku;
	double price;
	int calories;
	double weight;
};

struct ReportData
{
	int sku;
	double price;
	int calories;
	double weightLbs;
	double weightKg;
	int weightG;
	double servings;
	double costPerServing;
	double costPerCalorie;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* positiveNum);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* positiveNum);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProduct);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceDetails);

// 5. Display the formatted table header
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight);

// 6. Display a formatted record of cat food data
void displayCatFoodHeader(void);
// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(int weightInGrams, int servingSize, double* result);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* servings, double* result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const int* calories, const double* servings, double* result);

// 14. Derive a reporting detail record based on the cat food product data
void calculateReportData(struct ReportData* report, struct CatFoodInfo catFood);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData* report, int isCheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct ReportData reports[], int size);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);
