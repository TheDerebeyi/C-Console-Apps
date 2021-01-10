//Created by Mert Kahraman

//Generates 100 random numbers, sorts them and prints to the console. ,

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

typedef struct list { int data; struct list* next; } list;

list* createList(int d) //Program creates a member to the list here.

{ list* head = malloc((sizeof(list))); //Malloc is to allocate the size of "list".

head->data = d; head->next = NULL; return head; }

list* addToFront(int d, list* h) //Program uses this method to add a member to the front

{ list* head = createList(d); head->next = h; return head; }

list* arrayToList(int d[], int size) //Generating a array to list.

{ list* head = createList((d[0]));

int i;

for (i = 1; i < size; i++) { head = addToFront(d[i], head); }

return head; }

void printList(list* h, char*title) //Prints list with 20 member in each row.

{ printf("%s\n", title); for (int i = 1;h != NULL;i++) { printf("%u ", h->data); if ((i % 20) == 0) printf("\n"); h = h->next; } }

list* bubbleSortList(list* s, int size)

{ list* h = s; //Using "h" as a cache to store head of the list.

int temp;

for (int i = 1; i < size; i++) //Program must run this code for n-1 times to sort correctly.

{

while (s->next != NULL)

{
if (s->data > s->next->data) //If first value is bigger than second it will swap them.

{ temp = s->next->data;

s->next->data = s->data;

s->data = temp;

} s = s->next; //Jumps to the next member.

} s = h; //At the end, program jumps to the head again. To run sorting again or returning the head.

}

return s; }

int main()

{ time_t t;

srand((unsigned)time(&t));

list* head = NULL; int data[100];

for (int i=0; i <100; i++) { data[i] = rand(); }

head = arrayToList(data, 100);

printList(head, "100 unsorted random generated number"); //To check its shorted. These are the random unsorted numbers.

printf("\n\n");

head = bubbleSortList(head, 100);

printList(head, "100 sorted random generated number"); //Prints sorted numbers.

printf("\n\n");

return 0; }