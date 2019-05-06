#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/* Creating node struct. */
typedef struct node 
{
	int data;
	struct node *next; 
} node;

/* The function initializes the list, appends n new nodes and assigns consecutive
integer values to all elements in the list.  */
node* initialize(node* list, int n);

/* The function prints the linked list elements: the address of the node, it's data and link to the next node and so on till the end of the list. */
void print(node* list);

/* The function reverses the given list. */
node* reverse(node* list);

/* The function updates the given list so that the nodes with odd indexes (positions) are brought to the beginning of the list and the nodes with even indexes (positions) are appended to the end of the list with odd indexes.  */
node* shuffle(node* list);

/* The function updates the given list so that shuffles the given list so the resulting list becomes
1st node -> (n+1)th node -> (2n+1)th node -> ... -> 2nd node -> (n+2)th node -> (2n + 2)th node -> ... -> (n)th node -> (2n)th node -> ... */
node* shuffleN(node* list, int n);

#endif
