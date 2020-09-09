#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int commonElements(int *x,int *y,int n)
{
    int counter=0;
    int counterperelement;
    for(int i=0;i<n;i++)
    {
       counterperelement=0;
       for(int j=0;j<n;j++)
       {
           if(y[j]==x[i])
           {
               counterperelement++;
           }
       }
       if(counterperelement==1)
       {
           counter++;
       }
    }
    return counter;
}

int main()
{
  srand(1234);
  int x[SIZE];
  int y[SIZE];
  //Γέμισμα πινάκων χ και y με τυχαίες τιμές
  for(int i=0;i<SIZE;i++)
  {
      x[i]=rand()%20;
      y[i]=rand()%12;
  }
  printf("Total elements in table x which exists one time in table y are:%d",commonElements(x,y,SIZE));
  return 0;
}