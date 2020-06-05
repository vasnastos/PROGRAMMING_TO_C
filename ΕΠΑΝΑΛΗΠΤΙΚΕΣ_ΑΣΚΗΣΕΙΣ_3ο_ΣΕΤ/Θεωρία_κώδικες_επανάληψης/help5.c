#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Δήλωση δομής
typedef struct 
{
    char brand[100];
    char model[100];
    double price;
}car;

//Διάβασμα τιμών από δομή
void readdata(car *cars,int size)
{
    for(int i=0;i<size;i++)
    {
        fflush(stdin);
        printf("Give brand of car_%d:",i+1);
        gets(cars[i].brand);
        printf("Give model of car_%d:",i+1);
        gets(cars[i].model);
        printf("Give price of car_%d:",i+1);
        scanf("%lf",&cars[i].price);
    }
}

//Ταξινόμιση πίνακα αυτοκινήτων με βάση την τιμή
void sort_by_price(car *cars,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(cars[j]>cars[j+1])
            {
                car temp=cars[j];
                cars[j]=cars[j+1];
                cars[j+1]=temp;
            }
        }
    }
}

int main()
{
    //Δυναμική δέσμευση μνήμης για πίνακα 10 θέσεων που περιέχει στοιχεία τύπου car
    car *cars=(car *)malloc(10 * sizeof(car));
    readdata(cars,10);
    sort_by_price(cars,10);
    //Εκτύπωση τιμών πίνακα που περιέχει στοιχεία τύπου car.
    for(int i=0;i<10;i++)
    {
        printf("BRAND:%s\t",cars[i].brand);
        printf("MODEL:%s\t",cars[i].model);
        printf("PRICE:%s\n",cars[i].price);
    }

    //Αποδέσμευση μνήμης
    free(cars);
}