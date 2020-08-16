//STACK USING LINKED LIST

#include<iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
public:
    void push();
    int pop();
    void Display();
};

Node *top=NULL;

void Node::push()
{
    int n;
    cout<<"Enter data: \n";
    cin>>n;
    Node *t=new Node;
    if(t==NULL)
        cout<<"Stack is full\n";
    else
    {
        t->data=n;
        t->next=top;
        top=t;
    }

}

int Node::pop()
{
    int x;
    Node *p;
    if(top==NULL)
        cout<<"Stack is empty\n";
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free (p);
    }
    return x;
}

void Node::Display()
{
    Node *p;
    p=top;
    while(p!=NULL)
    {
        cout<<""<<p->data<<"\t";
        p=p->next;
    }
    cout<<"\n";;
}

int main()
{
    int n;
    Node q;
    cout<<"Enter the no. of inputs: \n";
    cin>>n;
    for(int i=0;i<n;i++)
        q.push();
    q.Display();
    cout<<"The deleted element is: "<<q.pop()<<"\n";
    q.Display();
    return 0;

}

