#include <stdio.h>
#include <stdlib.h>
long int minheap[100000];
long int maxheap[100000];
long int countmin=0;
long int countmax=0;
float m=0;
void swap(long int *a, long int *b)
{
    long int temp;
    //printf("Swapping %ld and %ld\n",*a,*b);
    temp=*a;
    *a=*b;
    *b=temp;

}
long int getmax()
{
    //printf("Returning the root of MaxHeap : %ld\n",maxheap[0]);
    return maxheap[0];
}
long int getmin()
{
    //printf("Returning the root of MinHeap : %ld\n",minheap[0]);
    return minheap[0];
}
void insertmax(long int x)
{
   maxheap[countmax]=x;
   //printf("%ld inserted into the MaxHeap\n", maxheap[countmax]);
   countmax++;
   //printf("countmax just after inserting : %ld \n", countmax);
   long int i=countmax-1;
   while(i>0&&maxheap[i]>maxheap[(i-1)/2])
    {
        swap(&maxheap[i],&maxheap[(i-1)/2]);
        i=(i-1)/2;
    }

}
void insertmin(long int x)
{
    minheap[countmin]=x;
    //printf("%ld inserted into the MinHeap\n", minheap[countmin]);
    countmin++;
    long int i=countmin-1;
    while(i>0&&minheap[i]<minheap[(i-1)/2])
    {
        swap(&minheap[i],&minheap[(i-1)/2]);
        i=(i-1)/2;
    }
}
long int extractmax()
{
    long int prevmax=maxheap[0];
    //printf("%ld was the previous root of MaxHeap\n",prevmax);
    swap(&maxheap[0],&maxheap[countmax-1]);
    //printf("Swapped root with last node\n");
    countmax--;
    long int maxchild=-1;
    long int i=0;
    while(i<countmax/2)
    {
        //printf("Value of i is %ld\n", i);
        if(2*i+2<countmax)
        {
        if(maxheap[2*i+1]>maxheap[2*i+2])
            maxchild=2*i+1;
        else
            maxchild=2*i+2;
        }
        else
        {
            maxchild=2*i+1;
        }
        ////////////////////////////////////
        if(maxheap[maxchild]<=maxheap[i])
            break;
        else
            {
                swap(&maxheap[maxchild],&maxheap[i]);
                i=maxchild;
            }
    }

    return prevmax;
}
long int extractmin()
{
    long int prevmin=minheap[0];
    swap(&minheap[0],&minheap[countmin-1]);
    countmin--;
    long int minchild=-1;
    long int i=0;
    while(i<countmin/2)
    {
        if(2*i+2<countmin)
        {
        if(minheap[2*i+1]<minheap[2*i+2])
            minchild=2*i+1;
        else
            minchild=2*i+2;
        }
        else
        {
            minchild=2*i+1;
        }
        ////////////////////////////////////
        if(minheap[minchild]>=minheap[i])
            break;
        else
            {
                swap(&minheap[minchild],&minheap[i]);
                i=minchild;
            }
    }

    return prevmin;
}
long int max(long int a, long int b)
{
    if(a>b)
        return a;
    else
        return b;
}
long int min(long int a, long int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int main()
{
    long int n=100000,i,x,y;

    for(i=0;i<n;i++)
    {
        x=rand()%100001;
        //printf("User Inputs : %ld\n", x);
        //printf("countmax : %ld, countmin : %ld\n", countmax, countmin);
        if(countmin<countmax)
        {
            if(x<m)
            {
                y=extractmax();
                //printf("%ld will be moved from MaxHeap(left) to MinHeap(right)\n",y);
                insertmin(y);
                insertmax(x);
            }
            else
            {
                insertmin(x);
            }
            m=(getmax()+getmin())/2.0;
            //printf("Median till now is : %f\n",m);
        }
        else if(countmin == countmax)
        {
            if(x<m)
                {
                    insertmax(x);
                    m=getmax();
                }
            else
                {
                    insertmin(x);
                    m=getmin();
                }
             //printf("Median till now is : %f\n",m);

        }
        else if(countmin>countmax)
        {
            if(x<m)
            {
                insertmax(x);
            }
            else
            {
                y=extractmin();
                insertmax(y);
                insertmin(x);
            }
            m=(getmax()+getmin())/2.0;
            //printf("Median till now is : %f\n",m);

        }

    }


}
