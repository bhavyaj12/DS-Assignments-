#include<stdio.h>
void merge(int a[],int b[],int c[],int n1,int n2,int n3)
{
	int i,j,k,l,d[60];
	i=j=k=l=0;
	while(i<n1 && j<n2 && j<n3)
	{
		int m=a[i]<b[j]?(a[i]<c[k]?a[i]:c[k]):(b[j]<c[k]?b[j]:c[k]);
		d[l++]=m;
		if(m==a[i])
		i++;
		else if(m==b[j])
		j++;
		else 
		k++;
	}
	while (i<n1&&j<n2) 
	{ 
        if (a[i]<=b[j]) 
		{ 
            d[l++]=a[i]; 
            i++; 
        } 
        else 
		{ 
            d[l++]=b[j]; 
            j++; 
        } 
    } 
    while (i<n1&&k<n3) 
	{ 
        if (a[i]<=c[k]) 
		{ 
            d[l++]=a[i]; 
            i++; 
        } 
        else 
		{ 
            d[l++]=c[k]; 
            k++; 
        } 
    } 
    while (k<n3&&j<n2) 
	{ 
        if (c[k]<=b[j]) 
		{ 
            d[l++]=c[k]; 
            k++; 
        } 
        else 
		{ 
            d[l++]=b[j]; 
            j++; 
        } 
    } 
    while (k<n3) 
        d[l++]=c[k++]; 
  
    while (i<n1) 
        d[l++]=a[i++]; 
  
    while (j<n2) 
        d[l++]=b[j++];
		
	printf("Merged ascending array given 3 ascending arrays is:\n");
	for(i=0;i<n1+n2+n3;i++)
	printf("%d ",d[i]);
}

void main()
{
	int a[20],b[20],c[20],n1,n2,n3,i;
	printf("Enter the size of the 3 arrays: ");
	scanf("%d %d %d",&n1,&n2,&n3);
	printf("Enter the first sorted array: ");
	for(i=0;i<n1;i++)
	scanf("%d",&a[i]);
	printf("\nEnter the second sorted array: ");
	for(i=0;i<n1;i++)
	scanf("%d",&b[i]);
	printf("\nEnter the third sorted array: ");
	for(i=0;i<n1;i++)
	scanf("%d",&c[i]);
	merge(a,b,c,n1,n2,n3);
	
}
