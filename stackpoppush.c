//perform all stack operation.push,pop and traverse
#include<stdio.h>
#define size 10
int stack[size],top =-1;
void push();
void pop();
void traverse();
int main()
{
	
    int choice;
    do
    {
     printf("\n1:push(insert):\n2:pop(delete):\n3:traverse(display):\n4:exit\n");
     printf("\nEnter your choice:\n");
     scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:traverse();
                break;
            case 4:break;
        default: printf("Invalid choice\n");
        }
    } while(choice !=4);
}

//push operation

    void push()
    {
        int element;
        if(top == size-1)
        {
            printf("\nOverflow !! stack is full\n");
        }
        else
		{
            printf("\nEnter the elements to insert:\n");
            scanf("%d",&element);
            top++;
            stack[top] = element;
            printf("Element is %d insert(pushed)\n",element);
        }
    }

//pop operation

    void pop()
 {
    if(top == -1)
    {
        printf("\nUnderflow !! stack is empty\n");
    }
    else
	{
        printf("\nThe deleted element is %d\n",stack[top]);
        top--;
		printf("\nElement is delete(poped)\n");    
	}
}
//traverse operation
    void traverse()
    {
        int i;
        if(top == -1)
        {
            printf("stack is empty\n");
        }
        else
        {
            printf("The element of stack are\n");
            for(i=0;i<=top;i++)
            {
            	    printf("%d\t",stack[i]);
			}
        
        }
    }


