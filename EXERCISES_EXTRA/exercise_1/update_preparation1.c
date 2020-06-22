#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define s 200

void read_copyright()
{
    printf("##########################\n");
    char line[s];
    FILE *cop=fopen("copyright.txt","r");
    while(fgets(line,s,cop)!=NULL)
    {
        printf("%s",line);
    }
    fclose(cop);
    printf("############################\n");
    printf("\n");
}

char filename[s];

typedef struct
{
    char cityname[s];
    double *citytemp;
}temperature;

int getsize()
{
    char line[s];
    int counter=0;
    FILE *fp=fopen(filename,"r");
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

void get_sum_temp_by_city(int *a)
{
    int i=0;
    char line[s];
    FILE *temp=fopen(filename,"r");
    while(fgets(line,s,temp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        int counter=0;
        char *token=strtok(line,",");
        token=strtok(NULL,",");
        while(token!=NULL)
        {
            counter++;
            token=strtok(NULL,",");
        }
        a[i]=counter;
        i++;
    }
    fclose(temp);
}

void read_data(temperature *temps)
{
    char line[s];
    int i=0;
    int j;
    FILE *temp=fopen(filename,"r");
    while(fgets(line,s,temp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        j=0;
        char *fetch=strtok(line,",");
        strcpy(temps[i].cityname,fetch);
        fetch=strtok(NULL,",");
        while(fetch!=NULL)
        {
            temps[i].citytemp[j]=atof(fetch);
            fetch=strtok(NULL,",");
            j++;
        }
        i++;
    }
    fclose(temp);
}

void get_cities_average_temp(temperature *temps,double *avg,int *col,int size)
{
   for(int i=0;i<size;i++)
   {
       avg[i]=0.0;
       for(int j=0;j<col[i];j++)
       {
           avg[i]+=temps[i].citytemp[j];
       }
       avg[i]/=col[i];
   }
}

void cities_below_and_under(double *avg,int size,int *below,int *under)
{
    (*below)=0;
    (*under)=0;
   for(int i=0;i<size;i++)
   {
      if(avg[i]>0)
      {
          (*under)++;
      }
      if(avg[i]<0)
      {
          (*below)++;
      }
   }
}


void delete_db_boards(temperature *tms,int *col,int size)
{
    for(int i=0;i<size;i++)
    {
        free(tms[i].citytemp);
    }
    free(col);
    free(tms);
}

int main()
{
    read_copyright();
    printf("Give filename:");
    gets(filename);
    int size=getsize();
    int *colsize;
    temperature *temps;
    if(size==0)
    {
        perror("No such file found\n");
        exit(EXIT_FAILURE);
    }
    printf("FILE LOADING");
    for(int i=0;i<5;i++)
    {
        printf("....");
        Sleep(500);
    }
    printf("\n\n");
    printf("File loading complete!!!!!!!\n");
    temps=(temperature *)malloc(size * sizeof(temperature));
    colsize=(int *)malloc(size * sizeof(int));
    get_sum_temp_by_city(colsize);
    for(int i=0;i<size;i++)
    {
        temps[i].citytemp=(double *)malloc(colsize[i] * sizeof(double));
    }
    read_data(temps);
    printf("DATA LOADING");
    for(int i=0;i<5;i++)
    {
        printf("....");
        Sleep(500);
    }
    double *average=(double *)malloc(size * sizeof(double));
    printf("\n\n");
    printf("Data loading complete!!!!!!!\n");
    printf("AVERAGE PER CITY\n");
    printf("###################################\n");
    get_cities_average_temp(temps,average,colsize,size);
    for(int i=0;i<size;i++)
    {
        printf("AVERAGE OF CITY:%s is:%.2lf\n",temps[i].cityname,average[i]);
        if(average[i]>0.0)
        {
            printf("TEMPARATURE OVER 0\n");
        }
        else if(average[i]<0.0)
        {
            printf("TEMPARATURE BELOW 0\n");
        }
        printf("\n");
    }
    printf("###################################\n");
    printf("\nSUMMARY OVERALL\n");
    printf("###################################\n");
    int over,below;
    cities_below_and_under(average,size,&below,&over);
    double averageover=((double)over/size)*100.0;
    double averagebelow=((double)below/size)*100.0;
    printf("%.2lf percent of cities have average temparature over 0\n",averageover);
    printf("%.2lf percent of cities have average temparature below 0\n",averagebelow);
    printf("###################################\n");
    free(average);
    delete_db_boards(temps,colsize,size);
}