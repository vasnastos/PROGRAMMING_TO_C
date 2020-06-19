#include <stdio.h>
#include <stdlib.h>

//Να διαβαστεί το αρχείο και να βρεθεί ο μέσος όρος τον αριθμών που περιεχεί καθώς και πόσοι αριθμοί
//είναι μεγαλύτερη ενός αριθμού Ν(Είσοδος από τον χρήστη).

int main()
{
    int size=0;
    int counter=0;
    double average=0.0;
    double N;
    char filename[100];
    printf("Give filename:");//Διάβασμα ονόματος αρχείου
    gets(filename);
    printf("Give Number:");//Διάβασμα αριθμού
    scanf("%lf",&N);
    double number;
    FILE *fp=fopen(filename,"r");//Άνοιγμα αρχείου
    while(fscanf(fp,"%lf",&number)>0)
    {
        average+=number;
        size++;
        if(number>N)
        {
            counter++;
        }
    }
    fclose(fp);
    average/=size;
    //printf("Average:%.2lf\n",average);
    //printf("%d numbers over number %.2lf\n",counter,N);
    //Εκτύπωσε τα αποτελέσμα(μο πλήθος) στο ίδιο αρχείο.
    fp=fopen(filename,"a");
    fprintf(fp,"Average:%.2lf\n",average);
    fprintf(fp,"%d numbers over number %.2lf\n",counter,N);
    fclose(fp);
}