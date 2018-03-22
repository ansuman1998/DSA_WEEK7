#include <stdio.h>
#include <stdlib.h>
struct node
{
    int n;
    struct node *prev;
    struct node *next;
};
struct node* head, *tail;
//////////////////////////////////////////////////////////////////////
void push(int x)
{
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->n=x;
    temp->next=NULL;
    if(head==NULL&&tail==NULL)
    {
        temp->prev=NULL;
        head=temp;
        tail=temp;
    }
    else
    {
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}
//////////////////////////////////////////////////////////////////////
void print(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ", temp->n);
        temp=temp->next;
    }
    printf("\n");
}
/////////////////////////////////////////////////////////////////////
int countnodes(struct node* temp)
{
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
//////////////////////////////////////////////////////////////////////
void preorder(struct node *root)
{
    if(root==NULL)
        return;

    printf("%d ",root->n);
    preorder(root->prev);
    preorder(root->next);

}
/////////////////////////////////////////////////////////////////////
struct node* makeBSTrecur(struct node **href, int n)
{
    if(n<=0)
        return NULL;

    struct node* left= makeBSTrecur(href,n/2);
    struct node* root= *href;
    root->prev = left;
    (*href)=(*href)->next;
    struct node* right= makeBSTrecur(href,n-n/2-1);
    root->next=right;
    return root;
};
//////////////////////////////////////////////////////////////////////
struct node* makeBST(struct node *temphead, int numnodes)
{
    return makeBSTrecur(&temphead,numnodes);
};

int main()
{
    //struct node *head = NULL;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);

    print(head);

    int numnodes = countnodes(head);
    printf("%d\n", numnodes);
    struct node *root = makeBST(head,numnodes);
    preorder(root);

}
