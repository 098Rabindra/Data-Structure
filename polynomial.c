#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co,exp;
	struct node *link;
};
struct node *start;
int main()
{
	int co,exp;
	char ch='y';
	struct node *fresh,*ptr,*prev;
	do
  {
	fresh=(struct node*)malloc(sizeof(struct node));
	if(fresh==NULL)
	printf("\noverflow!!");
	else
	{
		printf("Enter the coefficient and exponent:");
		scanf("%d%d",&co,&exp);
		
		fresh->co=co;
		fresh->exp=exp;
		fresh->link=NULL;
		ptr=start;
		while(ptr!=NULL)
		{
			if(ptr->exp == fresh->exp)
			{
				ptr->co=ptr->co+fresh->co;
				goto label;
			}
			ptr=ptr->link;
		}      
		ptr=start;
		while(ptr!=NULL && ptr->exp>fresh->exp)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		if(ptr==start)
		{
			fresh->link=start;
			start=fresh;
		}
		else if(ptr==NULL)
		prev->link=fresh;
		else
		{
			fresh->link=ptr;
			prev->link=fresh;
		}	
	 }
	 label:
	 getchar();
	 printf("\ndo you want to insert more(y/n)?");
	 
	    scanf("%c",&ch);
    }
  while(ch =='y');
  printf("\n the created polynomial is:");
  	printf("%dx^%d",start->co,start->exp);
  for(ptr=start->link;ptr!=NULL;ptr=ptr->link)
  {
	  	if(ptr->co>0)
	  		printf("+%dx^%d",ptr->co,ptr->exp);
	  	else if(ptr->co==0)
	  		continue;
		else
		  	printf("-%dx^%d",ptr->co,ptr->exp);
      
  }

}
