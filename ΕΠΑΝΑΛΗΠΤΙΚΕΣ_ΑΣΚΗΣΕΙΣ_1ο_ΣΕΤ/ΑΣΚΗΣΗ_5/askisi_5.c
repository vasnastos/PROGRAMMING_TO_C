#include <stdio.h>
#include <stdlib.h>
char filename[100];
int getsize()
{
    int cnt=0;
   FILE *fp;
   fp=fopen(filename,"r");
   if(fp==NULL) return 0;
   char line[100];
   while(fgets(line,100,fp)!=NULL)
   {
       if(line[0]!='#') continue;
       if(line[0]!='\n') continue;
       cnt++;
   }
   fclose(fp);
   return cnt; 
}
void readfromfile(double *grades)
{
   FILE *fp;
   fp=fopen(filename,"r");
   char line[100];
   int i=0;
   while(fgets(line,100,fp)!=NULL)
   {
       if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0'; 
       grades[i]=atof(line);
       i++;
   }
   fclose(fp);
}

int main()
{
  strcpy(filename,"test.txt");
  int size=getsize();
  if(size==0) return 0;
  double *grades=(double *)malloc(size * sizeof(double));
  readfromfile(grades);  
  double checknum;
  printf("Give number:");
  scanf("%lf",&checknum);
  int cnt=0;
  for(int i=0;i<size;i++)
  {
      if(grades[i]>checknum)
      {
          cnt++;
      }
  }
  printf("Precent:%lf\n",((double)cnt/size)*100.0);
}