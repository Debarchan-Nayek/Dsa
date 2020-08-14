#include<iostream>
 using namespace std;

 class Node
 {
 public:
    int data;
    Node *next;
 };

 Node *first=NULL;

 void create()
{
    struct Node *p,*last;
    int x,n;
    cout<<"Enter the no. of nodes: \n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter data: \n";
        cin>>x;
        p=(struct Node *)malloc(sizeof(struct Node));
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

 void Insert(Node *p,int pos)
 {
     Node *t=new Node;
     int n;
     cout<<"Enter data: \n";
     cin>>n;
     if(pos==0)             //First Node
     {
         t->data=n;
         t->next=NULL;
         first=t;
     }
     else
     {
         for(int i=0;i<pos-1;i++)
         {
             p=p->next;         //Moving up to the position-1 location, i.e after which we want to add that node
         }

         t->data=n;
         t->next=p->next;
         p->next=t;

     }
 }

 void Display(Node *p)
 {
     while(p!=NULL)
     {
         cout<<""<<p->data<<"\t";
         p=p->next;
     }
     cout<<"\n";
 }

int Count(Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int Sum(Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int Maxelement(Node *p)
{
    int m=first->data;
    while(p!=NULL)
    {
        if(p->data > m)
            m=p->data;

        p=p->next;
    }
    return m;
}

void Delete(struct Node *p,int pos)
{
    Node *q;
    if(pos==0)
    {
        q=first;
        first=first->next;
        delete(q);
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete(q);
    }
}

 int main()
 {
     int n,choice;
     create();


do
    {

     cout<<"Press 1 to Insert a node\n Press 2 to count the number of nodes\n Press 3 to find the sum of the elements of the linked list\n Press 4 to find the max element of the linked list\n Press 5 to Display the linked list\n Press 6 to Delete a node\n Press 7 to finish\n";
     cin>>choice;

            switch(choice)
     {
        case 1:
            {
                int k;
                cout<<"Enter the position at which you want to insert: \n";
                cin>>k;
                Insert(first,k);
                break;
            }

        case 2:
            cout<<"Total no. of nodes are: "<<Count(first)<<"\n";
            break;

        case 3:
            cout<<"The sum of all the elements is: "<<Sum(first)<<"\n";
            break;

        case 4:
            cout<<"Max element is: "<<Maxelement(first)<<"\n";
            break;

        case 5:
            Display(first);
            break;

        case 6:
            {
                int k;
                cout<<"Enter the position from which you want to delete: \n";
                cin>>k;
                Delete(first,k);
                cout<<"After deletion: \n";
                Display(first);
                break;
            }
        case 7:
            break;
     }

    }while(choice!=7);
     return 0;
 }
