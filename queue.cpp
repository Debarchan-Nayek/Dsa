#include<iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *ar;
public:
    void create();
    void enqueue();
    int dequeue();
    void Display();
    int ar_size();
};

void Queue::create()
{
    cout<<"Enter the size of the array: \n";
    cin>>size;
    front=rear=-1;
    ar=new int(size);
}

int Queue::ar_size()
{
    return size;
}
void Queue::enqueue()
{
    int x;
    cout<<"Enter data: \n";
    cin>>x;
    if(rear==size-1)
        cout<<"Queue is full\n";
    else
    {
        rear++;
        ar[rear]=x;
    }
}

int Queue::dequeue()
{
    int x;
    if(front==rear)
        cout<<"Queue is Empty\n";
    else
    {
        front++;
        x=ar[front];
    }
    return x;
}

void Queue::Display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<""<<ar[i]<<"\t";
    }
    cout<<"\n";
}

int main()
{
    Queue q;
    int n;
    q.create();
    cout<<"Enter the total no. of inputs: \n";
    cin>>n;
    for(int i=0;i<n;i++)
        q.enqueue();
    q.Display();
    cout<<"The deleted data is: "<<q.dequeue()<<"\n";
    cout<<"Queue after deletion: \n";
    q.Display();
    return 0;
}
