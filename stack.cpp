//STACK USING ARRAY

#include<iostream>
using namespace std;

class Stack
{
private:
    int n;
    int top;
    int *ar;
public:
    void ar_size(int x);
    void create();
    void push();
    int pop();
    void Display();
    int peek(int n);
    void isEmpty();
    void isFull();
    int topdata();
};

void Stack::ar_size(int x)
{
    n=x;
}
void Stack::create()
{
    ar=new int(n);
    top=-1;
}

void Stack::push()
{
    int x;
    cout<<"Enter data: \n";
    cin>>x;
    if(top==n-1)
        cout<<"Stack is Full\n";
    else
    {
        top++;
        ar[top]=x;
    }
}

int Stack::pop()
{
int x;
    if(top==-1)
        return -1;
    else
    {
        x=ar[top];
        top--;
    }
    return x;
}

int Stack:: peek(int index)
{
    int x;
    if(top-index+1)
        cout<<"Invalid Index\n";
    else
        x=ar[top-index+1];

    return x;
}

void Stack::isEmpty()
{
    if(top==-1)
        cout<<"Stack is Empty\n";
        else
            cout<<"Stack is not empty\n";
}

void Stack::isFull()
{
    if(top==n-1)
        cout<<"Stack is Full\n";
}

void Stack::Display()
{
    int i;
    for(i=top;i>=0;i--)
        cout<<""<<ar[i]<<"\t";
    cout<<"\n";
}

int Stack::topdata()
{
    if(top==-1)
        return -1;
    else
        return ar[top];
}

int main()
{
    Stack st;
    st.create();
    int x,s;
    cout<<"Enter the size of array:\n";
    cin>>x;
    st.ar_size(x);
    cout<<"Enter the elements in stack: \n";
    cin>>s;
    for(int i=0;i<s;i++)
        st.push();
    int choice;
    do
    {

        cout<<"\nPress 1 to Display\nPress 2 to find an element at an index\nPress 3 to know if the stack is empty\nPress 4 to know if the stack is full\n Press 5 to know the data to which top is pointing\nPress 6 to delete an element\nPress 7 to end";
        cout<<"Enter your choice: \n";
        cin>>choice;

        switch(choice)
        {
        case 1:
            st.Display();
            break;
        case 2:
            {
                int k,index;
                cout<<"Enter the index at which you want to find the element: \n";
                cin>>index;
                k=st.peek(index);
                cout<<"The element is "<<k<<"\n";
                break;
            }
        case 3:
            st.isEmpty();
            break;
        case 4:
            st.isFull();
            break;
        case 5:
            {
                int k=st.topdata();
                if(k==-1)
                    cout<<"Stack is Empty\n";
                else
                    cout<<""<<k<<" is the required data\n";
                    break;
            }
        case 6:
            {
                int k=st.pop();
                if(k==-1)
                    cout<<"Stack is Empty\n";
                else
                    cout<<"Deleted data is: "<<k<<"\n";
                break;
            }
        case 7:
            break;

        }

    }while(choice!=7);

    return 0;
}
