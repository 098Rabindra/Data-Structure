#include <stdio.h>
#include <stdlib.h>
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
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_at_begin();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_loc();
            break;
        case 4:
            delete_at_begin();
            break;
        case 5:
            delete_at_end();
            break;
        case 6:
            delete_at_loc();
            break;
        case 7:
            traverse();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    } while (ch != 8);
}

struct node
{
    int info;
    struct node *link;
};

struct node *start = NULL;

void insert_at_begin()
{
    int e;
    struct node *fresh;
    fresh = (struct node *)malloc(sizeof(struct node));
    if (fresh == NULL)
    {
        printf("\nOverflow! Memory allocation failed.\n");
        return;
    }

    printf("\nEnter the element to insert at Begin: ");
    scanf("%d", &e);

    fresh->info = e;

    if (start == NULL)
    {
        fresh->link = fresh; // Points to itself in circular list
        start = fresh;       // Set start to the new node
    }
    else
    {
        struct node *ptr = start;
        while (ptr->link != start)
        {
            ptr = ptr->link;
        }
        fresh->link = start; // new node's link points to start
        ptr->link = fresh;   // last node points to the new node
        start = fresh;       // start points to the new node
    }

    printf("\n%d inserted at the beginning.\n", e);
}

void insert_at_end()
{
    int e;
    struct node *fresh, *ptr;
    fresh = (struct node *)malloc(sizeof(struct node));
    if (fresh == NULL)
    {
        printf("\nOverflow Condition\n");
        return;
    }

    printf("\nEnter the element to insert at End: ");
    scanf("%d", &e);

    fresh->info = e;
    fresh->link = start; // new node's link points to start

    if (start == NULL)
    {
        start = fresh; // list is empty, so new node becomes the start
    }
    else
    {
        ptr = start;
        while (ptr->link != start) // traverse till last node
        {
            ptr = ptr->link;
        }
        ptr->link = fresh; // last node points to the new node
    }
    printf("\n%d inserted at the end.\n", e);
}

void insert_at_loc()
{
    int i = 1, e, loc;
    struct node *fresh, *ptr;
    fresh = (struct node *)malloc(sizeof(struct node));
    if (fresh == NULL)
    {
        printf("\nOverflow! Memory allocation failed.\n");
        return;
    }

    printf("\nEnter the element and location: ");
    scanf("%d%d", &e, &loc);

    fresh->info = e;

    if (loc == 1)
    {
        fresh->link = start;
        if (start == NULL)
        {
            start = fresh;
            fresh->link = start;
        }
        else
        {
            struct node *last = start;
            while (last->link != start)
            {
                last = last->link;
            }
            last->link = fresh;
            start = fresh;
        }
    }
    else
    {
        ptr = start;
        while (i < loc - 1 && ptr->link != start)
        {
            ptr = ptr->link;
            i++;
        }

        if (i == loc - 1)
        {
            fresh->link = ptr->link;
            ptr->link = fresh;
        }
        else
        {
            printf("\nLocation doesn't exist.\n");
            free(fresh);
        }
    }
}

void delete_at_begin()
{
    struct node *ptr, *last;
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
        last = start;
        while (last->link != start) // traverse to last node
        {
            last = last->link;
        }
        start = start->link;
        last->link = start;
    }

    printf("\n%d is Deleted\n", ptr->info);
    free(ptr);
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
    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    printf("The elements of the circular linked list are:\n");
    ptr = start;
    do
    {
        printf("%d\t", ptr->info);
        ptr = ptr->link;
    } while (ptr != start);
    printf("\n");
}

