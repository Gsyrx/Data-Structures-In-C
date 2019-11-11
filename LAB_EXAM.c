//INFIX_TO_POSTFIX
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 30
char ch,postfix[SIZE],infix[SIZE],s[SIZE],temp;
int top=-1,i=0,j=0;
void push(char ch)
{
    top=top+1;
    s[top]=ch;
}
char pop()
{
    temp=s[top--];
    return(temp);
}
int isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        return(1);
    else
        return(0);
}
int precedence(char ch)
{
    switch(ch)
    {
        case '^': return(4);
                    break;
        case '*':
        case '/': return(3);
                    break;
        case '+':
        case '-': return(2);
                    break;
        default:  return(1);
    }
}
void main()
{
    printf("Enter the expression :- ");
    gets(infix);
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(isalpha(ch))
        {
            postfix[j]=ch;
            j++;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(isoperator(ch)==1)
        {
            if(ch!='^')
            {
                while(top!=-1 && precedence(s[top])>=precedence(ch))
                {
                    postfix[j]=pop();
                    j++;
                }
            }
            push(ch);
        }
        else if(ch==')')
        {
            while(s[top]!='(')
            {
                postfix[j]=pop();
                j++;
            }
            temp=pop();
        }
        else
        {
            printf("Invalid Character !!");
        }
        i++;
    }
    while(top>-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("Output :- ");
    puts(postfix);
}






//DOUBLY_LINKED_LIST
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}node;
node *start = NULL,*ptr,*cur,*temp;
int i;
void create_list()
{
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data :- ");
    scanf("%d",&(temp->data));
    temp->llink = temp->rlink = NULL;
}
void insert_end()
{
    create_list();
    if(start==NULL)
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
        ptr->rlink = temp;
        temp->llink = ptr;
    }
}
void insert_beg()
{
    create_list();
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->rlink=start;
        start->llink=temp;
        start =temp;
    }
}
void insert_pos()
{
    int count=0,pos;
    ptr=start;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->rlink;
    }
    printf("Enter the position :- ");
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
        ptr=start;
        for(i =1;i<pos-1;i++)
        {
            ptr=ptr->rlink;
        }
        create_list();
        temp->rlink=ptr->rlink;
        temp->llink=ptr;
        ptr->rlink=temp;
        temp->rlink->llink=temp;
    }
    else
    {
        printf("INVALID POSITION !!");
    }
}
void delete_end()
{
    if(start==NULL)
    {
        printf("The list is empty !!");
    }
    else if(start->rlink==NULL)
    {
        free(start);
        start=NULL;
    }
    else
    {
        ptr=start;
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
        start=NULL;
    }
    else
    {
        ptr=start;
        start=start->rlink;
        start->llink=NULL;
        free(ptr);
    }
}
void delete_pos()
{
    int count=0,pos;
    ptr=start;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->rlink;
    }
    printf("Enter the position to be deleted :-  ");
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
        ptr=start;
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
        printf("Invalid position !!");
    }
}
void display()
{
    if(start==NULL)
    {
        printf("The list is empty !!");
    }
    else
    {
        ptr=start;
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








//ORDERED_DOUBLY_LINKED_LIST
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}node;
node *start = NULL,*ptr,*temp;
int i;
void create_list()
{
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data :- ");
    scanf("%d",&(temp->data));
    temp->llink = temp->rlink = NULL;
}
void insert_node()
{
    create_list();
    if(start==NULL)
    {
        start=temp;
    }
    else if(temp->data<start->data)
    {
        start->llink=temp;
        temp->rlink=start;
        start=temp;
    }
    else 
    {
        ptr=start;
        while(ptr->rlink!=NULL && temp->data>ptr->data)
        {
            ptr=ptr->rlink;
        }
        if(ptr->rlink==NULL&&temp->data>ptr->data)
        {
            ptr->rlink=temp;
            temp->llink=ptr;
        }
        else
        {
            temp->rlink = ptr;
            ptr->llink->rlink = temp;
            temp->llink = ptr->llink;
            ptr->llink = temp;
        }
    }
}
void display()
{
    if(start ==NULL)
    {
        printf("The list is empty !!");
    }
    else
    {
        ptr = start;
        while(ptr != NULL)
        {
            printf("%d<-->",ptr->data);
            ptr = ptr->rlink;
        }
    }
}
void main()
{
    int n;
    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.Exit");
        printf("\nEnter your choice :- ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: insert_node();
                    break;
            case 2: display();
                    break;
            case 3: exit(0);
            default: printf("Wrong code entered !!");
        }
    }
}







//STACK_IN_C
#include<stdio.h>
#define SIZE 4
int top=-1,num,s[SIZE],ditem;
void push()
{
    if(top==SIZE-1)
    {
        printf("OVERFLOW !!");
    }
    else
    {
        printf("Enter the number to be pushed :- ");
        scanf("%d",&num);
        top=top+1;
        s[top]=num;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("UNDERFLOW !!");
    }
    else
    {
        ditem=s[top];
        printf("The deleted item is :- %d",ditem);
        top=top-1;
    }
}
void display()
{
    if(top==-1)
    {
        printf("The stack is empty !!");
    }
    else
    {
        int i;
        for(i=top;i>=0;--i)
        {
            printf("%d\n",s[i]);
        }
    }
}
void main()
{
	int n;
	while(1)
	{
		printf("\n\n\n1 :- PUSH\n2 :-POP\n3 :-DISPLAY\n4 :- EXIT");
		printf("\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Wrong code entered !!");
		}
	}
}






//POSTFIX_EVALUATION
#include<stdio.h>
#include<stdlib.h>
char postfix[30],ch;
int top=-1,op1,op2,j,num,s[30];
void push(int num)
{
    top=top+1;
    s[top]=num;
}
int pop()
{
    int ditem;
    ditem=s[top];
    top=top-1;
    return(ditem);
}
void main()
{
    printf("Enter the postfix expression :- ");
    gets(postfix);
    while(postfix[j]!='\0')
    {
        ch=postfix[j];
        if(isalpha(ch))
        {
            printf("Enter the value for %c :- ",ch);
            scanf("%d",&num);
            push(num);
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(ch)
            {
                case '+': push(op1+op2);
                            break;
                case '-': push(op1-op2);
                            break;
                case '/': push(op1/op2);
                            break;
                case '*': push(op1*op2);
                            break;
                default: printf("'Wrong operator !!");
            }
        }
        j++;
    }
    if(top==0)
    {
        printf("Output :- %d",s[top]);
    }
    else
    {
        printf("Wrong expression !!");
    }
}







//LINEAR_QUEUE
#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int rear=-1,front=-1,item,ditem,Q[SIZE];
void insert()
{
    if(rear==SIZE-1)
    {
        printf("The queue is full !!");
    }
    else
    {
        printf("Enter the number to be pushed :- ");
        scanf("%d",&item);
        if(rear==-1&&front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=rear+1;
        }
        Q[rear]=item;
    }
}
void delete()
{
    if(rear==-1&&front==-1)
    {
        printf("The queue is empty !!");
    }
    else
    {
        ditem=Q[front];
        printf("The deleted element is :- %d ",ditem);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
    }
}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("The queue is empty !!!");
    }
    else
    {
        int i;
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",Q[i]);
        }
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter the choice :-  ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : insert();
                     break;
            case 2 : delete();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
            default: printf("Wrong code entered !!");
        }
    }
}





//CIRCULAR_QUEUE
#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

int rear = -1, front = -1, CQ[SIZE], item,  i;

void insert()
{
    if(rear == (front - 1) || (front == 0 && rear == (SIZE-1)))
        printf("overflow\n");
    else
    {
        printf("enter the element\n");
        scanf("%d", &item);

        if(front == -1 && rear == -1)
            front = 0;

        rear = (rear + 1) % SIZE ;
        CQ[rear] = item;
    }
}

void Delete()
{
    if(rear == -1 && front == -1)
    {
        printf("underflow\n");
    }
    else
    {

        printf("%d\n", CQ[front]);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % SIZE ;
    }
}

void display()
{
    if(rear == -1 && front == -1)
        printf("empty\n");
    else
    {
        for( i = front ; i != rear ; i = (i+1)%SIZE)
        {
            printf("%d\n", CQ[i]);
        }
        printf("%d\n", CQ[i]);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : insert();
                     break;
            case 2 : Delete();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
        }
    }
}
