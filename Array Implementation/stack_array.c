#include<stdio.h>
#include<conio.h>
#define size 5
int stack[size];
int top = -1;


int isfull()
{
	if (top == size - 1) {
		printf("Stack Overflow\n");
		return 0;
	}
	else
		return 1;
}

int isempty()
{
	if (top == -1) {
		printf("Stack Underflow\n");
		return 0;
	}
	else
		return 1;
}

void push()
{
	int ele;
	if (isfull())
	{
		printf("Enter a value: ");
		scanf("%d", &ele);
		top++;
		stack[top] = ele;
		printf("Value pushed\n");
	}
}

void pop()
{
	if (isempty())
	{
		printf("%d is popped\n", stack[top]);
		top--;
	}
}

void peek()
{
	if (isempty())
	{
		printf("Peek: %d\n", stack[top]);
	}
}

void display()
{
	if (isempty())
	{
		printf("Stack:\n");
		for (int i = top; i >= 0; i--)
			printf("%d\n", stack[i]);
	}
}

int main()
{
	int cho;
	printf("Menu\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", &cho);
		printf("\n");

		switch (cho)
		{
		case 1: 
			push();
			break;

		case 2:
			pop();
			break;

		case 3:
			peek();
			break;

		case 4:
			display();
			break;

		case 5:
			printf("Program Exited\n");
			cho = 0;
			break;

		default:
			printf("Invalid Input\n");
			break;
		}
	} while (cho != 0);
	return 0;
}
