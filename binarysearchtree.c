#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root=NULL;

void Insert()
{
    int x;
    printf("Enter data: \n");
    scanf("%d",&x);
    struct Node *t=root;
    struct Node *p,*r;
    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=x;
        p->lchild=p->rchild=NULL;
        root=p;
    }
    else
    {
        while(t!=NULL)
        {
            r=t;
            if(x<t->data)
                t=t->lchild;
            else if(x>t->data)
                t=t->rchild;
            else
                printf("Already inserted\n");
        }
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=x;
        p->lchild=p->rchild=NULL;
        if(x<r->data)
            r->lchild=p;
        else
            r->rchild=p;
    }
}

void Inorder(struct Node *p)
{
    if(p!=NULL)
    {
        Inorder(p->lchild);
        printf("%d\t",p->data);
        Inorder(p->rchild);
    }
}

int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    else
    {
        x=Height(p->lchild);
        y=Height(p->rchild);
        return x>y?x+1:y+1;
    }
}

struct Node* Search(int x)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(x==t->data)
            return t;
        else if(x<t->data)
            t=t->lchild;
        else if(x>t->data)
            t=t->rchild;
    }
    return NULL;
}

struct Node* InPred(struct Node *p)
{
    while(p!=NULL && p->rchild!=NULL)
        p=p->rchild;

    return p;

}

struct Node* InSucc(struct Node *p)
{
    while(p!=NULL && p->lchild!=NULL)
        p=p->lchild;

    return p;

}

struct Node* Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;

    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }

    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);

    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPred(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,key);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,key);
        }
    }
}

int main()
{
    int n,m,key;
    printf("How many Node do you want to insert..??");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        Insert();

    Inorder(root);

    printf("\nHeight of the binary tree is: %d\n",Height(root));

    printf("Enter the element to be searched: \n ");
    scanf("%d",&m);
    struct Node *search=Search(m);
    if(search==NULL)
        printf("Not found\n");
    else
        printf("%d element is found\n",search->data);

    printf("Enter the data to be deleted: \n");
    scanf("%d",&key);
    Delete(root,key);

    printf("Display using Inorder traversal after deleting:\n");
    Inorder(root);
    return 0;
}
