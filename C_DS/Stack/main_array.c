#include <stdio.h>
#include <stdlib.h>
#define maxVolume 16

char stack[maxVolume];
int top = -1;
int bottom = -1;
int size = 0;

void Push(char);
char Pop();
char getBottom();
char getTop();
int getSize();
unsigned int isEmpty();

int main()
{	

	printf("push a char \"c\" to stack\n");
	Push('c');
	
	printf("pop a char from stack is %c\n", Pop());	

	return 0;
}

void Push(char data)
{
	if(top >= maxVolume)
	{
		printf("Stack is full!\n");
	}else{
		stack[++top] = data;
		size++;
		
		if (bottom == -1)
			bottom = 0;
	}
}

char Pop()
{
	if(isEmpty())
		printf("Stack is empty!\n");
	else{
		char data = stack[top];
	        top--;
		size--;
		return data;	
	}
}

char getBottom()
{
	if(!isEmpty())
		return stack[bottom];
}

char getTop()
{
	if(!isEmpty())
		return stack[top];
}

int getSize()
{
	return size;
}

unsigned int isEmpty()
{
	if(size < 0){
		top = -1;
		bottom = -1;
		return 1;	
	}else{
		return 0;
	}
}

