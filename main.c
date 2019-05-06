#include "linkedList.h"

#define SIZE 6

int main()
{
	int size;
	printf("-----------------------------------------------------------\n");
	printf("Welcome to linked list creation and modification program...\n");
	printf("------------------------------------------------------------\n\n");
	printf("Please enter the linked list size: ");
	scanf("%d", &size);

	/* Initializing linked list. */
	node* list = (struct node*)malloc(sizeof(struct node));
	node* linkedList = NULL;
	if (list != NULL)
	{ 
		linkedList = initialize(list, size);
		printf("\nInitializing linked list...\n");
		print(linkedList);
	} else {
		perror("The malloc operation failed during new node creation.");
	}

	/* Reversing linked list. */
	reverse(linkedList);
	printf("\nReversing linked list...");
	simplePrint(linkedList);
	
	/* Initializing linked list based on entered size and numbers. */
	printf("Please enter the new linked list size: ");
	scanf("%d", &size);
	printf("Please enter the linked list values, each in a new line...\n");
	int i;
	int j;
	int arr[size];
	for (i = 0; i < size; i++) 
	{
		scanf("%d", &arr[i]);	
	}
	list = (struct node*)malloc(sizeof(struct node));
	if (list != NULL)
	{
        	linkedList = (node*)initializeListWithArray(list, size, arr);

		/* Reversing new linked list. */
		reverse(linkedList);
		printf("\nReversing linked list...");
		simplePrint(linkedList);

		/* Shuffling new linked list. */
		printf("\nShuffling linked list...");
		shuffle(linkedList);
		simplePrint(linkedList);
	} else {
		perror("The malloc operation failed during new node creation.");
	}

	/* Given examples for N Shuffling. */
	int array[] = {40, 2, 23, 14, 5, 6};
	list = (struct node*)malloc(sizeof(struct node));
	if (list != NULL)
	{
		linkedList = (struct node*)initializeListWithArray(list, SIZE, array);
		printf("\nInitializing shuffled linked list...");
		simplePrint(linkedList);

		int n = 2;
		shuffleN(linkedList, n);
		printf("\nN(%d) Shuffling linked list...", n);
		simplePrint(linkedList);

		n = 3;
		linkedList = (struct node*)initializeListWithArray(list, SIZE, array);
		shuffleN(linkedList, n);
		printf("\nN(%d) Shuffling linked list...", n);
		simplePrint(linkedList);

		n = 4;
		linkedList = (struct node*)initializeListWithArray(list, SIZE, array);
		shuffleN(linkedList, n);
		printf("\nN(%d) Shuffling linked list...", n);
		simplePrint(linkedList);
	} else {
		perror("The malloc operation is failed during new node creation.");
	}

	/* N Shuffling for any list items and n. */
	printf("Please enter the new linked list size for shuffling...");
	scanf("%d", &size);
	printf("Please enter the linked list values, each in a new line...\n");
	for (i = 0; i < size; i++) 
	{
		scanf("%d", &arr[i]);	
	}
	list = (struct node*)malloc(sizeof(struct node));
        linkedList = (node*)initializeListWithArray(list, size, arr);
	printf("Please enter number of N shuffling: ");
	int n;
	scanf("%d", &n);
	shuffleN(linkedList, n);
	printf("\nN(%d) Shuffling linked list...", n);
	simplePrint(linkedList);

	/* Dealloating allocated memory. */
	free(list);
	list = NULL;

	return 0;
}
