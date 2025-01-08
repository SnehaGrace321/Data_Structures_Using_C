#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node {
	int data;
	struct node* next;
}; 
struct node * head =NULL;

void insert(int a)
{
	struct node*t =head;
	
	if (head==NULL)
	{
		head=(struct node*)malloc(sizeof (struct node));
		head->data=a;
		head->next=NULL;
	}
	else
	{
		for(t=head;t->next!=NULL;t=t->next);
		t->next=(struct node*)malloc(sizeof(struct node));
		t->next->data=a;
		t->next->next=NULL;

	}
	
}

void display()
{
	struct node *t = head;
	if(head==NULL)
	{
		printf("empty list");
	}
	else
	{
			for(t=head;t!=NULL;t=t->next)
			{
				printf("%d\t",t->data);	
			}

    }
	
}

void deletee(int a)
{
	struct node *t ;
	if(head==NULL)
	{
		printf("no elemnts to delete");
		
	}
    else if(head->data==a)
    {
    	head=head->next;
	}
	else
	{
		t=head;
		while(t->next!=NULL&& t->next->data!=a)
		{
			t=t->next;
		}

		    if(t->next==NULL)
		    {
		    	printf("not found");
			}
			else
			{
				t->next=t->next->next;
			}
	}

}

void menu()
{
	int ch,elemnt;
	while(1)
	{
		printf("\n1.insert\n2.delete\n3.dispaly\n4.exit");
		printf("\n enter choice");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:printf("enter element to insert");
			      scanf("%d",&elemnt);
			      insert(elemnt);
			      break;
		    case 2:printf("enter elemect to delete");
			      scanf("%d",&elemnt);
			      deletee(elemnt);
			      break;
			case 3:display();
		        	break;
			case 4:break;
			default: printf("invalid input");
				
		}
		
	}
}

int main()
{
menu();
return 0;
	
}
