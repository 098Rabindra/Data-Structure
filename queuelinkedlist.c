//WAP to implement Queue using Linkedlist
#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int main()
{
	int ch;
	do
	{
		printf("Enter your choice:\n1:Enqueue\n2:Deqeue\n3:Display\n4:Exit\n");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			enqueue();
		break;
		case 2:
			dequeue();
		break;
		case 3:
		 	display();
		break;
		case 4:
			exit(0);
		break;
		default:
		printf("Invalid Choice");	
	}	
}while(ch!=4);
}

struct node
{
	int info;
	struct node *link;
};

struct node *front,*rear;

void enqueue()
{
	struct node *fresh;
	int e;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverFlow");
		return;
	}
	else
	{
		printf("\nEnter the element to insert:");
		scanf("%d",&e);
		fresh->info=e;
		fresh->link=NULL;
		if(front==0 && rear==0)
		{
			front=rear=fresh;
		}
		else
		{
			rear->link = fresh;
			rear = fresh;
		}	
		printf("%d is INSERTED\n",fresh->info);
	}
}

void dequeue()
{
	struct node *ptr;
	if(front==NULL)
	{
		printf("\nUnderflow !! Queue is Empty\n");
		return;
	}
	else
	{
	ptr = front;
	printf("\nThe deleted element is %d\n",ptr->info);
	if(front==rear)
	front=rear=NULL;
	else
	front=front->link;
	free(ptr);	
	}
}
void display()
{
	struct node *ptr;
	if(front==NULL)
	{
		printf("\n!!!Queue is Empty!!!\n");
	}
	else
	{
		printf("\nThe elements of the queue are:\n");
		for(ptr=front;ptr!=NULL;ptr=ptr->link)
		printf("%d\t",ptr->info);
	}
printf("\n");	
}
