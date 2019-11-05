#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}node;
node *start = NULL, *ptr = NULL, *temp = NULL;

void insert_end()
{
	temp = (node*)malloc(sizeof(node));
	printf("Enter the number :-  ");
	scanf("%d",&(temp->data));
	temp->rlink = NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		ptr = start;
		while(ptr->rlink!=NULL)
		{
			ptr = ptr->rlink;
			ptr->rlink = temp;
			temp->llink = ptr;
		}
	}
}
void display()
{
	if(start == NULL)
	{
		printf("The list is empty !!!");
	}
	else
	{
		ptr = start;
		while(ptr!=NULL)
		{
			printf("%d--> ",ptr->data);
			ptr=ptr->rlink;
		}
	}
}
void main()
{
	int n;
	while(1)
	{
		printf("\n\n1.Insert_End\n2.Display\n3.Exit");
		printf("\nEnter your choice :- ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: insert_end();
				break;
			case 2: display();
				break;
			case 3: exit(0);
			default: printf("Wrong code entered");
		}
	}
}
