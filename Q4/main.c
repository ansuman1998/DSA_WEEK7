#include <stdio.h>
#include <stdlib.h>
struct node
{
    int n;
    struct node *left;
    struct node *right;
};
struct node * newNode(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->n=x;
    temp->right=NULL;
    temp->left=NULL;
};
struct node *temps[1000];
int counttemp=0;
int countnodes(struct node *root)
{
    if(root==NULL)
        return 0;

    return 1+countnodes(root->left)+countnodes(root->right);
}
void inorder(struct node *root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    temps[counttemp++]=root;
    inorder(root->right);
}
int main()
{
    struct node * root= newNode(4);
    root->left= newNode(2);
    root->left->left = newNode(1);
    root->left->right= newNode(3);
    root->right = newNode(5);

    int numnodes = countnodes(root);
    printf("%d\n", numnodes);
    inorder(root);
    int i;
    for(i=0;i<numnodes-1;i++)
    {
        temps[i]->right=temps[i+1];
        temps[i+1]->left=temps[i];
    }
    temps[0]->left = temps[numnodes-1];
    temps[numnodes-1]->right=temps[0];
    struct node *head = temps[0];
    struct node *temp;
    temp=head;

    printf("%d ", temp->n);
    temp=temp->right;
    while(temp!=head)
    {
        printf("%d ", temp->n);
        temp=temp->right;
    }
}
