#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node* next;
}node;
node *head=NULL,*temp,*ptr;
int n;
node *temp=NULL;
node *ptr=NULL;

void create_list()
{
		temp=(node*)malloc(sizeof(node));
		printf("Enter the data:- ");
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
	        ptr->next = temp;
		}
	
}

void deleteAlt() 
{ 
    if (head == NULL) 
        return; 
  
    /* Initialize prev and node to be deleted */
    struct node *prev = head; 
    struct node *cur = head->next; 
  
    while (prev != NULL && cur != NULL) 
    { 
        /* Change next link of previous node */
        prev->next = cur->next; 
  
        /* Free memory */
        free(cur); 
  
        /* Update prev and node */
        prev = prev->next; 
        if (prev != NULL) 
            cur = prev->next; 
    } 
} 


//display
void display()
{   // NO NODE
	if(head==NULL)
		printf("Link is empty !!");
	else	// NODE PRESENT
	{	
		ptr = head;
		while(ptr!= NULL)
		{
			printf("%d<-->",ptr->data);
			ptr = ptr->next;
		}
	}
}

void main()
{
    int choice;
	while(1)
	{	
	    printf("\n1.Insert \n2.Display\n3.Delete alternate elements\n4.Exit");
	    printf("\nEnter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create_list();
				    break;
			case 2: display();
				    break;
            case 3: deleteAlt();
                    break;
            case 4: exit(0);
            default: printf("INVALID CHOICE !!");
        }
    }
}
