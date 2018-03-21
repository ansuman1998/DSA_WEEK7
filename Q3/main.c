#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int *result;
int *heap;
int *lastindex;
int **a;
int lastarray=-1;
int heapsize;
heapifydown(int root, int n)
{
    int i;
    int temp;
    int minchild;
    for(i=root;i<n/2;i++)
    {
        if(heap[2*i+1]<heap[2*i+2])
            minchild=2*i+1;
        else
            minchild=2*i+2;
        if(heap[minchild]<heap[i])
        {
            temp=heap[i];
            heap[i]=heap[minchild];
            heap[minchild]=temp;
        }
        else
            break;

    }
}
buildmaxheap()
{
    int i;
    for(i=heapsize/2;i>=0;i--)
        heapifydown(i,heapsize);

}
int extractmin(int n, int k)
{
    int retvalue=heap[0];
    int targetarray = -1;
    int i;
    for(i=0;i<n;i++)
    {
        if(lastindex[i]<k&&a[i][lastindex[i]]==retvalue)
            break;
    }
    targetarray=i;
    lastarray=i;
    lastindex[lastarray]++;
    if(lastindex[lastarray]<k)
        heap[0]=a[lastarray][lastindex[lastarray]];
    else
        heap[0]=INT_MAX;
    heapifydown(0,heapsize);
 return retvalue;
}
int main()
{
    int n,k;
    scanf("%d %d",&n, &k);
    a=(int **)malloc(n*sizeof(int *));
    int i,j;
    for(i=0;i<n;i++)
        a[i]=(int *)malloc(k*sizeof(int));
    for(i=0;i<n;i++)
        for(j=0;j<k;j++)
        scanf("%d", &a[i][j]);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
    result=(int *)malloc(n*k*sizeof(int));
    heap=(int *)malloc(n*sizeof(int));
    lastindex=(int *)malloc(n*sizeof(int));
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
    for(i=0;i<n;i++)
        lastindex[i]=0;
    for(i=0;i<n;i++)
        heap[i]=a[i][0];

    heapsize=n;
    buildmaxheap();

    for(i=0;i<n;i++)
        printf("%d ", heap[i]);
    printf("\n");
///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
    for(i=0;i<n*k;i++)
    {
        int temp=extractmin(n,k);
        result[i]=temp;
    }

    for(i=0;i<n*k;i++)
        printf("%d ",result[i]);
    printf("\n");


}


