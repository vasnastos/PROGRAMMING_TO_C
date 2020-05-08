#include <stdio.h>
#include <stdlib.h>
//Ορισμός δομής που θα αναπαριστά μαθητές
//Μία δομή χρησιμοποιήται ώστε να πραγματοποιήσουμε αναπαράσταση
//Ενός τύπου(π.χ students) που ορίζεται με παραπάνω από μία 
//πρωτογενείς μεταβλητές.
typedef struct  {
    char name[100];
    double grade;
}student;
void readstruct(student *pin,int size)
{
    for(int i=0;i<size;i++)
    {
        fflush(stdin);
        printf("Give student name:");
        gets(pin[i].name);
        printf("Give students grade:");
        scanf("%lf",&pin[i].grade);
    }
    //Κάθε μεταβλητή student αναπαρείσταται και από 2 πεδία
    //name,grade άρα για κάθε struct διαβάζω 2 μεταβλητές.
}
void printstudents(student *s,int size)
{
    //Εκτύπωση μαθητών
    for(int i=0;i<size;i++)
    {
        printf("Name:%s \t Grade:%.3lf\n",s[i].name,s[i].grade);
    }
}
int main()
{
   student *a;
   a=(student *)malloc(5 * sizeof(student));//Δυναμική δέσμευση πίνακα
   readstruct(a,5);//κλήση συνάρτησης
   printstudents(a,5);//κλήση συνάρτησης 
   free(a);//Αποδέσμευση της μνήμης που δέσμευσα για τον πίνακα.
}