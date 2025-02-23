//WAP implement of Doubly linked list
#include<stdio.h>
#include<stdlib.h>
void insert_at_begin();
void insert_at_end();
void insert_at_loc();
void delete_at_begin();
void delete_at_end();
void delete_at_loc(); 
void reverse();
void traverse();
void main()
{
	int ch;
	do
	{
		printf("\nDOUBLY LINKED LIST:\n1:Insert_at_Begin\n2:Insert_at_End\n3:Insert_at_Location\n4:Delete_at_Begin\n5:Delete_at_End\n6:Delete_at_location\n7:Traverse(Display)\n8:Reverse\n9:Exit\nEnter Your Choice:");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert_at_begin();
			break;
		case 2:insert_at_end();
			break;
		case 3:insert_at_loc();
			break;
		case 4:delete_at_begin();
			break;
		case 5:delete_at_end();
			break;
		case 6:delete_at_loc();
			break;
		case 7:traverse();
			break;
		case 8:reverse();
			break;
		case 9:exit(0);
			break;
		default:
			printf("\nInvalid Choice\n");
    	}		
	}while(ch!=8);	
}
struct node *start=NULL;
struct node
{
	int info;
	struct node *prev,*link;
};


//doubly linked list insertion at begin
void insert_at_begin()
{
	int e;
	struct node *fresh,*ptr,*prev;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	printf("\nOverflow Condition");
	else
	{
		printf("\nEnter the element to insert:");
		scanf("%d",&e);
		fresh->info=e;
		fresh->link=NULL;
		if(start==NULL)
		start=fresh;
	else
	{
		start->prev=fresh;
		fresh->link=start;
		start=fresh;
	}
	printf("\n%d is Inserted\n",e);
  }	
}

//doubly linked list insertion at end
void insert_at_end()
{
	int e;
	struct node *fresh,*ptr;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
	 printf("\nOverflow Exist");
	 return;
	}
	printf("\nEnter the element to insert at end:");
	scanf("%d",&e);
	fresh->info=e;
	fresh->link=NULL;
	if(start==NULL)
	start=fresh;
	else
	{
		for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
		ptr->link=fresh;
		fresh->prev=ptr;
	}
	printf("\n%d is Inserted\n",e);
}


//doubly linked list insertion of location
void insert_at_loc()
{
	int e,loc,i;
	struct node *fresh,*prev,*ptr;
	fresh=(struct node *)malloc(sizeof(struct node));
	if(fresh==NULL)
	printf("\nOverflow Condition");
	else
	{
		printf("\nEnter the element:");
		scanf("%d",&e);
		printf("Enter the position:");
		scanf("%d",&loc);
		fresh->info=e;
		fresh->link=NULL;
		fresh->prev=NULL;
	}
	if(start==NULL)
	printf("\nList doesn't Exist");
	else
	{
		i=1;
		ptr=start;
	while(i<loc && ptr!=NULL)
	{
		ptr=ptr->link;
		i++;
	}
	if(ptr==NULL)
	{
		printf("\nLocation doesnot Exist");
		return;
	}
	else if(ptr==start)
	{
		fresh->link=start;
		start->prev=fresh;
		start=fresh;
	}
	else
	{
		fresh->link=ptr;
		fresh->prev=ptr->prev;
		ptr->prev->link=fresh;
		ptr->prev=fresh;
	}
	printf("\n%d is inserted\n",e);
}
	
}


void traverse()
{
	int i;
	struct node *ptr;
	if(start==NULL)
	printf("List Doesnot Exist\n\n");
	else
	{
		printf("\nThe eleemnts of Linked list are:\n");
		for(ptr=start;ptr!=NULL;ptr=ptr->link)
		printf("%d\t",ptr->info);
	}
	printf("\n");
}

//Doubly linked list delete at begin
void delete_at_begin()
{
	struct node *ptr;
	if(start==NULL)
	printf("\nUnderflow !! List is Empty");
	else
	{
		ptr=start;
		if(start->link==NULL)
		start=NULL;
	else
		start=start->link;
		printf("\n%d is Deleted\n",ptr->info);
		free(ptr);
	}
}

//Doubly linked list Delete at end
void delete_at_end()
{
    struct node *ptr, *prev;
    
    if (start == NULL)
    {
        printf("\nUnderflow !! List is Empty");
    }
    else
    {
        if (start->link == NULL)  // Check if the list has only one node
        {
            printf("\n%d is Deleted\n", start->info);
            free(start);
            start = NULL;
        }
        else
        {
            ptr = start;
            // Traverse to the last node
            while (ptr->link != NULL)
            {
                ptr = ptr->link;
            }
            // Adjust the previous node's link to NULL (removing the last node)
            ptr->prev->link = NULL;
            printf("%d is Deleted\n", ptr->info);
            free(ptr);  // Free the last node
        }
    }
}

//Doubly linked list Delete at location
void delete_at_loc()
{
	int loc,i=1;
	struct node *prev,*ptr;
	if(start==NULL)
	printf("\nUnderflow !! List is Empty\n");
	else
	{
		printf("\nEnter the loaction:");
		scanf("%d",&loc);
		ptr=start;
		while(i<loc && ptr!=NULL)
		{
			ptr=ptr->link;
			i++;
		}
		if(ptr==NULL)
		printf("\nLOcation Doesnot exist");
		else if(ptr==start)
		{
			if(start->link==NULL)
			{
				free(start);
				start=NULL;	
			}
			
			else
			{
				start=start->link;
				start=prev=NULL;
				free(ptr);
			}
		}
		else if(ptr->link==NULL) //deleting the last node
		{
			//ptr->prev->link=NULL
			prev = ptr->prev;
			prev->link=NULL;
			free(ptr);
		}
		
		else  //deletind the middle node
		{
			ptr->link->prev=ptr->prev;
			ptr->prev->link=ptr->link;
		}
		printf("\n%d is Deleted\n",ptr->info);
		free(ptr);
	}
}



// Reverse doubly linked list
void reverse() {
    struct node *ptr = start, *temp;

    if (start == NULL) {
        printf("\nList is Empty\n");
        return;  // If the list is empty, return immediately
    } 

    // Reverse the links of the nodes
    while (ptr != NULL) {
        temp = ptr->link;  // Store next node
        ptr->link = ptr->prev;  // Reverse the link
        ptr->prev = temp;  // Reverse the previous link
        ptr = ptr->prev;  // Move to the next node (which is now the previous node)
    }

    // Adjust the start pointer to point to the new first node (which was the last node)
    temp = start;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }
    start = temp;  // Set the new start node

    // Print the reversed list
    printf("\nThe reversed Linked list is:\n");
    ptr = start;
    while (ptr != NULL) {
        printf("%d\t", ptr->info);  // Print node info
        ptr = ptr->link;  // Move to next node
    }
}

