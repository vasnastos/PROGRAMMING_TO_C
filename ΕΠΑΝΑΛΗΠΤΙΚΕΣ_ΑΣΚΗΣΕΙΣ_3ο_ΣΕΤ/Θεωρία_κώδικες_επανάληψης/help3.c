#include <stdio.h>
#include <stdio.h>

void findelements(int *pin,int size,int *max,int *min,double *avg)
{
    //Εύρεση πολλαπλών δεδομένων και χρήση τους στην main με την την χρήση μίας συνάρτησης
    int sum=pin[0];
    *max=pin[0];
    *min=pin[0];
    for(int i=1;i<size;i++)
    {
        if(pin[i]>*max)
        {
            *max=pin[i];
        }
        if(pin[i]<*min)
        {
            *min=pin[i];
        }
        sum+=pin[i];
    }
    *avg=(double)sum/size;
}

int main()
{
    int *a;//Δήλωση δείκτης
    int x=2;
    a=&x;//Ο δείκτης a δείχνει στην μεταβλητή x.
    int *b=(int *)malloc(sizeof(int));//Δυναμική δέσμευση μνήμης για δείκτη.
    *b=56;//Περιεχόμενο της θέσης μνήμης που δείχνει ο δείκτης περιέχει την τιμή 56.
    printf("%d",*b);//56
    printf("%d",*a);//2
    free(a);
    free(b);

    int pin[10]={45,23,67,89,1,2,5,32,9,12};
    int max,min;
    double avg;
    findelements(pin,10,&max,&min,&avg);
    printf("Max=%d \t Min=%d \t Avg=%.lf\n",max,min,avg);
}