//να γραφεί πρόγραμμα που να ανοίγει ένα αρχείο,να αποθηκεύει τους αριθμούς του σε ένα δυναμικό
//πίνακα και έπειτα μέσω συνάρτησης να υπολογίζει τον μέσο όρο του αρχείου
//extra-->Να γραφεί κομμάτι κώδικα που θα εκτυπώνει τον μέσο όρο στο αρχείο
#include <stdio.h>
#include <stdlib.h>
double average(int *p,int size)
{
   int s=0;
   for(int i=0;i<size;i++)
   {
       s+=*(p+i);
   }
   return (double)s/size;
}
int main()
{
   int *pin;
   FILE *fp;
   int num,size=0;
   fp=fopen("data.txt","r");
   if(fp==NULL)
   {
       printf("file couldn't open\n");
       return 0;
   }
   while(fscanf(fp,"%d",&num)>0)
   {
       size++;
   }
   fclose(fp);//όταν εκτελώ μία ενέργεια και έχω προσπελάσει το αρχείο πάντα κλείνω το αρχείο!!!
   pin=(int *)malloc(size * sizeof(int));
   int i=0;
   fp=fopen("data.txt","r");//άμα θέλω να ξαναπροσπελάσω το αρχείο το ξαναανοίγω
   while(fscanf(fp,"%d",&num)>0)
   {
       pin[i]=num;
       i++;
   }
   printf("Average from file data numbers=%.2lf\n",average(pin,size));
   fclose(fp);
   free(pin);
}