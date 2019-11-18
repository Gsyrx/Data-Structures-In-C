#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}node;
node *start = NULL,*temp,*ptr,*cur;

void create_node()
{
	temp = (node*)malloc(sizeof(node));
	printf("Enter the data :- ");
	scanf("%d",&(temp->data));
	temp->rlink = temp->llink = NULL;
}

void insert_end()
{
	create_node();
	if(start==NULL)
	{
		start = temp;
	}
	else 
	{
		ptr = start;

		while(ptr->rlink!=NULL)
			ptr = ptr->rlink;
		ptr->rlink = temp;
		temp->llink = ptr;				
		
	}
}
void display()
{
	if(start==NULL)
		printf("List is empty !!");
	else	
	{	
		ptr = start;
		while(ptr!= NULL)
		{
			printf("%d<-->",ptr->data);
			ptr = ptr->rlink;
		}
		
	}
}

void palindrome()
{
    int flag = 0,count = 1,i;
    
    if(start == NULL)
        printf("\nNo list is present !!");
    else
    {
        node *first,*last;
        ptr = first = start;
        
        while(ptr->rlink!=NULL)
        {
            ptr = ptr->rlink;
            count++;
        }    
        last = ptr; 
        
        for(i = 0;i<count/2;i++)
        {
            if(first->data!=last->data)
            {
                flag++;
                break;
            }  
            else
            {
                first = first->rlink;
                last = last->llink;
            }
            
        }
        if(flag==0)
        {
            printf("\nIt is a palindrome !!");
        }
        else
        {
            printf("\nIt is  not a palindrome");
        }
    }
}

void main()
{
	int choice;
	while(1)
	{	
	    printf("\n1.Insert\n2.Display\n3.Check (Palindrome or not)\n4.Exit");
	    printf("\nEnter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_end();
				    break;
			case 2: display();
				    break;
			case 3: palindrome();
				    break;
			case 4: exit(0);
            default: printf("Invalid choice !!");
        }
    }
}
