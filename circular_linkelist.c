#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void create()
{
    struct Node *p;
    struct Node *last;

    int x,n;
    printf("Enter the number of nodes to be inserted: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data:\n");
        scanf("%d",&x);

        if(head==NULL)
        {
            p=(struct Node *)malloc(sizeof(struct Node));
            p->data=x;
            head=p;
            last=head;
            last->next=head;
        }
        else
        {
            p=(struct Node *)malloc(sizeof(struct Node));
            p->data=x;
            p->next=last->next;
            last->next=p;
            last=p;
        }
    }
}

void Insert(int index,int key)
{
    struct Node *p=head;

    if(index==0)                        //Inserting before head node
    {
       struct Node *t=(struct Node *)malloc(sizeof(struct Node));
       t->data=key;

       if(head==NULL)                   //If it is the only node in the linked list
       {
           head=t;
           head->next=head;
       }

       else                             //If it is not the only node
       {
               while(p->next!=head)
               {
                   p=p->next;
               }
                p->next=t;
               t->next=head;
               head=t;
       }
    }

    else                                    //Inserting at any other position
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        struct Node *t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->next=p->next;
        p->next=t;
    }
}
void Display()
{
    struct Node *p;
    p=head;

    do
    {
        printf("%d\t",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

int Delete(int index)
{
    int x;
    struct Node *p=head;
    struct Node *q;
    if(index==1)                    //Deleting first node
    {
        while(p->next!=head)
            p=p->next;
        if(head==p)                 //If head is the only node in the linked list
        {
            x=head->data;
            free(head);
            head=NULL;
        }

        else
        {
            p->next=head->next;
            x=head->data;
            free(head);
            head=p->next;
        }
    }

    else
    {
        for(int i=0;i<index-2;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main()
{
    create();
    Display();
    Insert(0,19);
    Display();
    printf("The deleted data is:%d\n",Delete(1));
    Display();
    return 0;
}
