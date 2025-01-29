#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node cqueue;

cqueue *front=NULL;
cqueue *rear=NULL;

void enqueue(int e)
{
	cqueue *t;
	t= (cqueue *)malloc(sizeof(cqueue));
	t->data=e;
	
	if(front == NULL)
	{
		front = t;
		rear = front;
	}
	else
	{
		rear->next = t;
		rear = rear->next  ;
	}
	rear->next =front;
}

void dequeue()
{
	if(front==NULL)
		printf("Queue Empty\n");
	else
	{
		printf(" Deleted element is:%d\n",front->data);
		
		if(front == front->next)
		{
				rear=NULL;
				front=NULL;
		}
		else
		{
			front = front->next;
			rear->next =front;	
			}	
    } 
}


void display()
{
	if(front==NULL)
		printf("Empty Queue\n");
	else
	{
		cqueue *t=front;
	  do{
            printf("%d\t",t->data);
            t=t->next;
        }while (t!=front);
    }
	}


int menu()
{
    int ch;
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    return ch;
}

void main()
{
    int ch,a;
    for(ch = menu();ch != 4;ch = menu())
    {
        switch(ch)
        {
            case 1 : printf("Enter an element to insert : ");
            		 scanf("%d",&a);
					 enqueue(a);
                     break;
            case 2 : dequeue();
                     break;
            case 3 : display();
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
    }
}


