#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minkey(int *key, int *mst,int n)
{
    int min=INT_MAX;
    int minindex;
    int i;
    for(i=1;i<=n;i++)
    {
        if(mst[i]==0 && key[i]<min)
        {
            min=key[i];
            minindex=i;
        }
    }
    return minindex;
}
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    //////////////////////////////////////////////////////
    int **a=(int **)malloc((n+1)*sizeof(int *));
    int i,j;
    for(i=0;i<n+1;i++)
        a[i]=(int *)malloc((n+1)*sizeof(int));
    ////////////////////////////////////////////////////
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        {
            a[i][j]=0;
            //printf("%d %d %d\n", i, j, a[i][j]);
        }
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }*/
    //////////////////////////////////////////////////
    int c,d,w;


    while(m!=0)
    {
        scanf("%ld %ld %ld", &c,&d,&w);
        a[c][d]=w;
        a[d][c]=w;
        m--;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    int *mst = (int *)malloc((n+1)*sizeof(int));
    int *key = (int *)malloc((n+1)*sizeof(int));
    int *parent = (int *)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
        {
            mst[i]=0;
            key[i]=INT_MAX;
            parent[i]=-1;
        }
    printf("Parent, Key and MST values initialized\n");
    key[1]=0;
    mst[1]=0;
    int totalweight=0;
    for(i=1;i<=n;i++)
    {
        int u=minkey(key,mst,n);
        printf("Minimum key extracted is %d\n",u);
        mst[u]=1;

        if(u!=1)
        totalweight+=a[u][parent[u]];

        int v;
        for(v=1;v<=n;v++)
        {
            if(a[u][v]!=0 && key[v]> a[u][v])
            {
                key[v]=a[u][v];
                parent[v]=u;
                printf("Key of %d is updated to %d with parent %d\n", v, key[v], parent[v]);
            }
        }
    }


    printf("%d\n", totalweight);


}
