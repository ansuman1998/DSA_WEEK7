#include <stdio.h>
#include <stdlib.h>
print(long int *a, long int n)
{
    long int i;
    for(i=0;i<n;i++)
        printf("%ld ",a[i]);
    printf("\n");
}
void mergesort(long int *a, long int *temp, long int low, long int high)
{
    if(low>=high)
        return;


    long int mid=(low+high)>>1;
    //printf("%ld %ld %ld\n",low, mid, high);
    mergesort(a,temp,low,mid);
    mergesort(a,temp,mid+1,high);

    long int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
         temp[k++]=a[i++];
    while(j<=high)
         temp[k++]=a[j++];

    //print(temp,high-low+1);
    for(i=low;i<=high;i++)
        a[i]=temp[i];

    return;
}
int main()
{
    long int n=100000,i;
    long int *a=(long int *)malloc(n*sizeof(long int));
    long int *temp=(long int *)malloc(n*sizeof(long int));
    for(i=0;i<n;i++)
    {
        a[i]=(rand()+1)%1000000000;
    }
    //print(a,n);
    mergesort(a,temp,0,n-1);
    //print(a,n);
    long long int sum=0;
    for(i=0;i<n;i++)
        {
            //printf("%ld ",a[i]);
            sum=sum+a[i];
        }
    /*long long int sum=0;*/





   printf("%lld",sum);

}
