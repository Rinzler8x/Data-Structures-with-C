#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	if (newnode == NULL)
		printf("Memory not allocated\n");
	else
	{
		printf("Enter a value: ");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if (front == NULL){
			front = rear = newnode;
		}
		else{
			rear->next = newnode;
			rear = newnode;
		}
		printf("Element entered\n");
	}
}

void dequeue()
{
	struct node *temp;
	temp = front;
	if (front == NULL)
		printf("Queue Underflow\n");
	else
	{
		printf("Element deleted: %d\n", front->data);
		front = front->next;
		free(temp);
		if (front == NULL)
			rear = NULL;
	}
}

void peek()
{
	if (front == NULL)
		printf("Queue Underflow\n");
	else
		printf("Peek: %d\n", front->data);
}

void display()
{
	struct node *temp;
	temp = front;
	if (front == NULL)
		printf("Queue Underflow\n");
	else
	{
		printf("Queue: ");
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int cho;
	printf("Menu\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display");
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
