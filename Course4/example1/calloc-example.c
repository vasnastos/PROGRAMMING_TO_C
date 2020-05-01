#include <stdio.h>
#include <stdlib.h>
void print(int *a,int size)
{
    for(int j=0;j<size;j++)
    {
        printf("a[%d]:%d\n",j,a[j]);
    }
}
int main()
{
    int *pin;//Δήλωση δείκτη.
    int size;
    printf("Give size of board:");
    scanf("%d",&size);
    pin=(int *)calloc(size,sizeof(int));
    //Δυναμική δέσμευση μνήμης όπως και η malloc
    //με την μοναδική διαφορά ότι θέτει το περιεχόμενο της θέσης μνήμης που δεσμεύει
    //ίσο με το 0(πραγματοποιεί αρχικοποίηση των περιεχομένων της μνήμης)
    print(pin,size);
    size+=2;
    pin=(int *)realloc(pin,size*sizeof(int));
    //Επαναδέσμευση της μνήμης δεσμεύοντας λιγότερα οι περισσότερα bytes
    //στην μνήμη.
    printf("Board after reallocate!!");
    //size=sizeof(pin)/sizeof(pin[0]);--error(sizeof(*)=8)
    //sizeof(*) είναι πάντα σταθερό και ίσο με 8
    print(pin,size);
    free(pin);//Απελευθέρωση μνήμης που δέσμευσε ο δείκτης.
}