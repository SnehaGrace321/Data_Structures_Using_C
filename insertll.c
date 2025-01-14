#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;

};

typedef struct node list;
list* head=NULL;

list *createnode(int data)
{
	list * newnode=(list*)malloc(sizeof(list));
	newnode->data=data;
	newnode->next=NULL;	
	return newnode;
}

void insertbegin(int data)
{
	list * newnode=createnode(data);
	newnode->next=head;
	head=newnode;	
}


void insertend(int data)
{
	list * newnode=createnode(data);
	if(head==NULL)
	{
			head=newnode;
	}
	else
	{
		list * t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=newnode;
	}
}



void insertafterelement(int data,int element)
{
	list * newnode=createnode(data);
	list * t=head;
	while(t!=NULL && t->data!=element)
	{
		t=t->next;
	}
	if(t==NULL)
	{
		printf("ELEMENT NOT FOUND");
		return;
	}
	newnode->next=t->next;
	t->next=newnode;
}



void display()
{
	list * t=head;
	if(head==NULL)
	{
		printf("EMPTY LIST");
		return;
	}
	else
	{
			while(t!=NULL)
			{
				printf("%d->",t->data);
				t=t->next;
			}
			printf("NULL");
	}
}

void menu()
{
	int choice,value,element;
	while(1)
	{
		printf("\n1.INSERT AT BEGINING\n2.INSERT AT END\n3.INSERT AFTER ELEMENT\n4.DISPLAY\n5.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("Enter value to insert:");
			       scanf("%d",&value);
			       insertbegin(value);
			       break;
			case 2:printf("Enter value to insert:");
			       scanf("%d",&value);
			       insertend(value);
			       break;
			case 3:printf("Enter value to insert:");
			       scanf("%d",&value);
			       printf("Enter the element after which you wat to insert:");
			       scanf("%d",&element);
			       insertafterelement(value,element);
			       break;
			case 4:printf("LINKED LIST IS:\n");
			       display();
			       break;
			case 5:exit(0);
			       break;
		    default:printf("INVALID INPUT....................TRY AGAIN");
		}
	}
}



int main()
{
	menu();
	return 0;
}

