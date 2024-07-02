#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node Queue_Node;
Queue_Node *First = NULL;
Queue_Node *Last = NULL;
int Size = 0;

void Enqueue(char);
char Dequeue();
char getFirst();
char getLast();
int getSize();
int isEmpty();

int main()
{
	return 0;
}

void Enqueue(char data)
{
	Queue_Node *new_add_node;

	new_add_node = (Queue_Node*)malloc(sizeof(struct Node));

	new_add_node->data = data;
	new_add_node->next = NULL;

	if(isEmpty())
		First = new_add_node;
	else
		Last->next = new_add_node;

	Last = new_add_node;
	Size++;
}

char Dequeue()
{
	if(isEmpty()){
		printf("Queue is empty!\n");
	}else{
		Queue_Node *ptr = First;
		char temp = First->data;
		First = First->next;
		free(ptr);
		Size--;
		return temp;
	}
}

char getFirst()
{
	if(!isEmpty())
		return First->data;
}

char getLast()
{
	if(!isEmpty())
		return Last->data;
}

int getSize()
{
	return Size;
}

int isEmpty()
{
	if(Size == 0){
		First = NULL;
		Last = NULL;
		return 1;
	}else{
		return 0;
	}
}

