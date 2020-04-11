#include <stdio.h>
int find_max(int p[],int s)
{
    int max=p[0];
    for(int i=1;i<s;i++)
    {
        if(p[i]>max)
        max=p[i];
    }
    return max;
}
int cnt_max(int p[],int s)
{
    int c=0;
    int m=find_max(p,s);
    while(m%2==0)
    {
        c++;
        m/=2;
    }
    return c;
}
int main()
{
    int a[10]={1,7,8,15,28,31,42,88,56,22};
    printf("Max %d divides with 2 %d times",find_max(a,sizeof(a)/sizeof(a[0])),cnt_max(a,sizeof(a)/sizeof(a[0])));
    return 0;
}