#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
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
void pushback(struct node *curr,char x)
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
        printf("%c-",curr->data);
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
int main()
{
    list ll;
    ll.head=(struct node *)malloc(sizeof(struct node));
    char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    ll.head->data=alphabet[0];
    ll.head->next=NULL;
    printf("check_1(push_back):\n");
    for(int i=1;i<26;i++)
    {
        pushback(ll.head,alphabet[i]);
    }
    print(&ll);
    printf("check2(Length):\n");
    printf("Length:%d",length(ll.head));
    deletelist(&ll);
}