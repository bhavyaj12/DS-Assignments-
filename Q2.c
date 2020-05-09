#include<stdio.h>
void sumcmp(int a[][10],int s)
{
	int ads=0,bds=0,ds=0;
	int i,j;
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			if(j>i)
			ads+=a[i][j];
			if(j<i)
			bds+=a[i][j];
			if(i==j)
			ds+=a[i][j];
		}
	}
	if((ads+bds)==ds)
	printf("Sum is equal");
	else
	printf("Sum is not equal");
	
}

void main()
{
	int a[10][10],i,j,s;
	printf("Enter the size of the square matrix:");
	scanf("%d",&s);
	printf("\nEnter the matrix:\n");
	for(i=0;i<s;i++)
	for(j=0;j<s;j++)
	scanf("%d",&a[i][j]);
	sumcmp(a,s);
	
}
