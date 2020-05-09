#include<stdio.h>
void ppair(int a[50],int n)
{
   int i,j;
   for(i=0;i<n;i++)
   {
   	 for(j=i+1;j<n;j++)
   	 {
   	 	if((a[i]+a[j])==0)
   	 	printf("%d,%d ",a[i],a[j]);
	 }
   }	
}
void main()
{
	int i,n,a[50];
	printf("Enter the size: ");scanf("%d",&n);
	printf("Enter the array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	ppair(a,n);
}
