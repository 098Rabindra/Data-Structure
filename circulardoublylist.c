//WAP implement of Circular Doubly linked list
#include<stdio.h>
#include<stdlib.h>
void insert_at_begin();
void insert_at_end();
void insert_at_loc();
void delete_at_begin();
void delete_at_end();
void delete_at_loc();
void traverse();
void main()
{
	int ch;
	do
	{
		printf("\nCIRCULAR DOUBLY SINGLEY LINKED LIST:\n1:Insert_at_Begin\n2:Insert_at_End\n3:Insert_at_Location\n4:Delete_at_Begin\n5:Delete_at_End\n6:Delete_at_location\n7:Traverse(Display)\n80:Exit\nEnter Your Choice:");
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
		case 8:exit(0);
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
void insert_at_begin()
{
	int e;
	struct node *fresh,*ptr;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("\nOverflow");
		return;
	}
	printf("Enter the element to insert:\n");
	scanf("%d",&e);
	fresh->info=e;
	fresh->link=NULL;
	if(start==NULL)
	{
		start=fresh;
		fresh->prev=fresh;
		fresh->link=fresh;
	}
	else
	{
		fresh->prev=start->prev;
		fresh->link=start;
		start->prev->link=fresh;
		start->prev=fresh;
		start=fresh;
	}
}
void insert_at_end()
{
	 int i,e;
	 struct node *fresh, *ptr;
	 fresh=(struct node *)malloc(sizeof(struct node));
	 if(fresh == NULL)
	 {
	 	printf("\nOverflow Condition");
	 	return;
	 }
	
	 	printf("\nEnter the Eleemnt to insert to end: ");
	 	scanf("%d",&e);
	 	fresh->info;
	 	fresh->link=NULL;
	 	if(start==NULL)
	 	{
	 		start=fresh;
	 		fresh->prev=fresh;
	 		fresh->link=fresh;
		 }
		 else
		 {
		 	fresh->prev=start->prev;
		 	fresh->link=start;
		 	start->prev->link=fresh;
		 	start->prev=fresh;
		 }
	 
}

void insert_at_loc()
{
	int e,loc,i=1;
	struct node *fresh,*ptr;
	fresh=(struct node *)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverflow condition exist\n");
		return ;
	}
	printf("\nEnter the element : ");
	scanf("%d",&loc);
	printf("\nEnter the position to insert: ");
	scanf("%d",&e);
	fresh->info=e;
	
	
	if(start==NULL)
	{
		if(loc==1)
		{
			start=fresh;
			fresh->link=fresh;
			fresh->link=fresh;
		}
		else
		{
			printf("\nInvaild loctaion\n");
		}
		
		if(loc==-1)
		{
			fresh->prev=start->prev;
			fresh->link=start;
			start->prev->link=fresh;
			start->prev=fresh;
			return;
		}
		ptr=start;
		while(i<loc-1 && ptr->link!=start)
		{
			ptr=ptr->link;
			i++;
		}
		
		if(i==loc-1)
		{
			fresh->link=ptr->link;
			fresh->prev=ptr;
			ptr->link->prev=fresh;
			ptr->link=fresh;
		}
		else
		{
			printf("\nInvalid choice\n");
		}
	}
}

void delete_at_begin()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("\nUnderflow Conditon\n");
		return;
	}
	ptr=start;
	if(start->link==start)
	start=NULL;
	else
	{
		start->link->prev=start->prev;
		start->prev->link=start->link;
		start=start->link;
	}
	printf("\n%d is deleted\n",ptr->info);
}


void delete_at_end()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("\nUnderflow Condition\n");
	}
	else
	{
		ptr=start->prev;
		if(start->link==start)
		start=NULL;
		else
		{
			start->prev=start->prev->prev;
			start->prev->link=start;
		}
		printf("\n%d is Deleted\n",ptr->info);
		free(ptr);
	}
}


void delete_at_loc()
{
	int loc,i=1;
	struct node *ptr;
	if(start==NULL)
	{
		printf("\n Underflow Condition\n");
	}
	else
	{
		printf("\nEnter the location to delete: ");
		scanf("%d",&loc);
		
		if(loc==-1)
		{
			ptr=start;
			if(start->link==start)
			start=NULL;
			else
			{
				start->prev->link=start->link;
				start->link->prev=start->prev;
				start=start->link;
			}
			printf("\n%d is Deleted\n",ptr->info);
			free(ptr);
			return;
		}
		ptr=start;
		while(i<loc && ptr->link!=start)
		{
			ptr=ptr->link;
			i++;
		}
		if(i==loc)
		{
			ptr->prev->link=ptr->link;
			ptr->link->prev=ptr->prev;
			printf("\n%d is Deleted\n",ptr->info);
			free(ptr);
		}
		else
		{
			printf("\nInvaild Choice\n");
		}
	}
}


void traverse()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("\nList doesn't Exist\n'");
	}
	else
	{
		printf("\nThe Elements of linked list are: \n");
		for(ptr=start;ptr->link!=start;ptr=ptr->link)
		printf("%d\t",ptr->info);
		printf("%d\t",ptr->info);
	}
}























