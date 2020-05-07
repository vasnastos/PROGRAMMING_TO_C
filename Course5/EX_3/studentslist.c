#include <stdio.h>
#include <stdlib.h>
struct student
{
    int id;
    char *ln;
    double grade;
    struct student *next;
};
int length()
{
    //to be implement
}
void pushback(int id,char *ln,double gr)
{
    //to be implement
}
double average()
{
    //to be implement
}
void delete_student(struct student *curr,int id)
{
    //to implement
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
            //to be implement
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