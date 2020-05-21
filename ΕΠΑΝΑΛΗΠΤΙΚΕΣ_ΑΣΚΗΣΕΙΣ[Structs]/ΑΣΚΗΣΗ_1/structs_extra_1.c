#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    double real;
    double imaginary;
}complex;
//πρόσθεση
complex add(complex *n1,complex *n2)
{
    complex result;
    result.real=n1->real+n2->real;
    result.imaginary=n1->imaginary+n2->imaginary;
    return result;
}
//Αφαίρεση
complex minus(complex *n1,complex *n2)
{
   complex result;
   result.real=n1->real-n2->real;
   result.imaginary=n1->imaginary-n2->imaginary;
   return result;
}
//πολλαπλασιασμός
complex mul(complex *n1,complex *n2)
{
    complex result;
    result.real=n1->real*n2->real;
    result.imaginary=n1->imaginary*n2->imaginary;
    return result;
}
//Διαίρεση
complex divide(complex *n1,complex *n2)
{
    complex result;
    if(n2->real==0 || n2->imaginary==0)
    {
        result.real=0.0;
        result.imaginary=0.0;
        return result;
    }
    result.real=n1->real+n2->real;
    result.imaginary=n1->imaginary+n2->imaginary;
    return result;
}
//εκτύπωση αποτελέσματος
void printresult(complex *res)
{
    printf("%.2lf+%.2lfi\n",res->real,res->imaginary);
}
int main()
{
    complex number1,number2;
    char operator,answer;
    complex *result=(complex *)malloc(sizeof(complex));
    while(1)
    {
        printf("Give number 1:\n");
        printf("Give real part:");
        scanf("%lf",&number1.real);
        printf("Give imaginary part:");
        scanf("%lf",&number1.imaginary);
        fflush(stdin);
        printf("Give operator:");
        scanf("%c",&operator);
        printf("Give number 2:");
        printf("Give real part:");
        scanf("%lf",&number2.real);
        printf("Give imaginary part:");
        scanf("%lf",&number2.imaginary);
        if(operator=='+')
        {
          *result=add(&number1,&number2);
          printresult(result);
        }
        else if(operator=='-')
        {
           *result=minus(&number1,&number2);
           printresult(result);
        }
        else if(operator=='*')
        {
           *result=mul(&number1,&number2);
            printresult(result);
        }
        else if(operator=='/')
        {
           *result=divide(&number1,&number2);
           printresult(result);
        }
        else 
        {
            perror("Invalid command,please try again!!!!\n");
        }
        fflush(stdin);
        printf("continue??:");
        getc(answer);
        if(answer=='q') break;
    } 
    free(result);   
}