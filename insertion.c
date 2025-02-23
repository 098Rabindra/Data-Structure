#include<stdio.h>
#include<stdlib.h>
void insert_at_begin();
void insert_at_end();
void insert_at_loc();
void insert_bef_item();
void insert_aft_item(); 
void delete_at_begin();
void delete_at_end();
void delete_at_loc();
void delete_bef_item();
void delete_aft_item();   
void traverse();
void search();
void sort();
void reverse();
void main()
{
	int ch;
	do
	{
		printf("\nEnter your choice:\n1. Insert at begin\n2. Insert at end\n3. Insert at location\n"
		"4. Insert before item\n5. Insert after item\n6. Deletion at begin\n7. Deletion at end\n"
		"8. Deletion at location\n9. Deletion before item\n10. Deletion after item\n11. Traverse(Display)\n12. Search\n13. Sort\n"
		"14. Reverse\n15. Exit\n\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	insert_at_begin();
					break;
			case 2: insert_at_end();
					break;
			case 3: insert_at_loc();
					break;
			case 4: insert_bef_item();
					break;
			case 5: insert_aft_item();
					break;
			case 6: delete_at_begin();
					break;
			case 7: delete_at_end();
					break;
			case 8: delete_at_loc();
					break;
			case 9: delete_bef_item();
					break;
			case 10:delete_aft_item();
					break;
			case 11: traverse();
					break;
			case 12: search();
					break;
			case 13: sort();
					break;
			case 14: reverse();
					break;
			case 15: exit(0);
					break;
			default: printf("\nInvalid choice!!!\n");	
		}
	}
	while(ch!=15);
}

struct node *start;
struct node
{
	int info;
	struct node *link;
};

void insert_at_begin()
{
	int elem;
	struct node *fresh;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverflow\n");
		return;
	}
	printf("\nEnter the element to insert: ");
	scanf("%d",&elem);
	fresh->info=elem;
	fresh->link=NULL;
	if(start==NULL)
	{
		start=fresh;
	}
	else
	{
		fresh->link=start;
		start=fresh;
	}
	printf("%d is inserted\n",fresh->info);
}
 
void insert_at_end()
{
	int elem;
	struct node *fresh, *ptr;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverflow condition exist\n");
		return;
	}
	printf("\nEnter the element to insert at end: ");
	scanf("%d",&elem);
	fresh->info=elem;
	fresh->link=NULL;
	if(start==NULL)
	{
		start=fresh;
	}
	else
	{
		for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
		ptr->link=fresh;
	}
		printf("%d is inserted\n",fresh->info);
}

void insert_at_loc()
{
	int elem,loc,i;
	struct node *fresh, *ptr, *prev;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverflow condition exist\n");
		return;
	}
	printf("\nEnter the element and the position : ");
	scanf("%d %d",&elem,&loc);
	fresh->info=elem;
	fresh->link=NULL;
	if(start==NULL)
	{
		printf("\nList doesnot exist\n");
	}
	else
	{
		i=1;
		ptr=start;
		while(i<loc&&ptr!=NULL)
		{
			prev=ptr;
			ptr=ptr->link;
			i++;
		}
		if(ptr==NULL)
		{
			printf("\nLocation doesnot exist\n");
		}
		else if(ptr==start)
		{
			fresh->link=start;
			start=fresh;
		}
		else
		{
			prev->link=fresh;
			fresh->link=ptr;
		}
	}
}

void insert_bef_item()
{
	int elem,item;
	struct node *fresh, *ptr,*prev;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverflow condition exist\n");
		return;
	}
	printf("\nEnter the element and the item you want to insert before it : ");
	scanf("%d %d",&elem,&item);
	fresh->info=elem;
	fresh->link=NULL;
	if(start==NULL)
	{
		printf("\nList doesnot exist\n");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL && ptr->info!=item)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		if(ptr==NULL)
			printf("\nItem doesnot exist\n");
		else if(ptr==start)
		{
			fresh->link=start;
			start=fresh;
		}
		else
		{
			prev->link=fresh;
			fresh->link=ptr;
		}
	}
}

void insert_aft_item()
{
	int elem,item;
	struct node *fresh, *ptr,*prev;
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("\nOverflow condition exist\n");
		return;
	}
	printf("\nEnter the element and the item you want to insert after it : ");
	scanf("%d %d",&elem,&item);
	fresh->info=elem;
	fresh->link=NULL;
	if(start==NULL)
	{
		printf("\nList doesnot exist\n");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL && ptr->info!=item)
		{
			ptr=ptr->link;
		}
		if(ptr==NULL)
			printf("\nItem doesnot exist\n");
		else if(ptr==start)
		{
			fresh->link=start;
			start=fresh;
		}
		else
		{
			fresh->link=ptr->link;
			ptr->link=fresh;
		}   
	}
}


void traverse()
{
	struct node *ptr;
	if(start==NULL)
		printf("\nList doesnot exist\n");
	else
	{
		printf("\nThe elements of linked list are: \n");
		for(ptr=start;ptr!=NULL;ptr=ptr->link)
			printf("%d\t",ptr->info);
	}
}

void delete_at_begin()
{
	struct node *ptr;
	if(start==NULL)  {
		printf("\nUnderflow !! List is empty !!\n");
		return;
	}
	ptr=start;
	start=start->link;
	free(ptr);
}

void delete_at_end()
{
	struct node *ptr,*prev;
	if(start==NULL)   {
		printf("\nUnderflow !! List is empty !!\n");
		return;
	}
	ptr=start;
	while(ptr->link!=NULL)
	{
		prev=ptr;
		ptr=ptr->link;
	}
	prev->link=NULL;
	free(ptr);
}

void delete_at_loc()
{
	int loc,i=1;
	struct node *ptr,*prev;
	if(start==NULL)  {
		printf("\nUnderflow !! List is empty !!\n");
		return;
	}
	printf("Enter the location: ");
	scanf("%d",&loc);
	ptr=start;
	while(i<loc && ptr!=NULL)
	{
		prev=ptr;
		ptr=ptr->link;
		i++;
	}
	if(ptr==NULL)
		printf("\nLocation doesnot exist\n");
	else if(ptr==start)  //when loc is 1
	{
		start=start->link;
		free(ptr);
	}
	else  {      //any other loc
		prev->link=ptr->link;
		free(ptr);
	} 
}

void delete_aft_item()
{
	int item;
	struct node *ptr,*prev;
	if(start==NULL)  {
		printf("\nUnderflow !! List is empty !!\n");
		return;
	}
	printf("\nEnter the item you want to delete after it: ");
	scanf("%d",&item);
	ptr=start;
	while(ptr!=NULL && ptr->info!=item)  {
		prev=ptr;
		ptr=ptr->link;
	}
	if(ptr->link==NULL)
		printf("\nDeletion not possible\n");
	else 
	{
		prev=ptr->link;
		ptr->link=ptr->link->link;
		free(ptr);	
	}
}

void delete_bef_item()
{
	int item;
	struct node *ptr,*prev, *prevPrev;
	if(start==NULL)  {
		printf("\nUnderflow !! List is empty !!\n");
		return;
	}
	printf("\nEnter the item you want to delete before it: ");
	scanf("%d",&item);
	ptr=start;
	while(ptr!=NULL && ptr->info!=item)  {
		prevPrev=prev;
		prev=ptr;
		ptr=ptr->link;
	}

	if(ptr==NULL)
	{
		printf("\nItem is not found in the list\n");
		return;
	}
	if(prevPrev==NULL)
	{
		printf("\nNo node exists before the node\n");
		return;
	}
	prevPrev->link=prev->link;
	free(prev);
}

void search()
{
	int item,i;
	struct node *ptr;
	if(start==NULL)
		printf("\nLinked list doesnot exist\n");
	else
	{
		printf("\nEnter the item to search: ");
		scanf("%d",&item);
		ptr=start;
		while(ptr!=NULL && ptr->info!=item)
		{
			ptr=ptr->link;
			i++;
		}
		if(ptr==NULL)
			printf("\n%d not found\n",item);
		else
			printf("\n%d found at position %d\n",item,i);
	}
}

void sort()
{
	int item,temp,i=1;
	struct node *ptr1, *ptr2;
	if(start==NULL)
		printf("\nLinked list doesnot exist\n");
	else  {
		printf("\nEnter the item to sort: ");
		scanf("%d",&item);
	}
	ptr1=start;
	while(ptr1->link!=NULL)
	{
		ptr2=ptr1->link;
		while(ptr2!=NULL)
		{
			if(ptr1->info > ptr2->info)
			{
				temp=ptr1->info;
				ptr1->info=ptr2->info;
				ptr2->info=temp;
			}
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
	}
}

void reverse()
{
	struct node *ptr1, *ptr2=NULL, *prev=NULL, *temp=NULL;
	ptr1=start;
	while(ptr1!=NULL)
	{
		ptr2=ptr1->link;
		ptr1->link=prev;
		prev=ptr1;
		ptr1=ptr2;
	}
	start=prev;

	void display()  {
		if(start==NULL) {
			printf("\nThe list is empty\n");
		}
	}
	printf("\nThe reversed linked list is: \n");
	temp=start;	
	while(temp!=NULL)  {
		printf("%d\t", temp->info);
		temp=temp->link;
	}
}
