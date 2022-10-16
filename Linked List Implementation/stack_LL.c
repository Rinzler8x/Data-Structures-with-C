#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
 };
struct node *top = NULL;

int isEmpty()
{
	if (top == NULL) {
		printf("Stack Underflow\n");
		return 0;
	}
	else
		return 1;
}

void peek()
{
	if (isEmpty())
		printf("Peek: %d\n", top->data);
}

void display()
{
	struct node *temp;
	temp = top;
	if (isEmpty()) {
		printf("Stack:\n");
		while (temp != NULL) {
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
}

void push()
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
		printf("Memory not allocated\n");
	else {
		printf("Enter value: ");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if (top == NULL)
			top = newnode;
		else
		{
			newnode->next = top;
			top = newnode;
		}
		printf("Value Entered.\n");
	}
}

void pop()
{
	struct node *temp;
	temp = top;
	if (isEmpty()){
		top = top->next;
		printf("%d is popped\n", temp->data);
		free(temp);
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
