#include <stdio.h> //Εντολή προς προεπεξεργαστή
//Εισάγω στο πρόγραμμα περιεχόμενα του αρχείου stdio.(Περιέχει δηλώσεις για να χρησιμοποιήσω εντολές)
//Π.Χ printf!!!!
//#pragma once advance.h
//preprocessors->Δίνουν οδηγίες στον compiler
//πριν την μεταγλώττιση του προγράμματος
#define max(a,b) a>b?a:b //Μακροεντολή
#define sum(a,b) a+b  //Μακροεντολή
#define min(a,b) a<b?a:b //Μακροεντολή
#define string char *
#define print(dn) printf("%.2lf\n",dn)
//Preprocessor(test1.c)-->compiler(Κώδικας μηχανής)(test1.o)-->Linker(Βιβλιοθήκες και δυναμικές βιβλιοθήκες) .lib+.dll
//link to libraries
//dll dynamic link library(περιέχουν κώδικες και διαδικασιές για τα windows)
int main()
{
    double k=45;
    printf("%.2lf\n",max(6.76,3.45));
    printf("%d\n",max(23,43));
    printf("%.2lf\n",sum(6.78,5.67));
    printf("%d\n",sum(23,43));
    string a[20];
    gets(a);
    printf("%s\n",a);
    print(k);
    int b[]={1,3,4,7,8,9,4};
    printf("Time is %s\n",__TIME__);
    //__TIME__ προκαθορισμένη μακροεντολή
    printf("%d",sizeof(b)/sizeof(int));
}