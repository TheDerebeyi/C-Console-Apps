// Created by Mert Kahraman. September 18, 2020.
//Compute the average weight for a population of elephant seals read into an array. Use "elephant weigt data.txt" for data.

#include <stdio.h>

int main() {
	FILE* file;
	int i, sum = 0;
	double average;
	int weightData[1000];    // I needed an array to store weight data
	file = fopen("elephant seal data.txt", "r"); //Saved the dataset as elephant seal data.txt and opened here with openf() function.
	for (i = 0; i < 1000; i++)
	{
		fscanf(file, "%d 	", &weightData[i]);  //Scaned and assigned every invidual element into an array index 
	}

	fclose(file);    //closed to file to restore memory

	for (i = 0; i < 1000; i++)   //I used an itreation for sum calculation.
	{
		sum += weightData[i];
	}

	average = sum / 1000.0;     //I used 1000.0 because I needed double division.

	printf("Average weight of 1000 elephants is %lf", average); //Printed the average.
	return(0);
}
