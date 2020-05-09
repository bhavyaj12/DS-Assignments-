#include<stdio.h>
#include<stdlib.h>

void compare(int a[][10],int b[][10],int r1,int c1,int r2,int c2)
{
	int i,j,k,l;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			for(k=0;k<r2;k++)
			for(l=0;l<c2;l++)
			{
				if(a[i][j]==b[k][l])
				printf("\n%d row, %d column in first matrix and %d row, %d column in second matrix have same value",i+1,j+1,k+1,l+1);
			}
		}
	}
}
void main()
{
	int a[10][10],b[10][10],i,j,r1,c1,r2,c2;
	printf("Enter the size of the two matrices:");
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	printf("\nEnter the two matrices:\n");
	for(i=0;i<r1;i++)
	for(j=0;j<c1;j++)
	scanf("%d",&a[i][j]);
	printf("\n");
	for(i=0;i<r2;i++)
	for(j=0;j<c2;j++)
	scanf("%d",&b[i][j]);
	compare(a,b,r1,c1,r2,c2);
	
}
