#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct {
    struct node *head;
}list;
int length(struct node *curr)
{
    if(curr==NULL)
    {
        perror("empty list");
        return -1;
    }
  int l=0;
  while(curr!=NULL)
  {
      l++;
      curr=curr->next;
  }
  return l;
}
void push_front(struct node **cr,int d)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=*cr;
    *cr=newnode;
}
void insertintoposition(struct node *curr,int d,int pos)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    for(int i=1;i<pos-1;i++)
    {
       curr=curr->next;
    }
    newnode->next=curr->next;
    curr->next=newnode;
}
void deleteatposition(struct node *curr,int pos)
{
    if(pos<0 || pos>length(curr))
    {
        perror("invalid position,cant erase elment from thiw position because it does not exist;\n");
        return;
    }
    struct node *previous=NULL;
    for(int i=1;i<pos;i++)
    {
        previous=curr;
        curr=curr->next;
    }
    struct node *temp=curr;
    previous->next=curr->next;
    free(temp);
}
void pushback(struct node *curr,int x)
{
   struct node *newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=x;
   int size=length(curr);
   int i=1;
   while(i<size)
   {
       curr=curr->next;
       i++;
   }
   curr->next=newnode;
   newnode->next=NULL;
}
void print(list *l)
{
    struct node *curr=l->head;
    while(curr!=NULL)
    {
        printf("%d->",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
void deletelist(list *l)
{
    while(l->head!=NULL)
    {
        struct node *temp=l->head;
        l->head=l->head->next;
        free(temp);
    }
}
void erasefront(struct node **curr)
{
   struct node *prev=*curr;
   *curr=(*curr)->next;
   free(prev);
   prev=*curr;
}
void bubblesort(struct node *curr)
{
    struct node *headnode=curr;
    int size=length(curr);
    while(curr!=NULL)
    {
        struct node *temp=headnode;
       for(int i=0;i<size-1;i++)
       {
           if(temp->data>temp->next->data)
           {
               int var=temp->data;
               temp->data=temp->next->data;
               temp->next->data=var;
           }
           temp=temp->next;
       }
       curr=curr->next;
    }
}
//reverse list to be implement!!!! 
int main()
{
    list ll;
    ll.head=(struct node *)malloc(sizeof(struct node));
    ll.head->data=1;
    ll.head->next=NULL;
    pushback(ll.head,2);
    pushback(ll.head,3);
    erasefront(&ll.head);
    printf("CHECK_1:(erase front):expected 2->3:\t");
    print(&ll);
    printf("Check 2(push_front):expected 4->2->3:\t");
    push_front(&ll.head,4);
    print(&ll);
    printf("Check 3(insertintoposition(2)):expected4->->20->2->3:\t");
    insertintoposition(ll.head,20,2);
    print(&ll);
    printf("Check 4(deleteatposition(3)):expected 4->20->3:\t");
    deleteatposition(ll.head,3);
    print(&ll);
    printf("Check 5(Length):expected[3]:\t");
    printf("Length:%d\n",length(ll.head));
    printf("Check 6:(bubblesort):\n");
    bubblesort(ll.head);
    print(&ll);
    deletelist(&ll);
}