#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
}*list=0;
void BInsert()
{
    struct node *nnode;
    int val;
    scanf("%d", &val);
    nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = val;
    nnode->next=0;
    if(list==0)
        list=nnode;
    else
    {
        nnode->next = list;
        list = nnode;
        printf("nnode %d",nnode);
    }
}
void EInsert()
{
    struct node *nnode, *t;
    int val;
    scanf("%d", &val);
    nnode = malloc(sizeof(struct node));
    nnode->data = val;
    nnode->next=0;
    if(list==0)
        list=nnode;
    else
    {
        t = list;
        while(t->next != 0)
            t=t->next;
        t->next = nnode;
    }
}
void PInsert()
{
    struct node *nnode, *p;
    int val, pos, ctr=1;
    scanf("%d", &val);
    scanf("%d", &pos);
    p = list;
    while(ctr<pos-1 && p->next!=0)
    {
        p = p->next;
        ctr++;
    }
    nnode = malloc(sizeof(struct node));
    nnode->data = val;
    nnode->next = p->next;
    p->next = nnode;
}
void Delete()
{
    struct node *s, *t;
    int d;
    scanf("%d", &d);
    if(list->data==d) //Beginning deletion
    {
        printf("%d", list->data);
        list = list->next;
    }
    else //Data is elsewhere in the list
    {
        t = list;
        while(t->data!=d && t->next!=0)
        {
            s = t;
            t = t->next;
        }
        if(t->data==d)
            s->next = t->next; //Skip the data
        else
            printf("Error 404: The requested data was not found.");
    }
}
void BDelete()
{
    if(list==0)
        printf("\nEmpty list!");
    else
    {
        printf("%d", list->data);
        list = list->next;
    }
}
void PDelete()
{
    struct node *s, *t;
    if(list==0)
        printf("\nEmpty list!");
    else
    {
        int pos, ctr=1;
        scanf("%d", &pos);
        t = list;
        while(ctr!=pos && t->next!=0)
        {
            s = t;
            t = t->next;
            ctr++;
        }
        if(ctr==pos)
            s->next = t->next;
        else
            printf("Error 404: The requested data was not found.");
    }   
}
void EDelete()
{
    struct node *t, *s;
    if(list==0)
        printf("\nEmpty list!");
    else
    {
        t = list;
        while(t->next!=0)
        {
            s = t;
            t = t->next;
        }
        s->next = t->next;
    }
}
void Search()
{
    if(list==0)
    {
        printf("\nList is empty!\n");
    }
    else
    {
        struct node *t=list;
        int val, ctr=1, chk=0;
        scanf("%d", &val);
        while(t!=0)
        {
            if(t->data==val)
            {
                printf("Element found at position %d", ctr);
                chk++;
            }
            t = t->next;
            ctr++;
        }
        if(chk==0)
            printf("\nElement not found!\n");
    }
}
void Display()
{
    struct node *t;
    if(list==0)
        printf("\nEmpty list!");
    else
    {
        t = list;
        while(t!=0)
        {
            printf("%d ", t->data);
            t = t->next;
        }
    }
}
int main()
{
    int ch=0;
    do
    {
        printf("\n------------------------------------------");
        printf("\n1. To perform beginning insertion");
        printf("\n2. To perform end insertion");
        printf("\n3. To perform position insertion");
        printf("\n4. To perform beginning deletion");
        printf("\n5. To perform end deletion");
        printf("\n6. To perform position deletion");
        printf("\n7. To perform search operation");
        printf("\n8. To display the linked list");
        printf("\n9. To end the program");
        printf("\nEnter choice [1-9]: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: 
            BInsert();
            break;
            case 2:
            EInsert();
            break;
            case 3:
            PInsert();
            break;
            case 4:
            BDelete();
            break;
            case 5:
            EDelete();
            break;
            case 6:
            PDelete();
            break;
            case 7:
            Search();
            break;
            case 8:
            Display();
            break;
            case 9:
            printf("\nThank You for using our program!\n");
            break;
            default:
            printf("\nInvalid Input!\n");
        }
    }while(ch!=9);
}