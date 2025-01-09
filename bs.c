#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[20],i,j,temp,si,fi,mi,n,s;
	printf("enter the no of elememts:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	printf("Sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
	
	 printf("\nEnter the element to search:");
	 scanf("%d",&s);
	si=0;
	fi=n-1;
	
	while(si<=fi)
	{
		mi=(si+fi)/2;
		if(a[mi]==s)
		{
			printf("Element found at index %d",mi);
			break;
		}
		else if(a[mi]<s)
		{
			si=mi+1;	
		}
		else
		{
			fi=mi-1;
		}
		
	}
	if(si>fi)
	{
		printf("Element not found");
	}
	
}
