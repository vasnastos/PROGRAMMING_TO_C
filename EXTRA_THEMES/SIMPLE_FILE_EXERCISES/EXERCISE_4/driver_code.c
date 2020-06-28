#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s 200

//------------------------------
void read_copyrights()
{
    char line[s];
    FILE *fp=fopen("copyrights.txt","r");
    while(fgets(line,s,fp)!=NULL)
    {
        printf("%s",line);
    }
    fclose(fp);
}
//------------------------------
char fn[s];

typedef struct
{
    char des[s];
    double *elements;
}lined;

int get_row_size()
{
    int counter=0;
    char line[s];
    FILE *fp=fopen(fn,"r");
    if(fp==NULL)
    {
        return 0;
    }
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        counter++;
    }
    fclose(fp);
    return counter;
}

void  get_column_size(int *scol)
{
    char line[s];
    FILE *fp=fopen(fn,"r");
    int i=0;
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        char *token=strtok(line,",");
        scol[i]=0;
        while(token!=NULL)
        {
            scol[i]++;
            token=strtok(NULL,",");
        }
        i++;
    }
    fclose(fp);
}

void read_data(lined *lines)
{
    char line[s];
    int i=0;
    FILE *fp=fopen(fn,"r");
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        char *token=strtok(line,",");
        int j=0;
        while(token!=NULL)
        {
            lines[i].elements[j]=atof(token);
            j++;
            token=strtok(NULL,",");
        }
        i++;
    }
    fclose(fp);
}

double find_sum(lined *lines,int i,int size)
{
    double sm=0.0;
    for(int j=0;j<size;j++)
    {
        sm+=lines[i].elements[j];
    }
    return sm;
}

double find_average(lined *lines,int i,int size)
{
    return find_sum(lines,i,size)/size;
}

void save_results(lined *lines,int size,int *scol)
{
    fflush(stdin);
    char filename[s];
    printf("Give filename you want to save data:");
    gets(filename);
    FILE *fp=fopen(filename,"w");
    fprintf(fp,"DATA THAT BEEN RETRIVIED FROM FILE::\n\n");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"Line %d:SUM:%.2lf\tAVERAGE:%.2lf\n",i+1,find_sum(lines,i,scol[i]),find_average(lines,i,scol[i]));
    }
    fclose(fp);
}

void show_line(lined *lines,int pos,int scol)
{
    printf("####LINE SHOW ####\n");
    for(int i=0;i<scol;i++)
    {
        printf("Element %d:%.2lf\n",i+1,lines[pos].elements[i]);
    }
    printf("##################\n");
}

int make_main_menu()
{
    int choice;
    printf("Main Menu:::\n");
    printf("1-Load data\n");
    printf("2-Save data\n");
    printf("3-Find line sum\n");
    printf("4-find line average\n");
    printf("5-show line elements\n");
    printf("6-Clear contents\n");
    printf("7-exit\n");
    printf("Give choice:");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    lined *lines=NULL;
    int *sizecol=NULL;
    int getch;
    int size;
    int pos;
    while(1)
    {
        getch=make_main_menu();
        if(getch==1)
        {
            fflush(stdin);
            printf("Give filename:");
            gets(fn);
           size=get_row_size();
           if(size==0)
           {
               exit(EXIT_FAILURE);
           }
           lines=(lined *)malloc(size *sizeof(lined));
           sizecol=(int *)malloc(size * sizeof(int));
           get_column_size(sizecol);
           for(int i=0;i<size;i++)
           {
               lines[i].elements=(double *)malloc(sizecol[i] * sizeof(double));
           }
           read_data(lines);
        }
        else if(getch==2)
        {
            if(lines==NULL)
           {
               perror("Please load a file\n");
               continue;
           }
           save_results(lines,size,sizecol);
        }
        else if(getch==3)
        {
           if(lines==NULL)
           {
               perror("Please load a file\n");
               continue;
           }
           printf("Give line you want to accumulate:");
           scanf("%d",&pos);
           if(pos<0 || pos>size)
           {
               perror("No such line exist on file\n");
               continue;
           }
           pos--;
           printf("\n####RESULT####\n");
           printf("Sum of line_%d=%.2lf\n",pos+1,find_sum(lines,pos,sizecol[pos]));
           printf("################\n\n");
        }
        else if(getch==4)
        {
           if(lines==NULL)
           {
               perror("Please load a file\n");
               continue;
           }
           printf("Give line you want to find average:");
           scanf("%d",&pos);
           if(pos<0 || pos>size)
           {
               perror("No such line exist on file\n");
               continue;
           }
           pos--;
           printf("\n####RESULT####\n");
           printf("Average of line_%d=%.2lf\n",pos+1,find_average(lines,pos,sizecol[pos]));
           printf("################\n\n");
        }
        else if(getch==5)
        {
           if(lines==NULL)
           {
               perror("Please load a file\n");
               continue;
           }
           printf("Give line you want to show:");
           scanf("%d",&pos);
           pos--;
           if(pos<0 || pos>size)
           {
               perror("No such line exist on file\n");
               continue;
           }
           show_line(lines,pos,sizecol[pos]);
        }
        else if(getch==6)
        {
            if(lines==NULL)
            {
                printf("Choose a file you did not load one please try again!!!");
                continue;
            }
            free(sizecol);
            for(int i=0;i<size;i++)
            {
                free(lines[i].elements);
            }
            free(lines);
            lines=NULL;
            sizecol=NULL;
        }
        else if(getch==7)
        {
            free(sizecol);
            for(int i=0;i<size;i++)
            {
                free(lines[i].elements);
            }
            free(lines);
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("Invalid choice please try agoain!!!");
        } 
    }
}