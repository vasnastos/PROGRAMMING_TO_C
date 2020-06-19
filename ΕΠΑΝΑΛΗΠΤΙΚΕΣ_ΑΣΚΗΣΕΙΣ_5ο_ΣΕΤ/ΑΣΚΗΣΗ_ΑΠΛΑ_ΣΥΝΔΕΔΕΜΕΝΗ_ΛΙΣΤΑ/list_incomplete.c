#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void push_back(struct node *curr,int d)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=newnode;
    newnode->next=NULL;
}

int sum(struct node *curr)
{
    //Implementation
    return 0;
}

int length(struct node *curr)
{
    //impemantation
    return 0;
}

void printlist(struct node *curr)
{
    //Implementation
    printf("NOT IMPLEMENT YET\n");
}

int main()
{
    int a[]={2,6,7,4,1,9,12,45,51,2};
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->next=NULL;
    head->data=a[0];
    for(int i=1;i<sizeof(a)/sizeof(a[0]);i++)
    {
        push_back(head,a[i]);
    }
    printf("CHECK_1");
    push_back(head,57);
    printf("(PUSH_BACK)\n");
    printlist(head);
    printf("CHECK_2::\n");
    printf("Length:%d \t SUM:%d\n",length(head),sum(head));
}