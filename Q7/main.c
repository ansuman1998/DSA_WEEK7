#include <stdio.h>
#include <stdlib.h>
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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
struct data
{
    int a;
    int b;
    char c;
};
struct data d[1000];
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

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
int countnodes(struct node *root)
{
    if(root==NULL)
        return 0;

    return 1+countnodes(root->right)+countnodes(root->left);
}
int checkcomplete(struct node *root,int numnodes, int index)
{

    if(root==NULL) /*This has to be checked first because elsewise, index check fails for NULL nodes */
        return 1;

    if(index>=numnodes)
    {
        return 0;
    }

    return checkcomplete(root->left,numnodes,2*index+1) && checkcomplete(root->right,numnodes,2*index+2);

}
int checkheap(struct node* root)
{
    if(root==NULL)
        return 1;
    if(root->left==NULL&&root->right!=NULL)
        return 0;
    else
        return checkheap(root->left)&&checkheap(root->right);
}
/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

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
    printf("Root and its children are handled here\n");
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

    int numnodes = countnodes(root);
    printf("%d\n",numnodes);
    //////////////Tree constructed here //////////////////////
    //////////////Check is it is complete ////////////////////
    int iscomplete=checkcomplete(root,numnodes,0);
    if(iscomplete==0)
    {
        printf("Difficult\n");
        return 0;
    }
    int isheap=checkheap(root);
    if(isheap==0)
    {
        printf("Difficult\n");
        return 0;
    }
    printf("Easy");
    return 0;


}
