#include <stdio.h>
#define s 5
void function(int *a,int *max,int *min,float *avg)
{
    *max=a[0];
    *min=a[0];
    *avg=a[0];
    for(int i=1;i<s;i++)
    {
        if(*max<a[i]) *max=a[i];
        if(*min>a[i]) *min=*(a+i);
        *avg+=*(a+i);
    }
    *avg/=s;
}
int main()
{
    int pin[s]={6,4,8,2,10};
    int mx,mn;
    float average;
    function(pin,&mx,&mn,&average);
    printf("max=%d\n",mx);
    printf("min=%d\n",mn);
    printf("average=%f\n",average);
}