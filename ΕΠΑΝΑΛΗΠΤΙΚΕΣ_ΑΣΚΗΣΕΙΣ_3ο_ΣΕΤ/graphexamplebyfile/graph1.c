#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char filename[100];

void getsize(int *r,int *c)
{
    *r=0;
    *c=0;
    bool columncount=false;
    FILE *fp=fopen(filename,"r");
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
       if(columncount==false)
       {   
           char *token=strtok(line,",");
           while(token!=NULL)
           {
              (*c)++;
              token=strtok(NULL,",");
           }
           columncount=true;
       }
       (*r)++;
    }
    fclose(fp);
}

void readata(int **pin)
{
    FILE *fp=fopen(filename,"r");
    char line[100];
    int i=0;
    int j;
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
        if(line[strlen(line)-1]=='\n')  
        {
            line[strlen(line)-1]='\0';
        }
       j=0;
       char *token=strtok(line,",");
       if(token[0]=='[')
       {
           for(int i=0;i<strlen(token)-1;i++)
           {
               token[i]=token[i+1];
           }
           token[strlen(token)-1]='\0';
       }
       while(token!=NULL)
       {
         if(token[strlen(token)-1]==']')
         {
            token[strlen(token)-1]='\0';
         }
         pin[i][j]=atoi(token);
         token=strtok(NULL,",");
         j++;
       }
       i++;
    }
    fclose(fp);
}

void findconnectedvertices(int **ad,char *ver,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        bool cnt=false;
        printf("Connected Vertices to %c::",ver[i]);
        for(int j=0;j<col;j++)
        {
            if(ad[i][j]!=0)
            {
              printf("(%c--%d) \t",ver[j],ad[i][j]);
              cnt=true;
            }
        }
        if(cnt==false)
        {
            printf("No vertex from the available vertices\n");
        }
        else
        {
            printf("\n");
        }
    }
}
void find_max_in(int **adj_matrix,char *ver,int row,int col)
{
    int cnt_in[col];
    for(int j=0;j<col;j++)
    {
        cnt_in[j]=0;
        for(int i=0;i<row;i++)
        {
           if(adj_matrix[i][j]!=0)
           {
               cnt_in[j]++;
           }
        }
    }
    int max=cnt_in[0];
    int pos=0;
    for(int i=1;i<col;i++)
    {
       if(cnt_in[i]>max)
       {
           max=cnt_in[i];
           pos=i;
       }
    }
    printf("Vertices with more incomes:%c ",ver[pos]);
    for(int i=0;i<col;i++)
    {
        if(cnt_in[i]==max && i!=pos)
        {
            printf("%c ",ver[i]);
        }
    }
    printf("\n");
}

void delete_data(int **adj,char *m,int row,int c)
{
    for(int i=0;i<row;i++)
    {
        free(adj[i]);
    }
    free(adj);
    free(m);
}

int main()
{
    strcpy(filename,"graph.txt");
    int row,col;
    int **adj_matrix;
    char *vertices;
    getsize(&row,&col);
    printf("ok");
    printf("%d,%d\n",row,col);
    adj_matrix=(int **)malloc(row * sizeof(int *));
    vertices=(char *)malloc(row * sizeof(char));
    for(int i=0;i<row;i++)
    {
        adj_matrix[i]=(int *)malloc(col * sizeof(int));
        vertices[i]='A'+i;
    }
    readata(adj_matrix);
    findconnectedvertices(adj_matrix,vertices,row,col);
    find_max_in(adj_matrix,vertices,row,col);
    delete_data(adj_matrix,vertices,row,col);
}