#include <stdio.h>

int main()
{
	float height;
	printf("Please Enter Your Height: ");
	scanf("%f", &height);

	float weight;
	printf("Please Enter Your Weight: ");
	scanf("%f", &weight);

	float bmi = weight / 703;
	printf("Your BMI is: %.2f", bmi);

	return 0;

}