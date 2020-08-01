#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define s 200

struct node 
{
    int data;
    struct node *next;
};


int getsize()
{
    int counter=0;
    char line[s];
    FILE *fp=fopen("numbers.txt","r");
    while(fgets(line,s,fp)!=NULL)
    {
       if(line[0]=='\n') continue;
       if(line[0]=='#') continue;
       counter++;
    }
    fclose(fp);
    return counter;
}

void readata(int *data)
{
    FILE *fp=fopen("numbers.txt","r");
    char line[s];
    int i=0;
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
        char *token=strtok(line,":");
        token=strtok(NULL,":");
        data[i]=atoi(token);
        i++;
    }
    fclose(fp);
}

void push_front(struct node **curr,int d)
{
   struct node *newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=d;
   newnode->next=(*curr);
   (*curr)=newnode;
}

bool is_empty(struct node *curr)
{
    if(curr==NULL)
    {
       return true;
    }
    else
    {
        return false;
    }
    
}

void push_back(struct node *curr,int d)
{
    if(curr==NULL)
    {
        perror("Empty list!!!\n");
        return;
    }
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=newnode;
    newnode->next=NULL;
}

void delete_from_pos(struct node *curr,int pos)
{
    if(curr==NULL)
    {
        perror("Empty List!!!\n");
        return;
    }
    for(int i=1;i<pos-1;i++)
    {
        curr=curr->next;
    }
    struct node *temp=curr->next;
    curr->next=curr->next->next;
    free(temp);
}

void erase_front(struct node **curr)
{
    struct node *tempnode=(*curr);
    (*curr)=(*curr)->next;
    free(tempnode);
}

int sum(struct node *curr)
{
    int sum=0;
    while(curr!=NULL)
    {
        sum+=curr->data;
        curr=curr->next;
    }
    return sum;
}

int length(struct node *curr)
{
    int l=0;
    while(curr!=NULL)
    {
        l++;
        curr=curr->next;
    }
    return l;
}


struct node* get(struct node *curr,int pos)
{
   int size=length(curr);
   if(pos<1 || pos>size)
   {
       perror("No such element exists in list");
       return NULL;
   }
   for(int i=1;i<pos;i++)
   {
       curr=curr->next;
   }
   return curr;
}

void insert_into_position(struct node *curr,int d,int pos)
{
    if(curr==NULL)
    {
        perror("Empty list!!!\n");
        return;
    }
    struct node *shiftnode;
    for(int i=1;i<pos-1;i++)
    {
        curr=curr->next;
    }
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    shiftnode=curr->next;
    curr->next=newnode;
    newnode->next=shiftnode;
}

void printlist(struct node *curr)
{
    printf("\n");
    printf("LIST VIEW:::\n");
    printf("######################\n");
    int i=1;
    while(curr!=NULL)
    {
       printf("ELEMENT_%d:%d\n",i,curr->data);
       curr=curr->next;
       i++;
    }
}

void bubblesort(struct node *curr)
{
    struct node *counter=curr;
    struct node *column;
    int size=length(curr);
    while(counter!=NULL)
    {
        column=curr;
       for(int i=0;i<size-1;i++)
       {
           if(column->data>column->next->data)
           {
               int newdata=column->data;
               column->data=column->next->data;
               column->next->data=newdata;
           }
           column=column->next;
       }
       counter=counter->next;
    }
    printf("\n");
    printf("LIST AFTER BUBBLESORT:::\n");
    printf("##############################\n");
    printlist(curr);
}

void reverse(struct node *curr)
{
    int *elements;
    elements=(int *)malloc(length(curr) * sizeof(int));
    struct node *temp=curr;
    int i=length(curr)-1;
    while(temp!=NULL)
    {
        *(elements+i)=temp->data;
        i--;
        temp=temp->next;
    }
    i=0;
    while(curr!=NULL)
    {
        curr->data=*(elements+i);
        i++;
        curr=curr->next;
    }
    free(elements);
}

void delete_list(struct node *curr)
{
    struct node *deletenode;
   while(curr!=NULL)
   {
      deletenode=curr;
      curr=curr->next;
      free(deletenode);
   }
}

int main()
{
    int *elements;
    int size=getsize();
    if(size==0)
    {
        perror("No number detected on file\n");
        return 1;
    }
    elements=(int *)malloc(size * sizeof(int));
    readata(elements);
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->data=elements[0];
    head->next=NULL;
    for(int i=1;i<size;i++)
    {
        push_back(head,elements[i]);
    }
    free(elements);
    printf("CHECK_1\n");
    printlist(head);
    printf("CHECK_2\n");
    erase_front(&head);
    printlist(head);
    printf("CHECK_3\n");
    push_front(&head,40);
    printlist(head);
    printf("CHECK_4\n");
    insert_into_position(head,78,5);
    printlist(head);
    printf("CHECK_5\n");
    delete_from_pos(head,3);
    printlist(head);
    printf("CHECK_6\n");
    printf("LENGTH:%d \t SUM:%d\n",length(head),sum(head));
    printf("CHECK_7\n");
    bubblesort(head);
    int pos=6;
    printf("CHECK_8\n");
    struct node *result=get(head,pos);
    if(result!=NULL)
    {
      printf("ELEMENT_%d:%d\n",pos,result->data);
    }
    printf("CHECK_9\n");
    reverse(head);
    printlist(head);
    delete_list(head);
}