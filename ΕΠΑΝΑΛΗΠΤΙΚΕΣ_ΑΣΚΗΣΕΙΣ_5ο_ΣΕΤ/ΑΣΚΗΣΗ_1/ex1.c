#include <stdio.h>
#include <stdlib.h>
//#define s 10
#include <math.h>

void function(int *a,int size,double *avg,int *posmax,int *counter)
{
    int max=a[0];
    int sum=0;
    (*posmax)=0;
    (*counter)=0;
    for(int i=0;i<size;i++)
    {
        sum+=a[i];
        if(a[i]>max)
        {
            //a[i]=max
            max=a[i];
            *posmax=i;
        }
    }
    *avg=(double)sum/size*1.0;
    for(int i=0;i<size;i++)
    {
        if(a[i]>sqrt(sum))
        {
            (*counter)++;
        }
    }
}

int main()
{
    int d;
   int pin[10]={0};
   //Δυναμική δέσμευση μνήμης-->int *pin=(int *)malloc(10 * sizeof(int))
   char filename[100];
   printf("Give filename:");
   gets(filename);//Διάβασμα αλφαριθμητικού.
   FILE *fp=fopen(filename,"r");
   if(fp==NULL)
   {
       printf("File does not exist\n");
       //free(pin)
       exit(1);//return 0;
   }
   //Διάβασμα δεδομένων από αρχείο.
   char line[200];
   int i=0;
   while(fgets(line,200,fp)!=NULL)
   {
       if(line[0]=='\n')
       {
           continue;
       }
       if(line[0]=='#')
       {
           continue;
       }
       char *token=strtok(line,":");
       token=strtok(NULL,":");
       int number=atoi(token);
       if(i>=10)
       {
           break;
       }
       if(number%2==0 || number%3==0)
       {
           pin[i]=number;
           i++;
       }
   }
   fclose(fp);
   double average;
   int posmax,cnt;
   function(pin,10,&average,&posmax,&cnt);
   printf("Posmax:&d\n",posmax);
   printf("AVERAGE:%.2lf\n",average);
   printf("OVER SUM OF BOARD SQRT:%d\n",cnt);
   //Για δυναμικό πίνακα free(pin).
}