#include <stdio.h>
#include <stdlib.h>
#define maxVolume 16

int Queue[maxVolume];
int First = -1;
int Last = -1;
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

void Enqueue(char a)
{
	if(Last >= maxVolume)
	{
		printf("Queue is full!\n");
	}else{
		Queue[++Last] = a;
		Size += 1;
		if(First == -1)
			First = 0;
	}
}

char Dequeue()
{
	if(isEmpty()){
		printf("Queue is empty\n");
	}else{
		char data;
		data = Queue[First];
		for(int i = First; i<=Last; i++){
			Queue[i] = Queue[i+1];
		}
		Last -= 1;
		Size -= 1;
		return data;
	}
}

char getFirst()
{
	if(!isEmpty())
		return Queue[First];
}

char getLast()
{
	if(!isEmpty())
		return Queue[Last];
}

int getSize()
{
	return Size;
}

int isEmpty()
{
	if(Size <= 0){
		First = -1;
		Last = -1;
		return 1;
	}else{
		return 0;
	}

}

