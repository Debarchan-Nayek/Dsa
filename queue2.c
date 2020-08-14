//QUEUE USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue()
{
    int x;
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        printf("Queue is Full\n");
    else
    {
        printf("Enter data:\n ");
        scanf("%d",&x);
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }

    }
}

int dequeue()
{
    int x;
    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        x=front->data;
        front=front->next;
    }
    return x;
}

void Display()
{
    struct node *p;
    p=front;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }

}
int main()
{

    int n;
    printf("Enter the no. of elements to be inserted in a queue: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        enqueue();

    Display();
    printf("The deleted data is: %d\n",dequeue());
    Display();
    return 0;
}
