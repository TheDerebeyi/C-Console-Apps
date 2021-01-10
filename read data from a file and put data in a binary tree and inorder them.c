//Created by Mert Kahraman.

//Open and read a file of integer pairs into an array that is created with the first integer telling you how many to read.  
//So  4 9  11  4  5    would mean create an integer array size 4 and read into data[].   
//Write a routine that places these values into a binary tree structure. Then walk the tree “inorder” and print these values to the screen.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

typedef int DATA;

struct node

{ DATA d; struct node* left; struct node* right; };

typedef struct node NODE;

typedef NODE* BTREE;

void inorder(BTREE root) //It sorts and prints the binary tree as LEFT-ROOT-RIGHT template.

{
if (root != NULL)

{ inorder(root->left); printf("%d ", root->d); inorder(root->right); }

}

BTREE new_node(void) //Allocates memory to new node.

{ return(malloc(sizeof(NODE)));

}

BTREE init_node(DATA d1, BTREE p1, BTREE p2) //Initializes a new node, give it a right and left node.

{ BTREE t;

t = new_node();

t->d = d1;

t->left = p1;

t->right = p2;

return t;

}

BTREE create_tree(DATA a[], int i, int size) //Takes the data from an array and starting from i places elements of an array into binary tree's nodes.

{

if (i >= size)

return NULL; else

{
return(init_node(a[i], create_tree(a, 2 * i + 1, size), create_tree(a, 2 * i + 2, size)));

} //When init_node() function starts, it calls create_tree() to get a p1 value and in the back a new node creates for root->left. And for root->left's left a new node gets created until i became equal or more to size. Its same for right nodes.

}

void data_to_array(FILE* ifp, int data[], int size) //Reads data into an array.

{ int c;

for (int i = 0; i < size; i++)

{ fscanf(ifp, "%d", &c); data[i] = c; }

}

int main()

{
FILE* ifp; ifp = fopen("data.txt", "r"); //Opens file.

int size;

fscanf(ifp, "%d", &size); //Reads how many integers we should read.

int data[100];

data_to_array(ifp, data, size);

BTREE b; //Creates root.

b = create_tree(data, 0, size); //data[0] as root. We didn't use any rewind() in the code because I wanted to pass the first value of data which shows us the how many integers we would read.

inorder(b);

printf("\n\n");

fclose(ifp); //Closing the file.

return 0;

}