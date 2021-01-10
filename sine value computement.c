/* Created by Mert Kahraman
   A program that produces sine of a value between 0 and 1.
*/

#include<stdio.h>
#include <math.h>         // Included math.h to use sin() function

int main(void)
{
	float value, sine;
	printf("Please enter a value between 0 and 1: ");
	scanf_s("%f", &value);
	while (value >= 1 || value <= 0)       // Used while for check if its in limits
	{
		printf("\nYou entered a value outside of the limits. Please enter a value between 0 and 1 (non inclusive): ");
		scanf_s("%f", &value);
	}
	sine = sin(value);
	printf("\nSine of %f is %f", value, sine);
	return 0;
}
