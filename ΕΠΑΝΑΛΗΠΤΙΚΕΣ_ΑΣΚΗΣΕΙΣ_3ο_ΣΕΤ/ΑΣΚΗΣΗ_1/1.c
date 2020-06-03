#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct 
{
    char code;
    int views;
    int audience;
}room;

void readdata(room *rooms, int size) 
{
    for(int i=0;i<size;i++)
    {
        fflush(stdin);
        printf("Give code of viewing room %d: \n",i+1);
        scanf("%c",&rooms[i].code);
        while(rooms[i].code<'a' || rooms[i].code>'z')
        {
            printf("Wrong input!!! \n");
            printf("Give code of viewing room %d again: \n",i+1);
            scanf("%c",&rooms[i].code);
        }
        printf("Give views of viewing room %d: \n",i+1);
        scanf("%d",&rooms[i].views);
        while(rooms[i].views<0 || rooms[i].views>10)
        {
            printf("Wrong input!!! \n");
            printf("Give views of viewing room %d again: \n",i+1);
            scanf("%d",&rooms[i].views);
        }
        printf("Give audience of viewing room %d: \n",i+1);
        scanf("%d",&rooms[i].audience);
        while(rooms[i].audience<0)
        {
            printf("Wrong input!!! \n");
            printf("Give audience of viewing room %d again: \n",i+1);
            scanf("%d",&rooms[i].audience);
        }
    }
}

int views (room *rooms, int size)
{
    int counter=0;
    for(int i=0;i<size;i++)
    {
        if(rooms[i].views<2)
        {
            counter++;
        }
    }
    return counter;
}

void audience (room *rooms, int size)
{
    for(int i=0;i<size;i++)
    {
        if(rooms[i].audience>1000)
        {
            printf("Code:%c \t Views:%d \t Audience:%d \n", rooms[i].code, rooms[i].views, rooms[i].audience);
        }
    }
}

int main()
{
    room rooms[7];
    readdata(rooms, 7);
    printf("The viewing rooms with less than 2 views are: %d \n", views(rooms,7));
    audience(rooms, 7);


    return 0;
}