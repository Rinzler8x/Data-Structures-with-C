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

void insert_specific(int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
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
            for(int i = 1; i < pos - 1; i++){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
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

void deletion_specific(int pos)
{
    struct node *temp = head;
    struct node *ptr;

    if(head == NULL)
        printf("List empty\n");
    else{
        if(head->next == NULL)
            head = NULL;
        else{
            for(int i = 1; i < pos; i++){
                ptr = temp;
                temp = temp->next;
            }
            ptr->next = temp->next;
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

void display()
{
    struct node *temp = head;

    if(head == NULL)
        printf("List empty\n");
    else{
        printf("Linked list: ");
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
	int cho;
    int pos;
	printf("Menu\n1.Insertion At Beginning\n2.Insertion At Specific\n3.Insertion At End\n4.Deletion At Beginning\n5.Deletion At Specific\n6.Deletion At End\n7.Display\n8.Exit");
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", &cho);
		printf("\n");

		switch (cho)
		{
		case 1:
			insert_begin();
			break;

		case 2:
			printf("Enter position to insert: ");
            scanf("%d", &pos);
            insert_specific(pos);
			break;

		case 3:
			insert_end();
			break;

		case 4:
			delete_begin();
			break;

		case 5:
			printf("Enter position to delete: ");
            scanf("%d", &pos);
            deletion_specific(pos);
			break;

		case 6:
            delete_end();
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Program exited\n");
            cho = 0;
            break;

        case 9:
            printf("Invalid Input\n");
            break;
		}
	} while (cho != 0);
	return 0;
}
