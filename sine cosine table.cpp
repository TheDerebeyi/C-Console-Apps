// This program should produce a table that sine and cosine values of [0,1]. Created by Mert Kahraman.
#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{
	int i;
	float interval;

	printf("Value :  ");

	for (i = 0; i < 11; i++)     //I wanted the show values first so in the first row I aligned which value I took.
	{
		interval = i / 10.0;     //To get floats such 0.1 I made this which showed in the courses of Ira Pohl.
		printf("%.3f ", interval);  // This for loop should align all the values I take on a single row
	}

	printf("\nSine  :  ");

	for (i = 0; i < 11; i++)
	{
		interval = i / 10.0;
		printf("%.3f ", sin(interval)); //Using for loop I aligned sine values of the floats I choose
	}

	printf("\nCosine:  ");

	for (i = 0; i < 11; i++)
	{
		interval = i / 10.0;      //Made the same thing for cosine as well
		printf("%.3f ", cos(interval));
	}

	return 0;
}
