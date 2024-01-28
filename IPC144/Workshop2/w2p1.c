//***************************************************************************** 
//Workshop - #2 (Part - 1) 
//Full Name : Abcedi Ilacas 
//Student ID# : 138180211 
//Email : ailacas1@myseneca.ca 
//Section : NBB 
//Authenticity Declaration : 
//I declare this submission is the result of my own work and has not been 
//shared with any other student or 3rd party content provider.This submitted 
//piece of work is entirely of my own creation. 
//***************************************************************************** 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main(void)

{
	printf("Set Shirt Prices\n");
	printf("================\n");

	float temp;

	int smallshirt;
	printf("Enter the price for a SMALL shirt: ");
	scanf("%f", &temp);
	smallshirt = (int)(temp * 100 + 0.5);

	int mediumshirt;
	printf("Enter the price for a MEDIUM shirt: ");
	scanf("%f", &temp);
	mediumshirt = (int)(temp * 100 + 0.5);

	int largeshirt;
	printf("Enter the price for a LARGE shirt: ");
	scanf("%f", &temp);
	largeshirt = (int)(temp * 100 + 0.5);

	printf("\n\nShirt Store Price List\n");
	printf("======================\n");

	printf("SMALL : $%.2f\n", smallshirt / 100.0);
	printf("MEDIUM : $%.2f\n", mediumshirt / 100.0);
	printf("LARGE : $%.2f\n", largeshirt / 100.0);

	printf("\nPatty's shirt size is 'S'\n");
	
	int quantity;
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &quantity);

	printf("\n\nPatty's shopping cart...\n");
	printf("Contains : %d shirts\n", quantity);

	const int tax = 13;
	int subtotal = smallshirt * quantity;
	int taxes = (subtotal * tax + 50) / 100;
	int total = subtotal + taxes;

	printf("Sub-total: $%.4f\n", subtotal /100.0);
	printf("Taxes: $%.4f\n", taxes / 100.0);
	printf("Total: $%.4f\n", total / 100.0);

	return 0;

}
