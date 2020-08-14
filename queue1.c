//QUEUE USING ARRAY


#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *ar;
};

void create(struct queue *q)
{

    printf("Enter the size:\n");
    scanf("%d",&q->size);
    q->front=q->rear= -1;
    q->ar=(int *)malloc(q->size*(sizeof(int)));
}

void enque(struct queue *q,int x)
{
    if(q->rear==q->size-1)
        printf("Queue is Full.\n");
    else
    {
        q->rear++;
        q->ar[q->rear]=x;
    }
}

int deque(struct queue *q)
{
    int x;
    if(q->front==q->rear)
        printf("Queue is Empty.\n");
    else
    {
        q->front++;
        x=q->ar[q->front];
    }
    return x;
}

void Display(struct queue q)
{
    int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("%d\t",q.ar[i]);
}

//ANOTHER WAY TO DISPLAY QUEUE USING ARRAY.
/*void Display(struct queue q)
{
    int i;
    for(i=q.front+1;i<=q.rear;i++)
    {
        printf("%d\t",q.ar[q.front+1]);
        q.front++;
    }
    printf("\n");
}

void Display(struct queue q)
{
    while(q.front<q.rear)
    {
        printf("%d\t",q.ar[q.front+1]);
        q.front++;
    }
    printf("\n");
}*/


int main()
{
    struct queue q;
    create(&q);
    enque(&q,10);
    enque(&q,20);
    enque(&q,30);
    enque(&q,40);
    enque(&q,50);
    Display(q);
    printf("The deleted value is:%d \n",deque(&q));
    Display(q);
    return 0;
}
