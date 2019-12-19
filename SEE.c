// BINARY TREE CREATION
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *rlink;
    struct node *llink;
}node;
node *tree,*temp,*root;
int is_left_child(node *tree)
{
    int ch;
    printf("Do you want a left child for %d 1.Yes 2.No : ",tree->data);
    scanf("%d",&ch);
    if(ch==1)
        return 1;
    else 
        return 0;
}
int is_right_child(node *tree)
{
    int ch;
    printf("Do you want a right child for %d 1.Yes 2.No : ",tree->data);
    scanf("%d",&ch);
    if(ch==1)
        return 1;
    else 
        return 0;
}
void create(node *tree)
{
    if(is_left_child(tree)==1)
    {
        temp=(node *)malloc(sizeof(node));
        printf("Enter the data :  ");
        scanf("%d",&temp->data);
        temp->llink=temp->rlink=NULL;
        tree->llink=temp;
        create(temp);
    }
    else
        tree->llink=NULL;
    if(is_right_child(tree)==1)
    {
        temp=(node *)malloc(sizeof(node));
        printf("Enter the data :  ");
        scanf("%d",&temp->data);
        temp->llink=temp->rlink=NULL;
        tree->rlink=temp;
        create(temp);
    }
    else
        tree->rlink=NULL;
}
void inorder(node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d",tree->data);
        inorder(tree->rlink);
    }
}
void preorder(node *tree)
{
    if(tree!=NULL)
    {
        printf("%d",tree->data);
        preorder(tree->llink);
        preorder(tree->rlink);
    }
}
void postorder(node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->llink);
        postorder(tree->rlink);
        printf("%d",tree->data);
    }
}
void main()
{
    root=(node *)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d",&(root->data));
    root->llink=root->rlink=NULL;
    create(root);
    printf("\nInorder : ");
    inorder(root);
    printf("\nPostorder : ");
    postorder(root);
    printf("\nPreorder : ");
    preorder(root);
}




//Binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}node;
node *tree,*root,*temp=NULL,*ptr=NULL,*parent; 
void create()
{
    temp=(node *)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
    {
        root = temp;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            parent =ptr;
            if(ptr->data==temp->data)
            {
                printf("Node exist !!");
                return;
            }
            else if(ptr->data>temp->data)
            {
                ptr=ptr->llink;
            }
            else
                ptr=ptr->rlink;
        }
        if(parent->data<temp->data)
        {
            parent->rlink=temp;
        }
        else
            parent->llink=temp;
    }
}
void inorder( node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d<-->",tree->data);
        inorder(tree->rlink);
    }

}
void postorder( node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->llink);
        postorder(tree->rlink);
        printf("%d<-->",tree->data);
    }

}
void preorder( node *tree)
{
    if(tree!=NULL)
    {
        printf("%d<-->",tree->data);
        preorder(tree->llink);
        preorder(tree->rlink);
    }

}
void display()
{
    printf("The inorder traversal of the tree is :- ");
    inorder(root);
    printf("\nThe postorder traversal of the tree is :- ");
    postorder(root);
    printf("\nThe preorder traversal of the tree is :- ");
    preorder(root);

}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Exit\n");
        printf("Enter your choice :- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : display();
                     break;
            case 3 : exit(0);
        }

    }

}



//Stack push and pop
#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int top=-1;s[SIZE],ditem;
void push()
{
    int num;
    if(top==SIZE-1)
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter the number to be pushed :- ");
        scanf("%d",&num);
        top++;
        s[top]=num;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        ditem=s[top];
        printf("The deleted item is %d",ditem);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("The stack is empty");
    }
    else
    {
        for(int i=top;i>=0;--i)
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
			default: printf("Wrong code entered");
		}
	}
}





//Binary_search_using_recursion
#include<stdio.h>
void binary_search(int [],int,int,int);
void main()
{
    int key,list[25],i,size;
    printf("Enter the size :-> ");
    scanf("%d",&size);
    printf("Enter the elements :-> ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&list[i]);
    }
    printf("Enter the element to be searched :-> ");
    scanf("%d",&key);
    binary_search(list,0,size,key);
}
void binary_search(int list[],int lo,int hi,int key)
{
    int mid;
    if(lo>hi)
    {
        printf("Key is not found");
        return;
    }
    mid=(lo+hi)/2;
    if(list[mid]==key)
    {
        printf("Key found");
    }
    else if(list[mid]>key)
    {
        binary_search(list,lo,mid-1,key);
    }
    else if(list[mid]<key)
    {
        binary_search(list,mid+1,hi,key);
    }
}



//GCD
#include<stdio.h>
int gcd(int,int);
int main()
{
    int n1,n2;
    printf("Enter two numbers :");
    scanf("%d %d",&n1,&n2);
    printf("GCD = %d",gcd(n1,n2));
    return 0;
}
int gcd(int n1,int n2)
{
    if(n2!=0)
        return (gcd(n2,n1%n2));
    else
        return n1;
}






//TOH
#include<stdio.h>
void toh(int n,char source,char destination,char temp)
{
    if(n==1)
    {
        printf("\nMove disc from %c to %c",source,destination);
    }
    else
    {
        toh(n-1,source,destination,temp);
        printf("\nMove disc from %c to %c",source,destination);
        toh(n-1,temp,source,destination);
    }
}
void main()
{
    int n;
    printf("Enter no discs: ");
    scanf("%d",&n);
    toh(n,'A','B','C');
}




//Postfix_eval
#include<stdio.h>
#include<stdlib.h>
char postfix[30],ch;
int num,op1,op2,top=-1,s[30];
void push(int num)
{
    s[++top]=num;
}
int pop()
{
    int ditem;
    ditem=s[top];
    top--;
    return(ditem);
}
void main()
{
    int j=0;
    printf("Enter the postfix expression : ");
    gets(postfix);
    while(postfix[j]!='\0')
    {
        ch=postfix[j];
        if(isalpha(ch))
        {
            printf("Enter the value for %c ",ch);
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
                case '*': push(op1*op2);
                    break;
                case '/': push(op1/op2);
                    break;
                default: printf("Wrong option");
            }
        }
        j++;
    }
    if(top==0)
        printf("Output = %d",s[top]);
    else
        printf("Wrong expression");
}



//Infix to postfix
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 30
char ch,infix[SIZE],postfix[SIZE],s[SIZE],temp;
int i=0,j=0,top=-1;
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
        case '/':
        case '*': return(3);
                  break;
        case '-':
        case '+': return(2);
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
                while(top!=-1&&(precedence(s[top])>=precedence(ch)))
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
            printf("Invalid expression");
        i++;
    }
    while(top>-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    puts(postfix);
}



//Linear queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int rear=-1,front =-1,q[SIZE],item,ditem;
void insert()
{
    if(rear==SIZE-1)
    {
        printf("The queue is full");
    }
    else
    {
        printf("Enter the number to be pushed : ");
        scanf("%d",&item);
        if(rear==-1&&front==-1)
        {
            rear=0;
            front=0;
        }
        else
        {
            rear=rear+1;
        }
        q[rear]=item;
    }
}
void delete()
{
    if(rear==-1&&front==-1)
    {
        printf("the list is empty");
    }
    else
    {
        ditem=q[front];
        printf("The deleted item is %d",ditem);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            front=front+1;
    }
}
void display()
{
    if(rear == -1 && front == -1)
        printf("Queue is empty !!\n");
    else
    {
        for(int i =front ; i<=rear ; i++)
        {
            printf("%d\n", q[i]);
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




//Circular queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int i,rear=-1,front =-1,cq[SIZE],item,ditem;
void insert()
{
    if(rear==(front-1)||(front==0&&rear==(SIZE-1)))
    {
        printf("The queue is full");
    }
    else
    {
        printf("Enter the number to be pushed : ");
        scanf("%d",&item);
        if(rear==-1&&front==-1)
            front=0;
        rear=(rear+1)%SIZE;
        cq[rear]=item;
    }
}
void delete()
{
    if(rear==-1&&front==-1)
    {
        printf("the list is empty");
    }
    else
    {
        ditem=cq[front];
        printf("The deleted item is %d",ditem);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            front=(front+1)%SIZE;
    }
}
void display()
{
    if(rear == -1 && front == -1)
        printf("Queue is empty !!\n");
    else
    {
        
        for(i =front ; i!= rear ; i=(i+1)%SIZE)
        {
            printf("%d\n", cq[i]);
        }
        printf("%d\n",cq[i]);
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


//Priority Queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int i,rear=-1,front =-1,pq[SIZE],item,ditem;
void check(int item)
{
    int j;
    for(i=0;i<=rear;i++)
    {
        if(item>=pq[i])
        {
            for(j=rear+1;j>i;j--)
            {
                pq[j]=pq[j-1];
            }
            pq[i]=item;
            return;
            
        }
    }
    pq[i]=item;
}
void insert()
{
    if(rear==(SIZE-1))
    {
        printf("The queue is full");
    }
    else
    {
        printf("Enter the number to be pushed : ");
        scanf("%d",&item);
        if(rear==-1&&front==-1)
        {
            front=0;
            rear=0;
            pq[rear]=item;
            return;
        }
        else
            check(item);
        rear++;
    }
}
void delete()
{
    if(rear==-1&&front==-1)
    {
        printf("the list is empty");
    }
    else
    {
        ditem=pq[front];
        printf("The deleted item is %d",ditem);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            front=(front+1);
    }
}
void display()
{
    if(rear == -1 && front == -1)
        printf("Queue is empty !!\n");
    else
    {
        
        for(i =front;i<=rear;i++)
        {
            printf("%d\n", pq[i]);
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










//Singly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *ptr,*temp,*head,*cur;
void create()
{
    temp=(node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
}
void insert_end()
{
    create();
    if(head==NULL)
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
void insert_beg()
{
    create();
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void insert_pos()
{
    int count=0,pos;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("Enter the position : ");
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
        create();
        ptr=head;
        for(int i=1;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}
void del_end()
{
    if(head==NULL)
    {
        printf("The list is empty !!");
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            cur=ptr;
            ptr=ptr->next;
        }
        cur->next=NULL;
        free(ptr);
        
    }
}
void del_beg()
{
    if(head==NULL)
    {
        printf("The list is empty !!");
    }
    else
    {
        cur=head;
        head=head->next;
        free(cur);
    }
}
void del_pos()
{
    int count=0,pos;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos==1)
    {
        del_beg();
    }
    else if(pos==count)
    {
        del_end();
    }
    else if(pos>1&&pos<count)
    {
        ptr=head;
        for(int i=1;i<pos;i++)
        {
            cur=ptr;
            ptr=ptr->next;
        }
        cur->next=ptr->next;
        free(ptr);
    }
}
void display()
{
    if(head==NULL)
    {
        printf("The list is empty !!");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d<-->",ptr->data);
            ptr=ptr->next;
        }
    }
}
void main()
{
	int ch;
	
	while (1)
	{
		printf("\n 1. Insert_end  \n 2. Insert_beg  \n 3. Display  \n 4. Location based \n 5. Delete_end \n 6. Delete_beg \n 7. Loc_based_del");
		printf("\nEnter your choice :-  ");
		scanf("%d",&ch);
		switch(ch)
		{ 
			case 1: insert_end();
				break;
			case 2: insert_beg();
				break;
			case 3: display();
				break;
			case 4: insert_pos();
				break;
			case 5: del_end();
				break;
			case 6: del_beg();
				break;
			case 7: del_pos();
				break;
		}
	}
}






//Reverse singly linked list
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






//Doubly linked list
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





//Ordered doubly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}node;

node *ptr,*temp = NULL, *start = NULL;

void create_node()
{
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data :- ");
    scanf("%d",&(temp->data));
    temp->llink = temp->rlink = NULL;
}
void insert_node()
{
    create_node();
    if(start==NULL)
    {
        start = temp;
    }
    else if(temp->data < start->data)
    {
        temp->rlink = start;
        start->llink = temp;
        start = temp;
    }
    else
    {
        ptr = start;
        while(ptr->rlink != NULL && temp->data>ptr->data)
        {
            ptr=ptr->rlink;
        }
        if(ptr->rlink == NULL && temp->data> ptr->data)
        {
            ptr->rlink = temp;
            temp->llink = ptr;
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





//Circular linked list
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





//Polynomial
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int power;
    int coeff;
    struct node *link;
}node;
node *start=NULL, *temp, *ptr , *cur;

void create()
{
    temp = (node *)malloc(sizeof(node));
    printf("Enter the coeff and power: ");
    scanf("%d %d", &temp->coeff,&temp->power);
    temp->link=NULL;

    if(start==NULL)
        start=temp;
    else if(start->power<=temp->power)
    {
        temp->link=start;
        start=temp;
    }
    else
    {
    
        ptr=start;
        while(ptr!=NULL&&ptr->power>=temp->power)
        {
            cur=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL)
            cur->link=temp;
        else
        {
            temp->link=cur->link;
            cur->link=temp;
        }
    }
}

void display()
{
    if(start==NULL)
        printf("\nThe list is empty !!");
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d <--> %d-->", ptr->coeff,ptr->power);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void evaluate()
{
    int sum=0,x;
    if(start==NULL)
        printf("List is empty !!");
    else
    {
        printf("Enter the value of x :  ");
        scanf("%d",&x);
        ptr=start;
        while(ptr!=NULL)
        {
            sum=sum+ptr->coeff*pow(x,ptr->power);
            ptr=ptr->link;
        }
    }
    printf("\nThe expression result is %d\n",sum);
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.Evaluate\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : display();
                     break;
            case 3 : evaluate();
                     break;
            case 4 : exit(0);
            default: printf("Wrong code entered !!");
        }
    }
}
