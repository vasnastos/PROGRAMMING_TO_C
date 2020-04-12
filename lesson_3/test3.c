#include <stdio.h>
#include <stdlib.h>
#define s 5
void function(int *a,int *pos,int *sum)
{
    *sum=*(a);
    *pos=0;
    int max=*(a);
    for(int i=1;i<s;i++)
    {
        *sum+=*(a+i);
        if(*(a+i)>max)
        {
            max=*(a+i);
            *pos=i;
        }
    }
}
int main()
{
    int *pin=(int *)malloc(s * sizeof(int));
    for(int i=0;i<s;i++)
    {
        printf("pin[%d]:",i);
        scanf("%d",&pin[i]);
    }
    int posmax,sum;
    function(pin,&posmax,&sum);
    printf("Max element at position:%d\n",posmax);
    printf("Sum %d\n",sum);
    free(pin);
}