#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
}node;
node *start = NULL , *ptr,*cur,*temp;
void create_list()
{
    temp = (node*)malloc(sizeof(node));
    printf("Enter data :-  ");
    scanf("%d",&(temp->data));
    temp->rlink = temp->llink = NULL;
}
void insert_end()
{
    create_list();
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
        }
        temp->llink=ptr;
        ptr->rlink=temp;
    }
}
void insert_beg()
{
    create_list();
    if(start == NULL)
    {
        start=temp;
    }
    else
    {
        temp->rlink = start;
        start->llink = temp;
        start = temp;
    }
}
void insert_pos()
{
    int count=0,pos;
    ptr = start;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->rlink;
    }
    printf("Enter the position :-");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_beg();
    }
    else if(pos==count+1)
    {
        insert_end();
    }
    else if(pos>1&&pos<=count)
    {
        int i;
        ptr=start;
        for(i=1;i<pos-1;i++)
        {
            ptr = ptr->rlink;
        }
        create_list();
        temp ->rlink = ptr->rlink;
		temp->llink = ptr;
		ptr->rlink = temp;
		temp->rlink->llink = temp;
    }
    else
    {
        printf("INVALID POSITION !!");
    }
}
void delete_end()
{
    if(start ==NULL)
    {
        printf("The list is empty !!");
    }
    else if(start->rlink==NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        ptr = start;
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
        }
        cur=ptr->llink;
        cur->rlink=NULL;
        free(ptr);
    }
}
void delete_beg()
{
    if(start==NULL)
    {
        printf("The list is empty !!");
    }
    else if(start->rlink==NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        ptr = start;
        start = start->rlink;
        start->llink = NULL;
        free(ptr);
    }
}
void delete_pos()
{
    int count =0,pos;
    ptr = start;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->rlink;
    }
    printf("Enter the position :- ");
    scanf("%d",&pos);
    if(pos==1)
    {
        delete_beg();
    }
    else if(pos==count)
    {
        delete_end();
    }
    else if(pos>1&&pos<count)
    {
        int i;
        ptr = start;
        for(i=1;i<pos;i++)
        {
            ptr=ptr->rlink;
        }
        ptr->llink->rlink=ptr->rlink;
        ptr->rlink->llink=ptr->llink;
        free(ptr);
    }
    else
    {
        printf("INVALID POSITION");
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
            printf("%d<-->",ptr->data);
            ptr=ptr->rlink;
        }
    }
}
void main()
{
    int n;
    while(1)
    {
        printf("\n1.Insert_End\n2.Display\n3.Insert_Beg\n4.Insert_Pos\n5.Delete_end\n6.Delete_Beg\n7.Delete_Pos\n8.Exit\n");
        printf("Enter your choice :- ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: insert_end();
                    break;
            case 2: display();
                    break;
            case 3: insert_beg();
                    break;
            case 4: insert_pos();
                    break;
            case 5: delete_end();
                    break;
            case 6: delete_beg();
                    break;
            case 7: delete_pos();
                    break;
            case 8: exit(0);
            default: printf("Wrong code entered !!");
        }
    }
}
