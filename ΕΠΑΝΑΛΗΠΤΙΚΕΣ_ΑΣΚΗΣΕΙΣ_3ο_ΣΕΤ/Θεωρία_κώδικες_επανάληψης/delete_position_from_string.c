//Συωάρτηση η οποία διαγράγει έναν χαρακτήρα από μία συγκεκριμένη θέση του αλφαριθμητικού
#include <stdio.h>
#include <string.h> 
void delete_from_position(int i,char *x)
{
    if(i<0 || i>=strlen(x))
    {
        //έλεγχος εγκυρότητας θέσης
        return;
    }
    for(int j=i;j<strlen(x)-1;j++)
    {
        //Μετατόπιση στοιχείων μία θέση αριστερά
        x[i]=x[i+1];       
    }
    x[strlen(x)-1]='\0';//Μείωση μήκους αλφαριθμητικού
}