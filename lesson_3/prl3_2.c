#include <stdio.h>
#define size 5
void function(int *a,int *mx,int *mn,int *s)
{
    *mx=a[0];
    *mn=a[0];
    *s=a[0];
    for(int i=1;i<size;i++)
    {
       *s+=a[i];
       if(a[i]>*mx) *mx=a[i];
       if(a[i]<*mn) *mn=a[i];
    }
}
int main()
{
    int a[size]={6,8,1,4,5};
    int sum,max,min;
    function(a,&max,&min,&sum);
    printf("Sum=%d   max=%d   min=%d",sum,max,min);
}