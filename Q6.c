#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct stud
{
	char name[20];
	int rno;
	float gpa;
	struct stud *next;
};
struct stud *START=NULL;

void display(struct stud *START)
{
	struct stud *ptr;
	ptr=START;
	while(ptr!=NULL)
	{
		printf("%s %d %f \n",ptr->name,ptr->rno,ptr->gpa);
		ptr=ptr->next;
	}
}

struct stud *atend(struct stud *START)
{
    struct stud *nn;
	nn=(struct stud*)malloc(sizeof(struct stud));
	if(nn == NULL)
    printf("\nFailed to Allocate Memory");
	nn->next=NULL;
	int regno;char nm[20];float cgpa;
	printf("Enter the name, rno and cgpa\n");
	scanf("%s %d %f",&nm,&regno,&cgpa);
	strcpy(nn->name,nm);
	nn->rno=regno;
	nn->gpa=cgpa;
    if(START==NULL)
    START=nn;
   	else
	{
	struct stud *ptr=START;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	nn->next=NULL;
	ptr->next=nn;
	}
	return START;
}

struct stud *sort(struct stud *START)
{
	struct stud *p1,*p2;
	char nt[20];int rt;float gt;
	p1=START;
	while(p1->next!=NULL)
	{
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->rno>p2->rno)
			{
				strcpy(nt,p1->name);
				strcpy(p1->name,p2->name);
				strcpy(p2->name,nt);
				rt=p1->rno;
				p1->rno=p2->rno;
				p2->rno=rt;
				gt=p1->gpa;
				p1->gpa=p2->gpa;
				p2->gpa=gt;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	return START;
}


void main()
{
	int val,ch=1;
	do
	{
	
		START= atend(START);
		printf("\nTo insert more press 1: ");
		scanf("%d", &ch);
	}
	while(ch==1);
	printf("Unsorted records:\n");
	display(START);
	sort(START);
	printf("\nSorted records:\n");
	display(START);
	free (START);
	
}



