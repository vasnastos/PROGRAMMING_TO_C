#include <stdio.h>
#include <stdlib.h>

//#define V 6
const int V=6;

char vertices[V]={'A','B','C','D','E','F'};

int adj_matrix[V][V]={{0,2,6,0,0,0},
                     {2,0,3,1,0,0},
                     {6,3,0,4,3,0},
                     {0,1,4,0,2,0},
                     {0,0,0,10,5,0}};


int* totol_vertices()
{
   int *a=(int *)calloc(V,sizeof(int));
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<V;j++)
       {
           if(adj_matrix[i][j]!=0)
              a[i]++;
       }
   }
   return a;
}

int main()
{
    int *x=totol_vertices();
    for(int i=0;i<V;i++)
    {
        printf("%c TOTAL CONNECTED VERTICES:%d\n",vertices[i],x[i]);
    }
    free(x);
}