#include <stdio.h>
#include <stdlib.h>
#define size 5
void function(int *p,int *pos,int *s)
{
    int mao=p[0];
    *pos=0;
    *s=a[0];
    for(int i=1;i<size;i++)
    {
        s+=p[i];
        if(p[i]>max)
        {
            max=p[i];
            *pos=i;
        }
    }
}
int main()
{
    int *a=(int *)malloc(size * sizeof(int));
    for(int i=0;i<size;i++)
    {
        printf("Give a[%d]",i);
        scanf("%d",&a[i]);
    }
    int posmax,sum;
    function(a,&posmax,&sum);
    printf("Max at position:%d\n",posmax);
    printf("Sum=%d\n",sum);
    free(a);
}