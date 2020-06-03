#include<stdio.h>
#include<stdlib.h>

#define s 20

typedef struct
{
    int number;
    char fullname[100];
    double time;
}athlitis;

void readdata(athlitis *athlites, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Give number of athlete %d: \n",i+1);
        scanf("%d",&athlites[i].number);
      
        while(athlites[i].number<1 || athlites[i].number>99)
        {
            printf("Wrong input!!! Give number of athlete again: \n");
            scanf("%d",&athlites[i].number);
        }
        fflush(stdin);
    /*    do
        {
            printf("Give fullname of athlete %d: ",i+1);
            gets(athlites[i].fullname);
        while(athlites[i].fullname<'a' && athlites[i].fullname>'z' || athlites[i].fullname<'A' && athlites[i].fullname>'Z')
    */
        printf("Give fullname of athlete %d: \n",i+1);
        gets(athlites[i].fullname);
        do
        {
            printf("Give the time of the run of athlete %d: \n",i+1);
            scanf("%lf",&athlites[i].time);
        }while(athlites[i].time<=0);
    }
}

int winner(athlitis *athlites, int size)
{
    int winner_number=athlites[0].number;
    athlitis winner = athlites[0]; 
    for(int i=1;i<size;i++)
    {
        if(athlites[i].time < winner.time)
        {
            winner_number = athlites[i].number;
            winner = athlites[i];
        }
    }
    return winner_number;
}

void show_athlites(athlitis *athlites, int size)
{
    for(int i=0;i<size;i++)
    {
        if(athlites[i].time < 60.0)
        {
           printf("The athlete %d has: Number: %d \t Fullname: %s \t Time: %.2lf \n", i+1, athlites[i].number, athlites[i].fullname, athlites[i].time); 
        }
    }
}

int main()
{
    athlitis athlites[s];
    readdata(athlites,s);
    printf("The winner is the athlete with the number: %d \n", winner(athlites,s));
    show_athlites(athlites,s);

    return 0;
}