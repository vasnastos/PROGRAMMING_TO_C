#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename[100];

struct node 
{
    double d;
    struct node *next;
};

int get_size()
{
    int counter=0;
    char line[100];
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return 0;
    }
    while(fgets(line,100,fp)!=NULL)
    {
      if(line[0]=='#') continue;
      if(line[0]=='\n') continue;

      counter++;
    }
    fclose(fp);
    return counter;
}

void read_data(double *data)
{
    int i=0;
    char line[100];
    FILE *fp=fopen(filename,"r");
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        data[i]=atof(line);
        i++;
    }
    fclose(fp);
}

int length(struct node *curr)
{
    int counter=0;
    while(curr!=NULL)
    {
       counter++;
       curr=curr->next;
    }
    return counter;
}

void push_back(struct node *curr,double newdata)
{
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->d=newdata;
    newnode->next=NULL;
    curr->next=newnode;
}

void push_front(struct node **curr,double newdata)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->d=newdata;
    newnode->next=(*curr);
    (*curr)=newnode;
}

void insert_into_position(struct node *curr,int pos,double newdata)
{
    if(pos<0 || pos>length(curr))
    {
        perror("Invalid position!!!!\n");
        return;
    }
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->d=newdata;
    for(int i=1;i<pos;i++)
    {
        curr=curr->next;
    }
    struct node *after=curr->next;
    curr->next=newnode;
    newnode->next=after;
}

void printlist(struct node *curr)
{
    int i=1;
    FILE *fp=fopen(filename,"a");
    fprintf(fp,"\n");
    fprintf(fp,"LIST VIEW\n");
    while(curr!=NULL)
    {
        fprintf(fp,"ELEMENT_%d:%.2lf\n",i,curr->d);
        i++;
        curr=curr->next;
    }
    fprintf(fp,"\n");
    fclose(fp);
}

void delete_list(struct node *curr)
{
    while(curr!=NULL)
    {
        struct node *temp=curr;
        curr=curr->next;
        free(temp);
    }
}

int main(int argc,char **argv)
{
    strcpy(filename,"numbers.txt");
    if(argc!=4)
    {
        perror("invalid number of arguments!!!|||Please try again");
        exit(EXIT_FAILURE);
    }
    double number_pushfront=atof(argv[1]);
    char cpy[100];
    strcpy(cpy,argv[2]);
    char *token=strtok(cpy,"-");
    int posinsert=atoi(token);
    token=strtok(NULL,"-");
    double valinsert=atof(token);
    double valpush=atof(argv[3]);
    int size=get_size();
    if(size==0)
    {
        perror("No valid arguments find in file\n");
        exit(EXIT_FAILURE);
    }
    double *numbers=(double *)malloc(size * sizeof(double));
    read_data(numbers);
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->d=numbers[0];
    head->next=NULL;
    for(int i=1;i<size;i++)
    {
        push_back(head,numbers[i]);
    }
    printlist(head);
    push_front(&head,number_pushfront);
    printlist(head);
    insert_into_position(head,posinsert,valinsert);
    printlist(head);
    push_back(head,valpush);
    printlist(head);
    delete_from_pos(head,6);
    printlist(head);
    delete_list(head);
}