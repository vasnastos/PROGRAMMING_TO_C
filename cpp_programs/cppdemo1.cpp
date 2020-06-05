//Εκτύπωση μέσου όρου ενός πίνακα μονοδιάστατου και μέγιστου στοιχείου
//με δυναμική δέσμευση μνήμης
#include <iostream>
#include <cstdlib>
double average(int *a,int size,int &max)
{
    //call by reference
    double mo;
    int sum=a[0];
    max=a[0];
    for(int i=1;i<size;i++)
    {
        sum+=a[i];
        if(a[i]>max) max=a[i];
    }
    mo=(double)sum/size;
    return mo;
}

int main()
{
    int size;
    std::cout<<"Give size of board:";
    std::cin>>size;
    int *a=new int[size];
    //a=(int *)malloc(size * sizeof(int))
    for(int i=0;i<size;i++)
    {
       std::cout<<"a["<<i<<"]:";//Εκτύπωση ενός μηνύματος
       std::cin>>a[i];
    }
    int max;
    std::cout<<"Average:"<<average(a,size,max)<<std::endl;
    std::cout<<"Max:"<<max<<std::endl;
    delete[] a;
}