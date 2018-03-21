#include <stdio.h>
#include <stdlib.h>
struct node
{
    int n;
    struct node* next;
};
struct node * globalHead;
void push(struct node **head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->n=x;
    temp->next=NULL;
    printf("%d is added to the list\n", x);
    if((*head)==NULL)
        {
            *head=temp;
            globalHead = *head;
        }
    else
        {
            (*head)->next=temp;
            *head=temp;

        }
}

void printList(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->n);
        temp=temp->next;
    }
    printf("\n");
}
void partition(struct node *head, struct node ** front, struct node **back)
{
    struct node* fast;
    struct node* slow;
    if(head==NULL||head->next==NULL)
    {
        front=head;
        back=NULL;
    }
    else
    {
        slow=head;
        fast=head->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }

        *front=head;
        *back=slow->next;
        slow->next=NULL;
        printList(*front);
        printList(*back);
    }
}
struct node* mergeLists(struct node *a, struct node *b)
{
    struct node *mergedList = NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->n < b->n)
    {
        mergedList=a;
        mergedList->next=mergeLists(a->next,b);
    }
    else
    {
        mergedList=b;
        mergedList->next=mergeLists(a,b->next);
    }
    return mergedList;
}
void mergeSort(struct node** source)
{
    struct node* head = *source;
    struct node* left = NULL;
    struct node* right = NULL;
    if(head==NULL || head->next==NULL)
        return;

    partition(head,&left,&right);
    mergeSort(&left);
    mergeSort(&right);
    *source= mergeLists(left,right);
}
int main()
{
    struct node *head=NULL;
    push(&head,4);
    push(&head,3);
    push(&head,1);
    push(&head,5);
    push(&head,7);

    printList(globalHead);
    //printList(globalHead);
    mergeSort(&globalHead);
    printList(globalHead);

    return 0;
}
