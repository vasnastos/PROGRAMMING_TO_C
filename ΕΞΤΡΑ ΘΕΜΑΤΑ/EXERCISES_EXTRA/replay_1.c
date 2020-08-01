/*
Να γραφεί πρόγραμμα που θα διαβάζει από ένα αρχείο γραμμές και αριθμούς τυχαίους
και να υπολογίζει τον μέσο όρο το άθροισμα και να εμφανίζει το στοιχεία μίας γραμμής
*/
#include <stdio.h>
#include <stdlib.h>
#define s 200

char filename[s];

typedef struct 
{
    char des[s];
    double *numbers;
}random;

int get_row()
{
    char line[s];
    int i=0;
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return;
    }
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
        i++;
    }
    fclose(fp);
    return i;
}

void get_size(int *cols)
{
    char line[s];
    int i=0;
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return;
    }
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
        char *token=strtok(line,"-");
        cols[i]=0;
        while(token!=NULL)
        {
            cols[i]++;
            token=strtok(NULL,"-");
        }
        i++;
    }
    fclose(fp);
}

void read_data(random *nums)
{
    char line[s];
    int i=0;
    FILE *fp=fopen(filename,"r");
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        char *token=strtok(line,"-");
        int j=0;
        while(token!=NULL)
        {
            nums[i].numbers[j]=atoi(token);
            j++;
            token=strtok(NULL,"-");
        }
        i++;
    }
    fclose(fp);
}

double find_sum(random *nums,int size,char *des,int *cols)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(strcmp(nums[i].des,des)==0)
        {
            pos=i;
        }
    }
    if(pos==-1)
    {
        printf("Record with description %s did not found!!!!\n",des);
        return;
    }
    double sum_line=0.0;
    for(int j=0;j<cols[pos];j++)
    {
        sum_line+=nums[pos].numbers[j];
    }
    return sum_line;
}

double average(random *nums,int size,char *des,int *cols)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(strcmp(nums[i].des,des)==0)
        {
            pos=i;
        }
    }
    if(pos==-1)
    {
        printf("Record with description %s did not found!!!!\n",des);
        return;
    }
    double sum_line=0.0;
    for(int j=0;j<cols[pos];j++)
    {
        sum_line+=nums[pos].numbers[j];
    }
    return sum_line/cols[pos];
}

void show(random *nums,int size,char *des,int *cols)
{
    int found=0;
    for(int i=0;i<size;i++)
    {
        if(strcmp(nums[i].numbers,des)==0)
        {
            printf("RECORD %s:::\n",nums[i].des);
            for(int j=0;j<cols[i];j++)
            {
                printf("ELEMENT_%d:%.2lf\n",j+1,nums[i].numbers[j]);
            }
            return;
        }
    }
    if(found==0)
    {
        printf("Record %s did not found\n",des);
    }
}

int make_menu()
{
    int ch;
    printf("Main_Menu:::\n");
    printf("1-READ BE FILE\n");
    printf("2-FIND SUM OF DEPARTMENT\n");
    printf("3-FIND AVERAGE SALARY OF DEPARTMENT\n");
    printf("4-SHOW SALARIES OF DEPARTMENT\n");
    printf("5-EXIT\n");
    printf("Give choice:");
    scanf("%d",&ch);
    return ch;
}

int main()
{
    int size=0;
    random *nums=NULL;
    int *columns=NULL;
    char desc[200];
    while(1)
    {
        int c=make_menu();
        if(c==1)
        {
            size=get_row();
            if(size==0)
            {
                printf("File din not found!!\n");
                exit(EXIT_FAILURE);
            }
            get_size(columns);
            nums=(random *)malloc(size * sizeof(random));
            columns=(int *)malloc(size * sizeof(int));
        }
        else if(c==2)
        {
            if(nums==NULL)
            {
                perror("no valid records please try to add some");
                return;
            }
            printf("Give record description:");
            gets(desc);
            printf("Sum of line:%s is:%.2lf\n",desc,find_sum(nums,size,desc,columns));
        }
        else if(c==3)
        {
            if(nums==NULL)
            {
                perror("no valid records please try to add some");
                return;
            }
            printf("Give record description:");
            gets(desc);
            printf("Average of line:%s is:%.2lf\n",desc,average(nums,size,desc,columns));
        }
        else if(c==4)
        {
             if(nums==NULL)
            {
                perror("no valid records please try to add some");
                return;
            }
            printf("Give record description:");
            gets(desc);
            printf("Record %s info::\n",desc);
            show(nums,size,desc,columns);
        }
        else if(c==5)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            free(nums);
            free(columns);
            exit(EXIT_SUCCESS);
        }
    }
}