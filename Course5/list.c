#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void pushfront(struct node **head,int d)
{
   struct node *newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=d;
   newnode->next=*head;
   *head=newnode;
   printf("element has been inserted to list!!!\n");
}
int length(struct node *curr)
{
    //to me implement
    return -1;
}
int sum(struct node *curr)
{
    //to be implement
    return -1;
}
void inserttopositioni(struct node *curr,int pos,int d)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    int i=1;
    while(i<pos-1)
    {
        curr=curr->next;
        i++;
    }
    struct node *afterpos=curr->next;
    curr->next=newnode;
    newnode->next=afterpos;
}
void push_back(struct node *curr,int d)
{   
    int i=1;
    int size=length(curr);
    while(i<size)
    {
        curr=curr->next;
        i++;
    }
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    curr->next=newnode;
    newnode->next=NULL;
    printf("element has been inserted to list!!!\n");
}
void printlist(struct node *curr)
{
    //to be implement
    printf("list\n");
}
void deletelist(struct node *curr)
{
    while(curr!=NULL)
    {
        struct node *temp=curr;
        curr=curr->next;
        free(temp);
    }
    printf("List deleted!!!\n");
}
int main()
{
    printf("Create list L1:\n");
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->data=10;
    head->next=NULL;
    push_back(head,20);
    push_back(head,30);
    push_back(head,40);
    pushfront(&head,5);
    inserttopositioni(head,3,25);
    printlist(head);
    printf("LENGTH:%d\n",length(head));
    deletelist(head);
}