//WAP implement circular singly linked list
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
		printf("\n\nCIRCULAR SINGLEY LINKED LIST:\n1:Insert_at_Begin\n2:Insert_at_End\n3:Insert_at_Location\n4:Delete_at_Begin\n5:Delete_at_End\n6:Delete_at_location\n7:Traverse(Display)\n8:Exit\nEnter Your Choice:");
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
struct node *start;
struct node
{
	int info;
	struct node *link;
};



void insert_at_begin()
{
	int e;
	struct node *fresh,*ptr;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOver flow\n");
	}
	else
	{
			printf("\nEnter the element to insert at Begin:");
		scanf("%d",&e);
		
		fresh->info=e;
		fresh->link=NULL;
		
		if(start==NULL)
		{
		 	fresh->link = start; // Points to itself in circular list
       		start = fresh; // Set start to the new node
		}
		else
		{
			for(ptr=start;ptr->link!=start;ptr=ptr->link)
			fresh->link=start;
			ptr->link=fresh;
			start=fresh;
		}
	}	
    printf("\n%d inserted at the beginning.\n", e);
}



void insert_at_end()
{
	int e;
	struct node *fresh,*ptr;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverflow Condition\n");
	}
	else
	{
		printf("\nEnter the element to insert at End:\n");
		scanf("%d",&e);
		fresh->info=e;
		fresh->link=start;
		if(start==NULL)
		{
			start=fresh;
		}
		else
		{
			ptr=start;
			for(ptr=start;ptr->link!=start;ptr=ptr->link);
			ptr->link=fresh;
			fresh->link=start;
		}
	}
	 printf("\n%d inserted at the end.\n", e);
}

void insert_at_loc()
{
	int i,e,loc;
	struct node *fresh,*ptr,*prev;
	fresh=(struct node *)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverflow Exist\n");
		return;
	}
	else
	{
		printf("\nEnter the element and position");
		scanf("%d%d",&e,&loc);
		fresh->info=e;
		fresh->link=NULL;
	}
	if(loc==1)
	{
		fresh->link = start;
		if(start==NULL)
		{
			start=fresh;
			fresh->link=fresh;
		}
		else
		{
			ptr=start;
			while (ptr->link!=start)
			{
				ptr=ptr->link;	
			}
			fresh->link=start;
			ptr->link=fresh;
			start=fresh;
		}
	}
	else
	{

		ptr=start;
		while(i<loc-1 && ptr->link!=start)
		{
			ptr=ptr->link;
			i++;
		}
		if(i == loc -1)
		{
			fresh->link=ptr->link;
			ptr->link=fresh;
		}
		else
		{
			printf("\nLocation doesn't exist\n");
			free(fresh);
		}
	}
}

void delete_at_begin()
{
	struct node *ptr,*ptr1;
	if(start==NULL)
	{
		printf("\nUnder flow !! List is Empty\n");
	}
	else
	{
		ptr=start;
		if(start->link==start)
		start=NULL;
	else
	{
		for(ptr1=start;ptr1->link!=start;ptr=ptr->link);
		start=start->link;
		ptr->link=start;
	}
	printf("\n%d is Deleted\n");
	free(ptr);
	}
}

void delete_at_end()
{
    struct node *ptr, *prev;
    if (start == NULL)
    {
        printf("\nUnderflow! List is Empty.\n");
        return;
    }

    ptr = start;
    if (start->link == start) // only one node
    {
        start = NULL;
    }
    else
    {
        while (ptr->link != start) // traverse to last node
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = start; // second-last node points to start
    }

    printf("\n%d is Deleted\n", ptr->info);
    free(ptr);
}

void delete_at_loc()
{
    int loc, i = 1;
    struct node *ptr, *prev;
    if (start == NULL)
    {
        printf("\nUnderflow! List is Empty.\n");
        return;
    }

    printf("\nEnter the location: ");
    scanf("%d", &loc);

    if (loc == 1)
    {
        delete_at_begin();
    }
    else
    {
        ptr = start;
        while (i < loc && ptr->link != start)
        {
            prev = ptr;
            ptr = ptr->link;
            i++;
        }

        if (i == loc)
        {
            prev->link = ptr->link;
            printf("\n%d is Deleted\n", ptr->info);
            free(ptr);
        }
        else
        {
            printf("\nLocation doesn't exist.\n");
        }
    }
}

void traverse()
{
	struct node *ptr;
	if(start==NULL)
	printf("\nList doesn't Exist");
	else
	{
		printf("The elements of linked list are:\n");
		for(ptr=start;ptr->link!=start;ptr=ptr->link)
		printf("%d\t",ptr->info);
		printf("%d",ptr->info);
	}
	
}
