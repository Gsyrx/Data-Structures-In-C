#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;
node *last = NULL, *temp=NULL,*ptr=NULL,*cur;

void insert_end()
{
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter the data :- ");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(last == NULL)
    {
        last = temp;
        last->link = last;
    }
    else
    {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}

void insert_beg()
{
 
    temp = ( node *)malloc(sizeof( node));
    printf("\nEnter the data :->");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(last == NULL)
    {
        last = temp;
        last->link = last;
    }
    else
    {
        temp->link = last->link;
        last->link = temp;

    }
}

void insert_pos()
{
   
    int pos;
    int count = 0;

    printf("\nEnter the pos :- ");
    scanf("%d", &pos);

    ptr = last->link;
    while(ptr != last)
    {
        count++;
        ptr = ptr->link;
    }
    count++;
    if(pos == 1)
    {
        insert_beg();
    }
    else if(pos == count+1)
    {
        insert_end();
    }
    else if(pos>1 && pos<= count)
    {
    
        temp = (node *)malloc(sizeof(node));
        printf("\nEnter the data :- ");
        scanf("%d", &temp->data);
        temp -> link = NULL;
        ptr = last->link;
        for(int i = 1; i<pos-1; i++)
        {
            ptr = ptr->link;
        }
        temp -> link = ptr -> link;
        ptr -> link = temp;
    }
    else
        printf("Invalid location !!");
}
void delete_end()
{
    

    if(last == NULL)
        printf("The list is empty !!");

    cur = last->link;

    if(last->link == last)
    {
        last = NULL;
        free(last);
    }
    else
    {
        while(cur->link != last)
        {
            cur = cur->link;
        }
        cur->link = last->link;
        free(last);
        last = cur;
    }

}

void delete_beg()
{

    if(last == NULL)
        printf("\nThe list is empty !!");

    ptr = last->link;

    if(last->link == last)
    {
        last = NULL;
        free(last);
    }
    else
    {
        last->link = ptr->link;
        ptr->link = NULL;
        free(ptr);
    }
}


void display()
{

    if(last == NULL)
        printf("\nThe list is empty !!");
    else
    {
        temp = last->link;
        while(temp != last)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("%d-->", temp->data);
        printf("\n");
    }
}

void delete_pos()
{
  
    int pos;
    int count = 0;

    printf("\nEnter the position :- ");
    scanf("%d", &pos);

    ptr = last->link;
    while(ptr != last)
    {
        count++;
        ptr = ptr->link;
    }
    count++;
    if(pos == 1)
    {
        delete_beg();
    }
    else if(pos == count)
    {
        delete_end();
    }
    else if(pos>1 && pos< count)
    {

        cur = last->link;
        ptr = cur->link;

        for(int i = 1; i<pos-1; i++)
        {
            ptr = ptr->link;
            cur = cur->link;
        }
        cur -> link = ptr -> link;
        ptr -> link = NULL;
        free(ptr);
    }
    else
        printf("Invalid location !!");

}

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert_end\n2.Display\n3.Insert_beg\n4.Insert_pos\n5.Delete_end\n6.Delete_beg\n7.Delete_pos\n8.Exit\n");
        printf("\nEnter your choice :- ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : insert_end();
                     break;
            case 2 : display();
                     break;
            case 3 : insert_beg();
                     break;
            case 4 : insert_pos();
                     break;
            case 5 : delete_end();
                     break;
            case 6 : delete_beg();
                     break;
            case 7 : delete_pos();
                     break;
            case 8 : exit(0);
            default: printf("Wrong code entered !!");
        }
    }
}
