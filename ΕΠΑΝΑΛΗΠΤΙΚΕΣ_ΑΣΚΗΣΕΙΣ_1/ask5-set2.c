#include <stdio.h>
#include <string.h>
double average_from_string(char w[])
{
    int s=0;
    int cnt=0;
    for(int i=0;i<strlen(w);i++)
    {
        if(w[i]>='0' && w[i]<='8')
        {
            int x=(w[i]-'0')+1;
            w[i]=x+'0';
            if(x>6)
            {
               s+=x;
               cnt++;
            }
            
        }
        if(w[i]=='9')
        {
            s+=w[i]-'0';
        }
    }
    printf("%.2lf deegre of numbers over 6\n",(double)cnt/strlen(w)*100.0);
    return (double)s/cnt;
}
int main()
{
    char str[20];
    printf("give string:");
    gets(str);
    printf("Average over 6::%.2lf\n",average_from_string(str));
    return 0;
}