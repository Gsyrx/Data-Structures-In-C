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
		printf("\n Enter the data ");
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





void display()
{
	if (head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		ptr=head;
		while (ptr!=NULL)
		{	
			printf("\t %d --> ",ptr->data);
			ptr=ptr->next;		

		}
	}
}
void reverse()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head


    }
}


void main()
{
	int ch;
	
	while (1)
	{
		printf("\n1.Insert\n2.Display\n3.Reverse\n4.Exit\n");
		printf("\nEnter your choice :-  ");
		scanf("%d",&ch);
		switch(ch)
		{ 
			case 1: insert();
				break;
			case 2: display();
				break;
			case 3: reverse();
			    break;
			case 4: exit(0);
			default: printf("Wrong code entered !!");
		}
	}
}
