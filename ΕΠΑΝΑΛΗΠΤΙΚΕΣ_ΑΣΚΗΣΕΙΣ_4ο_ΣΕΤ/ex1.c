#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>//sqrt()

typedef struct 
{
  int x,y;
}point;

void sort(point *points,int size)
{
   //Προσπελαση του πίνακα
   for(int i=0;i<size;i++)
   {
       for(int j=0;j<size-1;j++)
       {
           //Ταξινόμιξη με βάση την ρίζα του x*y!!!!!
           if(sqrt(points[j].x*points[j].y)<sqrt(points[j+1].x*points[j+1].y))//Φθίνουσα ταξινόμιση
           {
               //swap
                point temp=points[j];
                points[j]=points[j+1];
                points[j+1]=temp;
           }
       }
   }
}

int main()
{
    //Δυναμική δέσμευση μνήμης-->malloc,calloc
   point *points=(point *)malloc(10 * sizeof(point));
   //Διάβασμα τιμών από τον χρήστη για μια δομή Struct
   for(int i=0;i<10;i++)
   {
       printf("Give x:");
       scanf("%d",&points[i].x);
       printf("Give y:");
       scanf("%d",&points[i].y);
   }
   //Κλήση συνάρτησης void
   sort(points,10);
   //Εκτύπωση πίνακα
   for(int i=0;i<10;i++)
   {
       //printf("%d %d\n",points[i].x,points[i].y);
       printf("Point %d:x::%d \t y::%d\n",i+1,points[i].x,points[i].y);
   }
   free(points);
}