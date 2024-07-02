#include <stdio.h>
#include <stdlib.h>

struct Node{
	char data;
	struct Node *next;
};

typedef struct Node Stack_Node;
Stack_Node *Bottom=NULL;
Stack_Node *Top=NULL;
int Size = 0;

void Push(char);
char Pop();
char getBottom();
char getTop();
int getSize();
int isEmpty();

int main()
{
	printf("Is Stack empty? %d\n", isEmpty());
	
	printf("push a char \"P\" in stack\n");
	Push('P');

	printf("Is Stack empty? %d\n", isEmpty());

	printf("push a char \"O\" in stack\n");
        Push('O');

	printf("Get Top in stack -> %c\n", getTop());
	printf("POP\n");
	Pop();

	printf("Get Top in stack -> %c\n", getTop());

	return 0;
}

void Push(char data)
{
	Stack_Node *new_add_node;
	new_add_node = (Stack_Node*)malloc(sizeof(struct Node));

	new_add_node->data = data;

	if(Size == 0)
		Bottom = new_add_node;

	new_add_node->next = Top;
	Top = new_add_node;
	Size++;
}

char Pop()
{
	if(isEmpty())
	{
		printf("Stack is empty!\n");
	}else{
		Stack_Node *ptr = Top;
		char temp = Top->data;
		Top = Top->next;
		free(ptr);
		Size--;
		return temp;
	}	
}

char getBottom()
{
	if(!isEmpty())
		return Bottom->data;
}

char getTop()
{
	if(!isEmpty())
		return Top->data;
}

int getSize()
{
	return Size;
}

int isEmpty()
{
	if(Size == 0)
	{
		Bottom = NULL;
		Top = NULL;
		return 1;
	}else{
		return 0;
	}
}
