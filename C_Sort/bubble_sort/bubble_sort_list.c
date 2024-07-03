#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
	struct Node* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}

void bubbleSort(struct Node** head, int count)
{
	struct Node** h;
	int i, j, swapped;

	for(i = 0; i <= count; i++)
	{
		h = head;
		swapped = 0;

		for(j = 0; j < count - i - 1; j++)
		{	
			struct Node* p1 = *h;
			struct Node* p2 = p1->next;
		

			if(p1->data > p2->data){
				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;

		}

		if(swapped == 0)
			break;
	}
}

void printList(struct Node* n)
{
	while (n != NULL)
	{
		printf("%d -> ", n->data);
		n = n->next;
	}

	printf("\n");
}

void insertAtTheBegin(struct Node** start, int data)
{
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

	ptr->data = data;
	ptr->next = *start;
	*start = ptr;
}

int main()
{
	int arr[] = {78, 20, 10, 32, 1, 5};
	int list_size, i;

	struct Node* start = NULL;
	list_size = sizeof(arr) / sizeof(arr[0]);

	for(i = list_size - 1;i >= 0; i--)
		insertAtTheBegin(&start, arr[i]);

	printf("Linked list before sorting\n");
	printList(start);

	bubbleSort(&start, list_size);

	printf("Linked list after sorting\n");
	printList(start);

	return 0;
}
