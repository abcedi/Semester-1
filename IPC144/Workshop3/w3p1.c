//*****************************************************************************
//Workshop - #3 (Part - 1)
//Full Name : Abcedi Ilacas
//Student ID# : 138180211
//Email : ailacas1@myseneca.ca
//Section : NBB
//Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//*****************************************************************************

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	const double testValue = 330.99;
	const int product1_id = 111;
	const int product2_id = 222;
	const int product3_id = 111;
	const float product1_price = 111.49;
	const float product2_price = 222.99;
	const float product3_price = 334.49;
	const char product1_taxed = 'Y';
	const char product2_taxed = 'N';
	const char product3_taxed = 'N';
	float avgprice = (product1_price + product2_price + product3_price) / 3; 

	printf("Product Information\n");
	printf("===================\n");

	printf("Product-1 (ID:%i)\n", product1_id);
	printf("  Taxed: %c\n", product1_taxed);
	printf("  Price: $%.4f\n\n", product1_price);

	printf("Product-2 (ID:%i)\n", product2_id);
	printf("  Taxed: %c\n", product2_taxed);
	printf("  Price: $%.4f\n\n", product2_price);

	printf("Product-3 (ID:%i)\n", product3_id);
	printf("  Taxed: %c\n", product3_taxed);
	printf("  Price: $%.4f\n\n", product3_price);

	printf("The average of all prices is: $%.4f\n\n", avgprice);

	printf("About Relational and Logical Expressions!\n");
	printf("========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("2. FALSE: is always represented by integer value 0\n");
	printf("3. TRUE : is represented by any integer value other than 0\n\n");

	printf("Some Data Analysis...\n");
	printf("=====================\n");

	printf("1. Is product 1 taxable? -> %i\n\n", product1_taxed == 'Y');

	printf("2. Are products 2 and 3 both NOT taxable (N)? -> %i\n\n", (product2_taxed == 'N') && (product3_taxed == 'N'));

	printf("3. Is product 3 less than testValue ($%.2f)? -> %i\n\n", testValue, product3_price < testValue);

	printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %i\n\n", product3_price > (product1_price + product2_price));

	printf("5. Is the price of product 1 equal to or more than the price difference\n");
	printf("   of product 3 LESS product 2? ->  %i (price difference: $%.2f)\n\n", product1_price >= (product3_price - product2_price), product3_price - product2_price);

	printf("6. Is the price of product 2 equal to or more than the average price? -> %i\n\n", product2_price >= avgprice);

	printf("7. Based on product ID, product 1 is unique -> %i\n\n", (product1_id != product2_id) && (product1_id != product3_id));

	printf("8. Based on product ID, product 2 is unique -> %i\n\n", (product2_id != product1_id) && (product2_id != product3_id));

	printf("9. Based on product ID, product 3 is unique -> %i\n\n", (product3_id != product1_id) && (product3_id != product2_id));

	return 0;



}