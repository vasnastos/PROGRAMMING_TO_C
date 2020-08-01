#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename[100];

typedef struct
{
    int homesize;
    int awaysize;
}score;


int get_size()
{
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return 0;
    }
    int cnt=0;
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
       if(line[0]=='#') continue;
       if(line[0]=='\n') continue;
       
       cnt++;
    }
    fclose(fp);
    return cnt;
}

void read_data(score *scores,int *cnthome,int *cntaway,int *tie)
{
    (*cnthome)=0;
    (*cntaway)=0;
    (*tie)=0;
    char line[100];
    int i=0;
    FILE *fp=fopen(filename,"r");
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#') continue;
       if(line[0]=='\n') continue;
       
       char *token=strtok(line,"-");
       if(token==NULL) continue;
       scores[i].homesize=atoi(token);
       token=strtok(NULL,"-");
       if(token==NULL) continue;
       scores[i].awaysize=atoi(token);
       if(scores[i].homesize>scores[i].awaysize)
       {
           (*cnthome)++;
       }
       else if(scores[i].homesize<scores[i].awaysize)
       {
           (*cntaway)++;
       }
       else
       {
           (*tie)++;
       }
       i++;
    }
    fclose(fp);
}

void print_score(const score *sc)
{
    printf("RESULT:%d-%d\n",sc->homesize,sc->awaysize);
    if(sc->homesize>sc->awaysize)
    {
        printf("Home wins\n");
    }
    else if(sc->homesize<sc->awaysize)
    {
        printf("Away wins\n");
    }
    else 
    {
        printf("Tie game\n");
    }
    printf("\n");
}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("No filename inserted please try again\n");
        exit(EXIT_FAILURE);
    }
    strcpy(filename,argv[1]);
    int size=get_size();
    if(size==0)
    {
        perror("the file does not exist");
        exit(EXIT_FAILURE);
    }
    score *scores=(score *)malloc(size * sizeof(score));
    int h,a,t;
    read_data(scores,&h,&a,&t);
    printf("########RESULTS########\n");
    printf("\n");
    for(int i=0;i<size;i++)
    {
        print_score(scores+i);
    }
    printf("Home wins=%d\n",h);
    printf("Away wins=%d\n",a);
    printf("Tie games=%d\n",t);
    printf("########################\n");
    free(scores);
}