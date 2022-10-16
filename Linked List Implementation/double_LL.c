#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head = NULL;

void insert_begin()
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	if (newnode == NULL)
		printf("Memory not allocated\n");
	else {
		printf("Enter value: ");
		scanf("%d", &newnode->data);
		newnode->next = newnode->prev = NULL;
		if (head == NULL)
			head = newnode;
		else {
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
		printf("Value entered\n");
			head = newnode;
	}
}

void insert_end()
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));

	if (newnode == NULL)
		printf("Memory not allocated\n");
	else {
		printf("Enter value: ");
		scanf("%d", &newnode->data);
		newnode->next = newnode->prev = NULL;
		if (head == NULL)
			head = newnode;
		else {
			struct node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
		}
		printf("Value entered\n");
	}
}

void del_value()
{
	struct node *temp = head;
	int key, flag = 0, count = 1;

	if (head == NULL)
		printf("List empty\n");
	else {
		printf("Enter value to be deleted: ");
		scanf("%d", &key);
		while (temp != NULL)
		{
			if (temp->data == key) {
				flag = 1;
				break;
			}
			else {
				temp = temp->next;
				count++;
			}
		}
		if (flag == 1) {
			if (temp->next == NULL && temp->prev == NULL)
				head = NULL;
			else if (temp->prev == NULL) {
				head = head->next;
				head->prev = NULL;
			}
			else if (temp->next == NULL)
				(temp->prev)->next = NULL;
			else {
				(temp->prev)->next = temp->next;
				(temp->next)->prev = temp->prev;
			}
			free(temp);
			printf("%d deleted from position: %d\n", key, count);
		}
		else
			printf("%d is not in the list\n", key);
	}
}

void display()
{
	struct node *temp = head;
	if (head == NULL)
		printf("List empty\n");
	else {
		printf("Linked List: ");
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
	printf("Menu\n1.Insert at beginning\n2.Insert at end\n3.Delete by value\n4.Display\n5.Exit");
	do {
		printf("\nEnter your choice: ");
		scanf("%d", &cho);
		printf("\n");

		switch (cho)
		{
		case 1:
			insert_begin();
			break;

		case 2:
			insert_end();
			break;

		case 3:
			del_value();
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
	}while (cho != 0);
	return 0;
}
