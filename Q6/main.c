#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min=INT_MAX;
int max=INT_MIN;
struct node
{
    int n;
    int hd;
    struct node* left;
    struct node* right;
};
struct node* newNode(int x)
{
    printf("%d is added to tree\n", x);
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->n=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
struct node *temp;
void findminmax(struct node* root, int hd)
{
    if(root==NULL)
        return;
    //printf("Horizontal Distance of %d is %d\n",root->n, hd);
    //printf("Present min is %d and Present max is %d\n", min, max);
    root->hd=hd;
    if(hd>max)
        max=hd;
    if(hd<min)
        min=hd;
    findminmax(root->left,hd-1);
    findminmax(root->right,hd+1);

}
void traverse(struct node *root, int hd)
{
    if(root==NULL)
        return;

    if(root->hd==hd)
        printf("%d ",root->n);
    traverse(root->left,hd);
    traverse(root->right,hd);
}
void search(struct node* root, int x)
{
    if(root==NULL)
        return;

    else if(root->n==x)
    {
        temp=root;
        return;
    }

    search(root->left,x);
    search(root->right,x);
    return;


}
struct data
{
    int a;
    int b;
    char c;
};
struct data d[1000];
int main()
{
    int m,a,b,rootvalue,i;
    char c;
    scanf("%d %d",&m, &rootvalue);
    struct node *root=NULL;
    for(i=0;i<m;i++)
    {
      scanf("%d %d %c", &d[i].a, &d[i].b, &d[i].c);
      if(d[i].a==rootvalue)
      {
            if(root==NULL)
                root=newNode(d[i].a);

            if(d[i].c=='l')
                root->left=newNode(d[i].b);
            else
                root->right=newNode(d[i].b);
      }

    }
    printf("Root and children are handled here\n");
    while(1)
    {
        int count=0;
        for(i=0;i<m;i++)
        {
            temp=NULL;
            search(root,d[i].a);
            if(temp!=NULL)
            {
                 count++;
                 if(d[i].c=='l')
                    temp->left=newNode(d[i].b);
                 else
                    temp->right=newNode(d[i].b);
            }

        }
        if(count==m)
            break;
    }

    /*
    if(root==NULL)
        {
            root=newNode(a);
            if(c=='l')
                root->left=newNode(b);
            else
                root->right=newNode(b);
        }
        search(root,temp,a);
        if(c=='l')
            temp->left=newNode(b);
        else
            temp->right=newNode(b);
        m--;
    */
    ///////////////////////////////////////
    /*struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);*/
    ///////////////////////////////////////
    findminmax(root,0);
    printf("%d %d\n",min,max);
    for(i=min;i<=max;i++)
    {
        traverse(root,i);
        printf("\n");
    }
}
