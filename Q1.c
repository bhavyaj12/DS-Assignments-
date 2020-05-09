#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct date
{
	int d,m,y;
};

struct node
{
	int sno;
	char name[20];
	struct date dat;
	struct node *next;
};
struct node *S1=NULL,*S2=NULL;

struct node *create(struct node *START)
{
    struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	if(nn == NULL)
    printf("nFailed to Allocate Memory");
	nn->next=NULL;
	int no;char nm[20];int dd,mm,yy;
	printf("Enter the sno, name and registration date(dd mm yyyy)\n");
	scanf("%d %s %d %d %d",&no,&nm,&dd,&mm,&yy);
	strcpy(nn->name,nm);
	nn->sno=no;
	nn->dat.d=dd;nn->dat.m=mm;nn->dat.y=yy;
    if(START==NULL)
    START=nn;
   	else
	{
	struct node *ptr=START;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	nn->next=NULL;
	ptr->next=nn;
	}
	return START;
}

void display(struct node *START)
{
	struct node *ptr;
	ptr=START;
	while(ptr!=NULL)
	{
		printf("%d %s %d/%d/%d \n",ptr->sno,ptr->name,ptr->dat.d,ptr->dat.m,ptr->dat.y);
		ptr=ptr->next;
	}
}

int cmpdate(struct date d2, struct date d1)

{
	if (d1.y>d2.y || d1.y==d2.y && d1.m>d2.m || d1.y==d2.y && d1.m==d2.m && d1.d>d2.d)
	return 1;
	else return 0;
} 

void movenode(struct node **dest,struct node **source) 
{ 
    struct node *nn=*source; 
    *source=nn->next; 
    nn->next=*dest; 
    *dest=nn; 
} 
  
struct node *merge(struct node *a, struct node *b)  
{ 
	struct node *result=NULL; 
	struct node **last=&result;  
    while(1)  
	{ 
	if(a==NULL)  
    { 
      *last=b; 
       break; 
    } 
    else if(b==NULL)  
    { 
       *last=a; 
       break; 
    } 
    if(cmpdate(a->dat,b->dat))  
    { 
      movenode(last,&a); 
    } 
    else 
    { 
      movenode(last,&b); 
    } 
    last=&((*last)->next);  
  } 
  return(result); 
} 

void main()
{
	struct node *res=NULL;
	int ch1=1,ch2=1;
	printf("Enter sorted linked list 1:\n");	
	do
	{
		S1=create(S1);
		printf("\nTo insert more press 1: ");
		scanf("%d", &ch1);
	}while(ch1==1);
	printf("Enter sorted linked list 2:\n");	
	do
	{
		S2= create(S2);
		printf("\nTo insert more press 1: ");
		scanf("%d", &ch2);
	}while(ch2==1);
	printf("Linked list 1:\n");
	display(S1);
	printf("\nLinked list 2:\n");
	display(S2);
	printf("\nMerged records ordered as oldest to newest students:\n");
	res=merge(S1,S2);
	display(res);

}



