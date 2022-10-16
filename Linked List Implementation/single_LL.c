#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert_begin()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
        printf("Memory not allocated\n");
    else{
        printf("Enter value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else{
            newnode->next = head;
            head = newnode;
        }
        printf("Value entered\n");
    }
}

void insert_end()
{
    struct node *newnode = (struct node * )malloc(sizeof(struct node));
    struct node *temp = head;

    if(newnode == NULL)
        printf("Memory not allocated\n");
    else{
        printf("Enter value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        
        if(head == NULL)
            head = newnode;
        else{
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        printf("Value entered\n");
    }
}

void delete_begin()
{
    struct node *temp = head;

    if(head == NULL)
        printf("List empty\n");
    else{
        printf("%d deleted\n", head->data);
        if(head->next == NULL)
            head = NULL;
        else{
            head = head->next;
        }
        free(temp);
    }
}

void delete_end()
{
    struct node *temp = head;
    struct node *ptr = head;
    if(head == NULL)
        printf("List empty\n");
    else{
        if(head->next == NULL)
            head == NULL;
        else{
            while(temp->next != NULL)
            {
                ptr = temp;
                temp = temp->next;
            }
            printf("%d deleted\n", temp->data);
            ptr->next = NULL;
        }
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
