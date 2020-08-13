//STACK USING ARRAY

#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *a;
};

void create(struct stack *st)
{
    printf("Enter the size of the array: \n");
    scanf("%d",&st->size);
    st->a=(int *)malloc(st->size*(sizeof (int)));
    st->top=-1;
}

void push(struct stack *st)
{
    int x;
    printf("Enter data: \n");
    scanf("%d",&x);
    if(st->top==st->size-1)
        printf("Stack is Full. \n");
    else
    {
        st->top++;
        st->a[st->top]=x;
    }
}

int pop(struct stack *st)
{
    int x;
    if(st->top==-1)
        printf("Stack is Empty.\n");
    else
    {
        x=st->a[st->top];
        st->top--;
    }
    return x;
}

void Display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
        printf("%d \t",st.a[i]);
    printf("\n");

}

//ANOTHER WAY TO DISPLAY STACK USING ARRAY
/*void Display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d\t",st.a[st.top]);
        st.top--;
    }
    printf("\n");

}*/

void isEmpty(struct stack st )
{
    if(st.top==-1)
        printf("Stack is Empty.\n");

}

void isFull(struct stack st)
{
    if(st.top==st.size-1)
        printf("Stack is Full\n");
}


int main()
{
    struct stack st;
    create(&st);
    int n;
    printf("Enter the no. of elements to be entered: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        push(&st);
    Display(st);
    printf("The deleted value is:%d\n",pop(&st));
    Display(st);
    return 0;
}
