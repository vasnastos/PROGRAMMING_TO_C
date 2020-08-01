//Διάβασμα αρχείου με προιόντα -τιμές και εκτύπωση σε αρχείο της μέσης τιμής και της λίστας των προιόντων ταξινομημένα
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
int read_data(double *price)
{
    FILE *fptr;
    char filename[20];
    printf("Give filename:");
    gets(filename);
    int linecount=0;
    fptr=fopen(filename,"r");
    char line[100];
    while(fgets(line,100,fptr)!=NULL)
    {
        linecount++;
    }
    fclose(fptr);
    printf("Read data complete\n");
    return linecount;
}
void fill_data(char n[][maxsize],double *p,int s)
{
    FILE *fp;
    char line[maxsize];
    int j=0;
    char fn[maxsize];
    printf("give filename(fill data):");
    gets(fn);
    fp=fopen(fn,"r");
    while(fgets(line,maxsize,fp)!=NULL)
    {
       if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
       char w1[maxsize];
       int c1=0;
       char w2[maxsize];
       int c2=0;
       int cnt=0;
       for(int i=0;i<strlen(line);i++)
       {
         if(line[i]=='-') cnt++;
         else if(line[i]!='-' && cnt==0)
         {
             w1[c1]=line[i];
             c1++;
         }
         else if(line[i]!='-' && cnt==1)
         {
             w2[c2]=line[i];
             c2++;
         }
         else{
             printf("wrong input data\n");
             break;
         }
       }
       w1[c1]='\0';
       w2[c2]='\0';
       strcpy(n[j],w1);
       p[j]=atof(w2);
       j++;
    }
    printf("ENROLL:%d\n",j);
    fclose(fp);
}
void sort(char nam[][maxsize],double *pr,int s)
{
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s-1;j++)
        {
            //bubblesort(Sort algorithm)
            if(pr[j]>pr[j+1])
            {
                double t=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=t;
                char temp[maxsize];
                strcpy(temp,nam[j]);
                strcpy(nam[j],nam[j+1]);
                strcpy(nam[j+1],temp);
            }
        }
    }
}
double getaverageprice(double *pr,int s)
{
    double sum=0.0;
    for(int i=0;i<s;i++)
    {
        sum+=pr[i];
    }
    return sum/s;
}
void savetofile(char n[][maxsize],double *p,int s)
{
    FILE *fp;
    char name[20];
    printf("Give filename(save data):");
    gets(name);
    fp=fopen(name,"w");
    fprintf(fp,"LIST OF PRODUCTS\n");
    for(int i=0;i<s;i++)
    {
        fprintf(fp,"PRODUCT_%d:%s\t price:%.2lf\n",i+1,n[i],p[i]);
    }
    fprintf(fp,"Average price:%.2lf\n",getaverageprice(p,s));
    fclose(fp);
    printf("Product list has been saved\n");
}
void allocate(double *p)
{
    free(p);
}
void run()
{
    double *price;
    int size=read_data(price);
    price=(double *)malloc(size * sizeof(double));
    char names[size][maxsize];
    fill_data(names,price,size);
    sort(names,price,size);
    savetofile(names,price,size);
    allocate(price);
}
int main()
{
    run();
}