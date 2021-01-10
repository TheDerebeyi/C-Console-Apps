//Created by Mert Kahraman

#include <stdio.h>

#include <stdlib.h>

void print_file(FILE* fptr) //Prints a file into screen.

{ int c; rewind(fptr); while ((c = getc(fptr)) != EOF) putc(c, stdout); }

void data_to_array(FILE* ifp, int data[],int size) //Reads data into an array.

{
int c;

rewind(ifp);

for(int i = 0; i <= size + 1; i++) //i <= size because first element of the data shows the size. It isn't included to data.

{ fscanf(ifp, "%d", &c); data[i] = c; }

}

int max_calculator(int data[], int size) //Calculates the maximum value of an array.

{ int temp = data[1]; //Temp is initialized as first value. If program catches a bigger value, temp assigns as it. At the end maximum number is being calculated by this way.

for(int i = 1; i<= size;i++)

{ if(data[i] > temp)

{ temp = data[i];

}

}

return temp;

}

double average_calculation(int data[], int size)

{
double sum = 0.0;

for(int i = 1; i <= size; i++)

{
sum += data[i]; //Sum is 0.0 at first. It adds every element each other. Starting by data[1] because data[0] is size of the list.

}

return (sum / size);

}

void write_to_output(FILE* ofp, int data[], int size)

{
double average = average_calculation(data,size);

int max = max_calculator(data, size);

fprintf(ofp, "Average is %.3f and maximum value is %d", average,max); //This writes the results into answer-hw3 file.

}

int main() {
FILE* ifp, * ofp;

int size;

ifp = fopen("data.txt", "r+");

fscanf(ifp, "%d", &size);

int data[100];

ofp = fopen("answer-hw3", "w+");

printf("my %s file as read is \n\n", "data.txt");

print_file(ifp); printf("\n\n");

data_to_array(ifp, data,size);

write_to_output(ofp, data, size);

print_file(ofp);

printf("\n\n");

fclose(ofp); //Closing the files.

fclose(ifp);

return 0; }