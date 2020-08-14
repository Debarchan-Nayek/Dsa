#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};first=NULL;


void create()
{
    struct node *p,*last;
    int x,n;
    printf("Enter the number of nodes: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data: \n");
        scanf("%d",&x);
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        if(first==NULL)
        {
            first=p;
            last=p;
        }
        else
        {
            last->next=p;
            last=p;
        }
    }
}

void Insert(struct node *p,int pos)
{
   int i,value;
   printf("Enter the value to be inserted: \n");
   scanf("%d",&value);
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
        for(i=0;i<pos-1;i++)
            p=p->next;

         t->data=value;
         t->next=p->next;
         p->next=t;
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
    int k;
    create();
    printf("The no.s are:\n");
    Display(first);
    printf("Enter the position to insert a node: \n");
    scanf("%d",&k);
    Insert(first,k);
    printf("\n");
    Count(first);
    printf("\n");
    Sum(first);
    printf("\n");
    Maxelement(first);
    return 0;
}
