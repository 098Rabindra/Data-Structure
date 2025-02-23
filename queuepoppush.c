//Write a c program for implemntion linear queue
#include<stdio.h>
#define size 10
int queue[size];
int front = -1;
int rear = -1;
void insert();
void delete();
void traverse();
int main()
{
	
    int choice;
        printf("1:Insert:\n2:Delete:\n3:traverse(display):\n4:exit\n");
    do
    {
     printf("\nEnter your choice:\n");
     scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
                break;
            case 2:delete();
                break;
            case 3:traverse();
                break;
            case 4:break;
        default: printf("Invalid choice\n");
        }
    } while(choice !=4);
    return 0;
}
/*
{
	int choice;
	do
	{
		printf("\nEnter a choice:\n1:insert\n2:delete\n3:traverse\n4:exit\n");
		scanf("%d",&choice);
	
	switch(choice)
	{
		case 1: insert();
				break;
		case 2: delete();
				break;
		case 3: traverse();
				break;
		case 4: break;
		default:
			printf("\nInvalid input");
	}
	}
	while(choice !=4);
	
}
*/
void insert()
{
	int element;
	if(rear == size - 1)
	{
		printf("\noverflow !! queue is full\n");
	}
	else
	{
		printf("\nEnter the element to insert\n");
		scanf("%d",&element);
			if(front == -1)
			{
				front++;
			}
			rear++;
			queue[rear] = element;
	}
}
void delete()
{
	if(front == -1)
	{
		printf("\nunderflow !! queue is empty\n");
	}
	else
	{
		printf("\nThe deleted element is %d\n",queue[front]);
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front ++;
		}
	}
}

void traverse()
{
	int i;
	if(front == -1)
	{
		printf("\nQueue is empty\n");
	}
	else
	{
		printf("\nThe element of queue are\n");
		for(i=front; i<=rear; i++)
		printf("%d\t",queue[i]);
	}
	queue[front];
}

