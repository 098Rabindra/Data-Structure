//WAP to implement circular queue
#include<stdio.h>
#define size 10
int queue[size];
int rear = -1;
int front = -1;
void insert();
void delete();
void display();
int main()
{
	int ch;
	do
	{
	printf("\nCIRCULAR QUEUE\n1:Insert\n2:Delete\n3:Display\n4:Exit\nEnter your Choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert();
		break;
		case 2:delete();
		break;
		case 3:display();
		break;
		case 4:exit(0);
		break;
		default:
			printf("Invalid choice\n");
	}		
  }while(ch!=4);
}

void insert()
{
	int e;
	if(front==(rear+1)%size)
	{
		printf("Overflow\n");
	}
	else
	{
		printf("\nEnter the element insert:");
		scanf("%d",&e);
		if(front==-1)
		{
			front++;
		}
		rear=(rear+1)%size;
		queue[rear]=e;
		printf("%d is INSERTED\n",queue[rear]);
		
	}
}
void delete()
{
	if(front==-1)
	{
		printf("\nUnderflow !! Queue is Empty\n");
	}
	else
	{
		printf("The deleted element is %d\n",queue[front]);
		if(front==rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front=(front+1)%size;
		}
	}
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("\nUnderflow ^^ QUEUE is Empty\n");
	}
	else
	{
		printf("\nThe element of the queue are:\n");
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d\t",queue[i]);			
			}
		}
		else
		{
			for(i=front;i<=size;i++)
			printf("%d\t",queue[i]);
			for(i=0;i<=rear;i++)
			printf("%d\t",queue[i]);
		}
	}
}
