//stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int main()
{
	int ch;
	do
	{
		printf("Enter your choice\n1.push\n2.pop\n3.display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
			default:
			printf("\ninvalid choice\n");
		}
	}while(ch!=4);
}
struct node
{
	int info;
	struct node *link;
};
struct node *top;

void push()
{
	struct node *fresh;
	int e;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh == NULL)
	{
		printf("\noverflow!!!\n");
		return;
	}
	else
	{
		printf("\nenter the element to insert:");
		scanf("%d",&e);
		fresh->info=e;
		fresh->link=NULL;
		if(top == NULL)
		top=fresh;
		else
		{
			fresh->link=top;
			top=fresh;
		}
	}
}
void pop()
{
	struct node *ptr;
	if(top == NULL)
	printf("\nunderflow!!list is empty");
	else
	{
		ptr=top;
		top=top->link;
		printf("\nThe deleted element is %d\n",ptr->info);
		free(ptr);
	}
}

void display()
{
	int i;
	struct node *ptr;
	if(top==NULL)
	printf("\nstack is empty");
	else
	{
		printf("\nThe elements of the stack are:\n");
		for(ptr=top;ptr!=NULL;ptr=ptr->link)
		printf("%d\t",ptr->info);
	}
	printf("\n");
}
