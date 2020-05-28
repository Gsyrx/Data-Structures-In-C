//Bubble_Sort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    int n,i,j,temp;
    clock_t start,end;
    double totaltime;
    printf("\nEnter the number of elements :- ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i] = rand();
    }
    start = clock();
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    end = clock();
    totaltime = (double)(end-start)/CLOCKS_PER_SEC;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nTime taken = %lf",totaltime);
}


//Selection_Sort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    int n,i,j,temp,min;
    clock_t start,end;
    double totaltime;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i] = rand();
    }
    start = clock();
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j = i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    end = clock();
    totaltime = (double)(end-start)/CLOCKS_PER_SEC;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nTime taken = %lf",totaltime);
}



//Merge_Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
int n=0;
int main()
{
    int i;
    clock_t start,end;
    double totaltime;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i] = rand();
    }
    start = clock();
	
		
	mergesort(a,0,n-1);
	
	end = clock();
	
	printf("\nSorted array is :");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	totaltime = (double)(end-start)/CLOCKS_PER_SEC;
    
    printf("\nTime taken = %lf",totaltime);
	return 0;
}
 
void mergesort(int a[],int i,int j)
{
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		
		mergesort(a,mid+1,j);	
		merge(a,i,mid,mid+1,j);	
	}
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[n];	
	int i,j,k;
	i=i1;	
	j=i2;	
	k=0;
	
	while(i<=j1 && j<=j2)	
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=j1)	
		temp[k++]=a[i++];
		
	while(j<=j2)	
		temp[k++]=a[j++];
		
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}



//Quick_Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
void quick_sort(int[],int,int);
int partition(int[],int,int);
 
int main()
{
	int n,i;
	clock_t start,end;
	double totaltime;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int a[n];
	
	for(i=0;i<n;i++)
		a[i] = rand();
	start = clock();
		
	quick_sort(a,0,n-1);
	end = clock();
	
	printf("\nSorted array is :");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	totaltime = (double)(end-start)/CLOCKS_PER_SEC;
    
    printf("\nTime taken = %lf",totaltime);
	return 0;
	
	return 0;		
}
 
void quick_sort(int a[],int low,int high)
{
	int pos;
	if(low<high)
	{
		pos=partition(a,low,high);
		quick_sort(a,low,pos-1);
		quick_sort(a,pos+1,high);
	}
}
 
int partition(int a[],int low,int high)
{
	int key,i,j,temp,k;
    key=a[low];
	i=low+1;
	j=high;
	
	while(i<=j)
	{
	    while(i<=j&&key>=a[i])
	            i = i+1;
	        while(key<a[j])
	            j = j-1;
	        if(i<j)
	        {
	            temp = a[i];
	            a[i] = a[j];
	            a[j] = temp;
	        }
	        else
	        {
	            k = a[j];
	            a[j] = a[low];
	            a[low] = k;
	        }
    }
	return j;
}



//BFS
#include<stdio.h>
void BFS(int[20][20],int,int[20],int);

int main()
{
  int n,a[20][20],i,j,visited[20],source;
  printf("enter number of vertices:");
  scanf("%d",&n);

  printf("\nenter adjacency matrix\n");
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     scanf("%d",&a[i][j]);

  for(i=1;i<=n;i++)
  visited[i]=0;

  printf("\nEnter the source node:");
  scanf("%d",&source);
  visited[source]=1;

  BFS(a,source,visited,n);

  for(i=1;i<=n;i++)
  {
    if(visited[i]!=0)
      printf("\nnode %d is reachable",i);
    else
      printf("\nnode %d is not reachable",i);
  }

}
void BFS(int a[20][20], int source, int visited[20], int n)
{
  int queue[20],f,r,u,v;
  f=0;r=-1;
  queue[++r]=source;
  while(f<=r)
  {
   u=queue[f++];
   for(v=1;v<=n;v++)
   {
      if(a[u][v]==1&&visited[v]==0)
      {
	queue[++r]=v;
	visited[v]=1;
      }
    }
  }
}



//Horsepool_algorithm_for_string_matching
#include<stdio.h>
#include<string.h>
#define MAX 500
int t[MAX];
void shifttable(char p[]) 
{
	int i,j,m;
	m=strlen(p);
	for (i=0;i<MAX;i++)
	  t[i]=m;
	for (j=0;j<m-1;j++)
	  t[p[j]]=m-1-j;
}
int horspool(char src[],char p[]) 
{
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	printf("\nLength of text=%d",n);
	printf("\nLength of pattern=%d",m);
	i=m-1;
	while(i<n) 
	{
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
		   k++;
		if(k==m)
		   return(i-m+1); else
		   i+=t[src[i]];
	}
	return -1;
}
int main() 
{
	char src[100],p[100];
	int pos;
	printf("Enter the text in which pattern is to be searched:\n");
	gets(src);
	printf("Enter the pattern to be searched:\n");
	gets(p);
	shifttable(p);
	pos=horspool(src,p);
	if(pos>=0)
	  printf("\nThe desired pattern was found starting from position %d",pos+1); else
	  printf("\nThe pattern was not found in the given text\n");
}


//Warshall's Algorithm
# include <stdio.h>

int n,a[10][10],p[10][10];

void path()
{
    int i,j,k;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    p[i][j]=a[i][j];
    for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(p[i][k]==1&&p[k][j]==1) p[i][j]=1;
}

int main()
{
    int i,j;
    
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    path();
    printf("\nThe path matrix is showm below\n");
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    printf("%d ",p[i][j]);
    printf("\n");
    }

}



