#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}*head=NULL;

void Insert(int pos)
{
    int x;
    struct Node *p=head,*t;
    printf("Enter data: \n");
    scanf("%d",&x);
    if(pos==0)
    {
        if(head!=NULL)
        {

            t->prev=NULL;
            t->next=head;
            head->prev=t;
            head=t;
        }
        else
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->prev=t->next=NULL;
            head=t;
        }
    }
    else
    {
        for(int i=0;i<pos-1;i++)
            p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next!=NULL)
            p->next->prev=t;
        p->next=t;
    }
}

void Display()
{
    struct Node *p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

struct Node * Delete(int index)
{
    struct Node *p=head;
    if(index==1)
    {
        head=head->next;
        head->prev=NULL;
        return p;
        free(p);
    }
    else
    {
        for(int i=0;i<index;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next!=NULL)
            p->next->prev=p->prev;
        return p;
        free(p);
    }

}

int main()
{
    int n,m,choice;
    printf("Enter the no. of nodes: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        Insert(i);
    do
    {
    printf("Press 1 to Insert\nPress 2 to Delete\nPress 3 to  Display\nPres 4 to end\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            int x;
            printf("Enter the position at which you want to insert: \n");
            scanf("%d",&x);
            Insert(x);
            break;
        }

    case 2:
        {
            printf("Enter the position to be deleted: \n");
            scanf("%d",&m);
            struct Node *q=Delete(m);
            printf("The deleted data is: %d",q->data);
            break;
        }
    case 3:
        Display();
        break;
    case 4:
        break;
    }
    }while(choice!=4);


    return 0;
}
