/*AUTHOR NASTOS VASILEIOS DIT UOI*/

#include <stdio.h>
#include <string.h>

int getgreekcharacters(char *s)
{
    int counter=0;
    for(int i=0;i<strlen(s);i++)
    {
        if((s[i]>='Α' && s[i]<'Ω')||(s[i]>='α' && s[i]<='ω'))
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    char string[100];
    for(int i=0;i<100;i++)
    {
        printf("Give character:");
        scanf("%c",&string[i]);
    }
    printf("Total characters 100\n");
    printf("Greek characters:%d",getgreekcharacters(string));
    printf("Greek character precent:%.2lf\n",getgreekcharacters(string)/100.0);
}