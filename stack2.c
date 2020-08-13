//STACK USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}*top=NULL;

void push()
{
    int x;
    printf("Enter data:\n");
    scanf("%d",&x);
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node ));
    if(t==NULL)
        printf("Stack is Full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    int x;
            struct node *p;
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free (p);
    }
    return x;
}

void Display()
{
    struct node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter no. of inputs: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        push();
    Display();
    printf("The deleted element is %d\n",pop());
    Display();
    return 0;

}
