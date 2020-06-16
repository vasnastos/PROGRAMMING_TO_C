#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define s 10
typedef struct
{
   char cityname[100];
   int population;//long long-->size_t
}town;

void find_by_name(town *towns,int size)
{
   char name[100];
   double pr;
   fflush(stdin);
   printf("Give city name:");
   gets(name);//Διάβασμα αλφαριθμητικού
   printf("Give percent of population raise:");
   scanf("%lf",&pr);//3.5
   //Εύρεση του name στον πίνακα
   //Έλεγχος εύρεσης στοιχείου σε πίνακα.
   int found=0;
   for(int i=0;i<size;i++)
   {
      if(strcmp(name,towns[i].cityname)==0)
      {
         towns[i].population+=(towns[i].population *pr)/100;//towns[i].population=towns[i].population+(towns[i].population *pr)
         found=1;//Το στοιχείο name βρέθηκε
      }
   }
   if(found==0)//Το στοιχείο name δεν βρέθηκε
   {
       printf("city %s does not exist in the table\n",name);
   }
}

void sort(town *towns,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(towns[j].population<towns[j+1].population)
            {
                town temp=towns[j];
                towns[j]=towns[j+1];
                towns[j+1]=temp;
            }
        }
    }
}

int main()
{
    town towns[10];
    //Διάβασμα στοιχείων
    for(int i=0;i<10;i++)
    {
        printf("Give details for city %d:::",i+1);
        fflush(stdin);
        printf("Give city name:");
        gets(towns[i].cityname);
        printf("give city population:");
        scanf("%d",&towns[i].population);
    }
    //Εμφάνιση αποτελεσμάτων σε αρχείο
    FILE *fp;
    char filename[100];
    //Διάβασμα ονόματος αρχείου.
    fflush(stdin);
    printf("Give filename:");
    gets(filename);
    fp=fopen(filename,"w");
    find_by_name(towns,10);
    sort(towns,10);
    //Συνάρτηση εκτύπωσης σε αρχείο
    for(int i=0;i<10;i++)
    {
        fprintf(fp,"Town %d:NAME%s: \t POPULATION:%d\n",i+1,towns[i].cityname,towns[i].population);
    }
    fclose(fp);
}