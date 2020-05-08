//Καταμέτρηση τιμών από αρχείο,δυναμική δέσμευση μνήμης για πίνακα,εμφάνιση ωρών(έστω αρχική ώρα 00:00:00) από τα  αντοίστoιχα δευτερόλεπτα
#include <stdio.h>
#include <stdlib.h>
#define ms 100
int getsize()
{
    int cnt=0;
    FILE *fp;
    char fn[ms];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        printf("No file:%s found!!!!\n",fn);
        return cnt;
    }
    int x;
    while(fscanf(fp,"%d",&x)==1)
    {
        cnt++;
    }
    fclose(fp);
    return cnt;
}
void readdata(int *a,int size)
{
    FILE *fp;
    char fn[ms];
    printf("Give filename:");
    gets(fn);
    int x;
    fp=fopen(fn,"r");
    int i=0;
    while(fscanf(fp,"%d",&x)==1)
    {
        a[i]=x;
        i++;
    }
    printf("data readed from file\n");
    fclose(fp);
}
void converttotime(int *a,char **time,int size)
{
    int h,m,s;
    for(int i=0;i<size;i++)
    {
        int j=0;
        int temp=a[i];
       h=temp/3600;
       while(h>=24)
       {
           h/=24;
           j++;
       }
       temp=temp%3600;
       m=temp/60;
       s=temp%60;
       if(j==0)
       sprintf(time[i],"%d:%d:%d",h,m,s);
       else{
           sprintf(time[i],"%d days pass,%d:%d:%d",j,h,m,s);
       }
    }
}
void savetofile(int *a,char **time,int size)
{
    FILE *fp;
    char fn[ms];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"w");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"%d,%s\n",a[i],time[i]);
    }
    fclose(fp);
}
void deletepointers(int *board,char **t,int size)
{
    for(int i=0;i<size;i++)
    {
        free(t[i]);
    }
    free(board);
    free(t);
}
int main()
{
   int *pin;
   char **time;
   int size=getsize();
   pin=(int *)malloc(size * sizeof(int));
   time=(char **)malloc(size * sizeof(char *));
   for(int i=0;i<size;i++)
   {
       time[i]=(char *)malloc(ms * sizeof(char));
   }
   readdata(pin,size);
   converttotime(pin,time,size);
   savetofile(pin,time,size);
   deletepointers(pin,time,size);
}