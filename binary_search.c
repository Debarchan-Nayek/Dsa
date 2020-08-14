#include<stdio.h>
void bin_search(int a[],int n,int key)
{
    int mid,low=0,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            printf("Key is found at %d",mid+1);
            break;
        }
        else if(a[mid]<key)
            low=mid+1;
        else if(a[mid]>key)
            high=mid-1;
        else
            printf("Not found\n");
    }
}
int main()
{
    int n;
    printf("Enter the size: \n");
    scanf("%d",&n);
    int ar[n];
    printf("Enter the array elements: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&ar[i]);
    int key;
    printf("Enter the element to be found: \n");
    scanf("%d",&key);
    bin_search(ar,n,key);
    return 0;
}
