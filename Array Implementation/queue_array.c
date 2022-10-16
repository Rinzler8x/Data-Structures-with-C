#include<stdio.h>
#include<conio.h>
#define size 5
int queue[size];
int front = -1;
int rear = -1;

int isfull()
{
	if (rear == size - 1) {
		printf("Queue Overflow\n");
		return 0;
	}
	else
		return 1;
}

int isempty()
{
	if (front == -1 || front == rear + 1) {
		printf("Queue Underflow\n");
		return 0;
	}
	else
		return 1;
}

void enqueue()
{
	int ele;
	if (isfull())
	{
		printf("Enter a value: ");
		scanf("%d", &ele);
		if (front == -1 && rear == -1)
			front = rear = 0;
		else
			rear++;
		queue[rear] = ele;
		printf("Value enqueued\n");
	}
}

void dequeue()
{
	if (isempty()) {
		printf("%d is dequeued\n", queue[front]);
		front++;
	}
}

void peek()
{
	if (isempty())
		printf("Peek: %d\n", queue[front]);
}

void display()
{
	if (isempty())
	{
		printf("Queue: ");
		for (int i = front; i <= rear; i++)
			printf("%d ", queue[i]);
	}
	printf("\n");
}

int main()
{
	int cho;
	printf("Menu\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", &cho);
		printf("\n");

		switch (cho)
		{
		case 1:
			enqueue();
			break;

		case 2:
			dequeue();
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
