#include <stdio.h>
#include <stdlib.h>
struct student
{
    int id;
    char *ln;
    double grade;
    struct student *next;
};
int length(struct student *curr)
{
    if(curr==NULL)
    {
        perror("No list detected!!\n");
        return 0;
    }
    int cnt=0;
    while(curr!=NULL)
    {
        cnt++;
        curr=curr->next
    }
    return cnt;
}
void pushback(struct student *curr,struct student *newstudent)
{
    int i=0;
    int j=length(curr);
    while(i<j)
    {
        curr=curr->next;
        i++;
    }
    curr->next=newstudent;
    newstudent->next=NULL;
}
double average(struct student *curr)
{
    int size=length(curr);
    double avg=0.0;
    while(curr!=NULL)
    {
        avg+=curr->grade;
        curr=curr->next;
    }
    return avg/size;
}
void delete_student(struct student *curr,int id)
{
    struct student *temp=curr;
    int pos=-1;
    int i=0;
    while(temp!=NULL)
    {
        if(curr->id==id)
        {
            pos=i;
        }
        remp=temp->next;
        i++;
    }
    if(pos==-1)
    {
        perror("NO SUCH ID EXISTS!!!\n");
        return;
    }
    struct student *prev;
    for(int j=1;j<pos;j++)
    {
        prev=curr;
        curr=curr->next;
    }
    struct student *del=curr;
    prev->next=curr->next;
    free(del);
}
void printlist(struct student *curr)
{
    printf("LIST::\n");
   while(curr!=NULL)
   {
       printf("ID:%d--LESSON:%s--GRADE:%.2lf\n",curr->id,curr->ln,curr->grade);
       curr=curr->next;
   }
}
void readstudent(student *s)
{
    printf("Give students id:");
    scanf("%d",&s.id);
    fflush(stdin);
    s.ln=(char *)malloc(ms * sizeof(char));
    printf("Give lesson name:");
    gets(s.ln);
    printf("Give grade of %d in lesson %s:",s.id,s.ln);
    scanf("%lf",&s.grade);
}
void deletelist(struct node *current)
{
    while(curr!=NULL)
    {
        struct node *temp=curr;
        curr=curr->next;
        free(temp);
    }
}
int main()
{
    struct student *head;
    head=(struct student *)malloc(sizeof(struct));
    readstudent(head);
    head->next=NULL;
    int choice;
    while(1)//εκχώρηση στοιχείων στην λίστα
    {
        printf("Insert student?:(0:no|1:yes):");
        scanf("%d",&choice);
        if(choice==1)
        {
            struct student *st;
            st=(struct student *)malloc(sizeof(struct student));
            readstudent(st);
            pushback(head,st);
        }
        else if(choice==0)
        {
            break;
        }
        else
        {
            printf("invalid choice please try again!!\n");
        }
    }
    printf("check 1(length)");
    printf("Length:%d\n",length());
    printf("check2(pushback):\n");
    struct student sd;
    readstudent(&sd);
    pushback(&sd);
    printlist(head);
    printf("Check 3(Average:):%.3lf\n",average(head));
    printf("Check4(delete at position 2):\n");
    delete_student(head,3);
    printlist(head);
    deletelist(head);   
}