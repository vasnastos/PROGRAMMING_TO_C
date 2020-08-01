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
    if(curr==NULL)
    return -1;
    int cnt=0;
    while(curr!=NULL)
    {
       cnt++;
       curr=curr->next;
    }
}
int sum(struct node *curr)
{
    if(curr==NULL)
    return -1;
    int sum=0;
    while(curr!=NULL)
    {
      sum+=curr->data;
      curr=curr->next;
    }
    return sum;
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
  if(curr==NULL)
  { 
     perror("list does not exist!!\n");
     return;
  }
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=d;
  int i=1;
  int size=length(curr);
  while(i<size)
  {
      curr=curr->next;
      i++;
  }
  curr->next=newnode;
  newnode->next=NULL;
}
void printlist(struct node *curr)
{
    printf("LIST VIEW\n");
    int i=1;
    int size=length(curr)-1;
    while(curr!=NULL)
    {
        if(i<size)
        {
            printf("%d->",curr->data);
        }
        else
        {
            printf("%d->",curr->data);
        }
        curr=curr->next;
        i++;
    }
    printf("\n");
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
    printf("Check 1:pushback():");
    printlist(head);
    pushfront(&head,5);
    printf("Check 2:pushfront():");
    inserttopositioni(head,3,25);
    prtintf("Check 3:insert_to_position(3)");
    printlist(head);
    printf("Check 4:length list()");
    printf("LENGTH:%d\n",length(head));
    deletelist(head);
}