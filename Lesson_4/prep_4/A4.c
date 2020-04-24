#include <stdio.h>
void readfscanf(char name[])
{
    FILE *fp;
    fp=fopen(name,"r");
    int h,a;
    int cnth=0,cnta=0,cntt=0;
    while(fscanf(fp,"%d-%d",&h,&a)>0)
    {
       if(h>a) cnth++;
       else if(h<a) cnta++;
       else cntt++;
    }
    fclose(fp);
    printf("%d home wins\n",cnth);
    printf("%d away wins\n",cnta);
    printf("%d ties\n",cntt);
}
int main(int argc,char **argv)
{
    readfscanf(argv[1]);
}