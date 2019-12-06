#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node* next;
}node;
node *head=NULL,*temp,*ptr;
int n;
node *temp=NULL;
node *ptr=NULL;

void insert()
{

		temp=(node*)malloc(sizeof(node));
		printf("\nEnter the data:- ");
		scanf("%d", &(temp->data));
		temp->next=NULL;

		if (head==NULL)
		{		
			head=temp;
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{	
				ptr=ptr->next;		

			}
			ptr->next=temp;
	
		}
	
}
void delete()
{	
    if (head==NULL)
	{
		printf("The list is empty!!");
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
		
	}
}



void display()
{
	if (head==NULL)
	{
		printf("List is empty!!");
	}
	else
	{
		ptr=head;
		while (ptr!=NULL)
		{	
			printf("%d\n",ptr->data);
			ptr=ptr->next;		

		}
	}
}

void main()
{
	int ch;
	
	while (1)
	{
		printf("\n1.Inser\n2.Delete\n3.Display\n4.Exit");
		printf("\nEnter your choice :-  ");
		scanf("%d",&ch);
		switch(ch)
		{ 
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Wrong code entered !!");
		}
	}
}
