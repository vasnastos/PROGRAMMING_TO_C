#include <stdio.h>
#include <stdlib.h>
float* maxpoint(float *a,float *b)
{
    if(*a>*b)
    return a;
    else if(*b>*a)
    return b;
    else return NULL;
} 
int main()
{
    float a,b;
    float *result;
    printf("Give number_1:");
    scanf("%f",&a);
    printf("Give number_2:");
    scanf("%f",&b);
    result=maxpoint(&a,&b);
    if(result==NULL)
    {
        printf("two numbers are equal\n");
        exit(EXIT_SUCCESS);
    }
    printf("max value:%.2f\n",*result);
    free(result);
}