#include <string.h>
#include "linkedList.h"

node* createNode(int data, node* currentNode, node* nextNode)
{
	node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode != NULL)
	{
		newNode -> data = data;
		newNode -> next = nextNode;
		currentNode -> next = newNode;
		return newNode;
	} else {
		perror("The malloc operation failed during new node creation.\n");
	}
}

node* initialize(node* list, int n)
{
	list = (struct node*)malloc(sizeof(struct node));
	if (list != NULL) {
		list -> data = 1;
		list -> next = NULL;
		node* currentNode = list;
		int i;

		for (i = 2; i <= n; i++ ) {
			node* newItem = createNode(i, currentNode, NULL);
			currentNode = newItem;
		}
		return list;
	} else {
		perror("The malloc operation failed during new node creation.\n");
	}
}

node* initializeListWithArray(node* list, int n, int* array)
{
	list = (struct node*)malloc(sizeof(struct node));
	if (list != NULL) {
		list -> data = array[0];
		list -> next = NULL;
		node* currentNode = list;
		int i;
		for (i = 1; i < n; i++ ) {
			node* newItem = createNode(array[i], currentNode, NULL);
			currentNode = newItem;
		}
		return list;
	} else {
		perror("The malloc operation failed during new node creation.\n");
	}

}

void print(node* list)
{
	while(list != NULL)
	{
		printf("%p:%i -> ", list, list -> data);
		list = list -> next;	
	}
	printf("NULL\n\n");
}

void simplePrint(node* list)
{
	printf("\n%i", list -> data);
	list = list -> next;	
	while(list != NULL)
	{
		printf(" -> ");
		printf("%i", list -> data);
		list = list -> next;	
	}
	printf("\n\n");
}

int getSize(node* list)
{
	int size = 0;
	while(list != NULL)
	{
		list = list -> next;	
		size++;
	}
	return size;
}


int* getListData(node* list)
{
	int size = 0;
	int* arr = (int*)malloc((getSize(list)+1)*sizeof(int));
	if (arr != NULL)
	{
		while (list != NULL)
		{
			*(arr + size) = list -> data;
			list = list -> next;	
			size++;
		}
		return arr;
	} else {
		perror("The malloc operation failed during array creation.\n");
	}
}

int* getShuffleData(node* list)
{
	int i;
	int* listData = getListData(list);	
	int* result = (int*)malloc((getSize(list)+1)*sizeof(int));
	if (result != NULL)
	{
		int size = getSize(list);
		int halfSize = size/2;
		if (size % 2 != 0) 
		{
			halfSize = halfSize + 1;
		}
		int oddCount = 0;
		int evenCount = 0;
		for (i = 0; i < size; i++)
		{
			if (i % 2 == 0)
			{
				result[evenCount] = listData[i];
				evenCount++;
			} else {
				result[halfSize + oddCount] = listData[i];
				oddCount++;
			}
		}
		return result;
	} else {
		perror("The malloc operation failed during array creation.\n");
	}
}

node* reverse(node* list)
{
	int i;
	int* listData = getListData(list);	
	int size = getSize(list);
	for (i = size-1; i >= 0; i--)
	{
		list -> data = listData[i];
		list = list -> next; 
	}
	return list;
}

node* shuffle(node* list)
{
	int i;
	int* listData = getShuffleData(list);	
	int size = getSize(list);
	for (i = 0; i < size; i++)
	{
		list -> data = listData[i];
		list = list -> next; 
	}
	return list;
}

int* getShuffleNData(node* list, int n)
{
	int i;
	int j;
	int* listData = getListData(list);	
	int* result = (int*)malloc((getSize(list)+1)*sizeof(int));
	if (result != NULL)
	{
		int size = getSize(list);
		int count = 0;
		for (i = 0; i < size; i++)
		{
			result[count] = listData[i];
			count++;
			for (j = 1; j*n+i < size; j++)
			{
				result[count] = listData[j*n+i];
				count++;	
			}
		}
		return result;
	} else {
		perror("The malloc operation failed during array creation.\n");
	}
}

node* shuffleN(node* list, int n)
{
	int i;
	int* listData = getShuffleNData(list, n);	
	int size = getSize(list);
	for (i = 0; i < size; i++)
	{
		list -> data = listData[i];
		list = list -> next; 
	}
	return list;
}
