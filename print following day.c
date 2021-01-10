// Created by Mert Kahraman.
//Write enumerated types that supports dates—such as december 12. Then add a function that produces a next day.
//So nextday(date) of december 12 is december 13. Also write a function printdate(date) that prints a date legibly.
//The function can assume that February has 28 days and it most know how many days are in each month.
//Use a struct with two members; one is the month and the second  is the day of the month—an int (or short).
//Then print out  the date January 1  and print  the next day Jan 2.
//Do this for the following dates:  February 28, March 14, October 31, and  December 31.

#include <stdio.h>
typedef enum month { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec } month;
typedef struct date { month m; int d; } date;
void nextday(date* ptrToDate);
void printDate(date prtDate);       //Declerations of my functions.
void setDate(int m, int d, date* ptrToDate);

int main()
{
	int i, dateData[5][2] =        //Instructor given date data. 5 rows for dates and 2 columns for month and day.
	{ {0,1},
		{1,28},
		{2,14},
		{9,31},
		{11,31} };

	date date;
	for (i = 0; i < 5; i++)		//With this loop I intended to print the original date and the next date in the following line.
	{
	setDate(dateData[i][0], dateData[i][1], & date);   //date's members are given here.
	printDate(date);    //Prints original date
	nextday(&date);     //Calculates next day
	printDate(date);    //Prints next date
	}
	return 0;
}

void setDate(int m, int d, date* ptrToDate)   //With this function we are declaring what is going to be given to members
{
	ptrToDate->d = d;
	ptrToDate->m = m;
}

void nextday(date *ptrToDate)    //Calculating next day here.
{
	if ((ptrToDate->d) >= 28)    //February 28 is a special case (except one in four years Feb 29). If the date is less than 28, we don't need to check if its going to jump next month or not.
	{
		switch (ptrToDate->m)
		{
		case 0:	case 2:	case 4:case 6: case 7: case 9:  //The are the months which includes 31-days
 			if ((ptrToDate->d + 1) % 31 == 1)    //If (date + 1) % 31 is 1 that means we jumped to the next month so a month++ here;
			{
				ptrToDate->d = 1;
				ptrToDate->m++;
			}
			else
			{
				ptrToDate->d = ++ptrToDate->d % 31;
			}

			break;
		case 11:
			if ((ptrToDate->d + 1) % 31 == 1)
			{
				ptrToDate->d = 1;
				ptrToDate->m = 0;
			}
			else
			{
				ptrToDate->d = ++ptrToDate->d % 31;
			}
			break;
		case 1: //Here is February
			ptrToDate->d = 1;
			ptrToDate->m++;
			break;
		default:
			if ((ptrToDate->d + 1) % 30 == 1)
			{
				ptrToDate->d = 1;
				ptrToDate->m++;
			}
			else
			{
				ptrToDate->d = ++ptrToDate->d % 30;
			}
			break;
		}
	}
	else  //If its less then 28, program jumps directly here 
	{
		ptrToDate->d++;
	}
}

void printDate(date prtDate)
{
	switch (prtDate.m) //Each integer between 0-11 has a value. 0 is Jan, 11 is Dec. Used switch for printing the date.
	{
	case 0:
		printf("The date is January %d\n", prtDate.d);
		break;
	case 1:
		printf("The date is February %d\n", prtDate.d);
		break;
	case 2:
		printf("The date is March %d\n", prtDate.d);
		break;
	case 3:
		printf("The date is April %d\n", prtDate.d);
		break;
	case 4:
		printf("The date is May %d\n", prtDate.d);
		break;
	case 5:
		printf("The date is June %d\n", prtDate.d);
		break;
	case 6:
		printf("The date is July %d\n", prtDate.d);
		break;
	case 7:
		printf("The date is August %d\n", prtDate.d);
		break;
	case 8:
		printf("The date is September %d\n", prtDate.d);
		break;
	case 9:
		printf("The date is October %d\n", prtDate.d);
		break;
	case 10:
		printf("The date is November %d\n", prtDate.d);
		break;
	case 11:
		printf("The date is December %d\n", prtDate.d);
		break;
	}
}
