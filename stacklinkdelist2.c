//WAP STACK Using Linkedlist
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
		printf("\nSTACK USING LINKED LIST\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
		printf("Enter Your Choice:\n");
		scanf("%d",&ch);
	switch(ch)
		{
			case 1:
				push();
			break;
			case 2:
				pop();
			break;
			case 3:
			     
				display();
			break;
			case 4:exit(0);
			break;
			default:
				printf("Invalid choice");
		}
	}while(ch!=4);
}

struct node
{
  int data;
  struct node *link;
};
struct node *top=0;

void push()
{
  struct node *newnode;
  int x;
  newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode == NULL)
  {
    printf("\nOvertflow\n");
  }
  printf("\nEnter the element to insert:\n");
  scanf("%d",&x);
  newnode->data = x;
  newnode->link = top;
  top = newnode;
  printf("%d is inserted\n",newnode->data);
}

void display()
{
  struct node *temp;
  temp = top;
  if(top == NULL)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("The Stack Using LinkedList is\n");
   while(temp!=NULL)
  {
    printf("%d\t",temp->data);
    temp = temp->link;
  }
  }
}
void pop()
{
  struct node *temp;
  temp = top;
   if(top == NULL)
   {
    printf("UNDERFLOW");
   }
   else
   {
      printf("The pop element is %d",top->data);
      top = top->link;
      free(temp);
   }

}

