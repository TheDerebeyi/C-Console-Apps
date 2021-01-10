//Created by Mert Kahraman

//Modify the singly linked list to be a doubly linked list. Now write a routine that removes all duplicate data in the doubly linked list.
//The data will be integers generated at random from [0,49]. Initially have a list of 200 elements.  
//Now do this in one of two ways.  Sort the list by its data field. Remove adjacent elements of the sorted list with the same value.
//Or, take the first element—search the remainder of the list for elements with the same data and remove them.
//Then take the second element and do the same. Repeat until only one element is left.

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

typedef struct list { int data; struct list* next; struct list* previous; } list;

list* createList(int d) //Program creates a member to the list here.

{ list* head = malloc((sizeof(list))); //Malloc is to allocate the size of "list".

head->data = d;

head->next = NULL;

head->previous = NULL;

return head; }

list* addToFront(int d, list* h) //Program uses this method to add a member to the front

{ list* head = createList(d); head->next = h; return head; }

list* addToRear(int d, list* h) //Program uses this method to add a member to the front

{ list* head = createList(d); head->previous = h; return head; }

list* arrayToList(int d[], int size) //Generating a array to list.

{ list* head = createList((d[0]));

int i;

for (i = 1; i < size; i++) { head = addToFront(d[i], head); }

list* cache = head;

list* previous;

head = head->next;

head->previous = cache;

while(head->next != NULL)

{ previous = head; head = head->next; head->previous = previous; }

head = cache;

return head; }

void printList(list* h, char*title) //Prints list with 20 member in each row.

{ printf("%s\n", title);

for (int i = 1;h != NULL;i++)

{ printf("%u ", h->data);

if ((i % 20) == 0) printf("\n");

h = h->next; } }

list* bubbleSortList(list* s, int size)

{ list* h = s; //Using "h" as a cache to store head of the list.

int temp;

for (int i = 1; i < size; i++) //Program must run this code for n-1 times to sort correctly.

{ while (s->next != NULL)

{ if (s->data > s->next->data) //If first value is bigger than second it will swap them.

{ temp = s->next->data;

s->next->data = s->data;

s->data = temp;

} s = s->next; //Jumps to the next member.

} s = h; //At the end, program jumps to the head again. To run sorting again or returning the head.

}

return s; }

list* clearDuplicate(list* h) //Clears duplicated members. { list* temp = h; int cache = h->data; //Cache stores the data that will be used for comparisons. while (h->next != NULL) { if (cache != h->data) cache = h->data; //If cache's value doesn't match with first member it will be replaced with current one.

if (h->next->next == NULL && h->data == h->next->data) //Last element of the list is being checked here. If last 2 has same value, n-1 is being deleted here.

{ h = h->next;

h->previous = h->previous->previous;

h->previous->previous->next = h;

} else

{ h = h->next; //Checks every member here. If it finds a duplicate it removes it from the list.

if (h->data == cache && h->next != NULL)

{ h->previous->next = h->next;

h->next->previous = h->previous;

}

}

} return temp; //Returns the head. }

int main()

{
time_t t; srand((unsigned)time(&t));

list* head = NULL;

int data[200];

for (int i=0; i <200; i++) { data[i] = rand() %50; //Random numbers between 0 and 49. }

head = arrayToList(data, 200);

head = bubbleSortList(head, 200);

printList(head, "200 sorted random generated number"); //Prints sorted numbers. printf("\n\n");

head = clearDuplicate(head);

printList(head, "Duplicated data are deleted.");

printf("\n\n");

return 0;

}