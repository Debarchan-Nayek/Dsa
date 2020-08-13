#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};first=NULL;


void Insert(struct node *p,int pos,int value)
{
   int i;
    struct node *t;
    t=(struct node *)malloc(sizeof(int));
    if(pos==0)
    {
        t->data=value;
        t->next=first;
        first=t;
    }
    else
    {
        //p=first;
        for(i=0;i<pos-1;i++)
            p=p->next;
        if(p!=NULL)
            {
                t->data=value;
                t->next=p->next;
                p->next=t;
            }
    }
}


void Display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void Count(struct node *p)
{
  int c=0;
  while(p!=NULL)
  {
      c++;
      p=p->next;
  }
  printf("No. of nodes= %d",c);
}


void Sum(struct node *p)
{
  int s=0;
  while(p!=NULL)
  {
      s=s+p->data;
      p=p->next;
  }
  printf("Sum of the no.s is=%d",s);
}


void Maxelement(struct node *p)
{
    int m=0;
    while(p!=NULL)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    printf("Maximum element is: %d",m);
}



int main()
{
    printf("Enter the node:\n");
    Insert(first,0,10);
    Insert(first,1,12);
    Insert(first,2,5);
    Insert(first,3,9);
    Insert(first,4,11);
    printf("The no.s are:\n");
    Display(first);
    printf("\n");
    Count(first);
    printf("\n");
    Sum(first);
    printf("\n");
    Maxelement(first);
    return 0;
}
