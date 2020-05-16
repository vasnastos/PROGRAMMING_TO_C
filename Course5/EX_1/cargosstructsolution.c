#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 100
typedef struct 
{
   int id;
   double weight;
   char *destination;
   double price;
}cargo;
void delete_cargo(cargo *cr,int size,int id)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(cr[i].id==id)
        {
            pos=i;
        }
    }
    if(pos==-1)
    {
        printf("id didn't found on the board\n");
        return;
    }
    for(int i=pos;i<size-1;i++)
    {
        cr[i]=cr[i+1];
    }
    size--;
    cr=(cargo *)realloc(cr,size * sizeof(cargo));
}
void find_expensive_cargo(cargo *cr,int size,cargo *expensive)
{
    *expensive=cr[0];
    for(int i=1;i<size;i++)
    {
        if(cr[i].price>expensive->price)
        {
            *expensive=cr[i];
        }
    }
}
void save_to_file(cargo *cr,int size)
{
    FILE *fp;
    char fn[100];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"w");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"ID:%d--WEIGHT:%.2lf--DESTINATION:%s--PRICE:%.2lf\n",cr[i].id,cr[i].weight,cr[i].destination,cr[i].price);
    }
    fclose(fp);
}
void update_price(cargo *cr,int size)
{
    for(int i=0;i<size;i++)
    {
        cr[i].price+=(cr[i].weight/0.2)*0.1;
    }
}
void deleteboard(cargo *cr,int size)
{
    for(int i=0;i<size;i++)
    {
        free(cr[i].destination);
    }
}
int main()
{
    FILE *fp;
    cargo *cargos;
    char fn[100];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        perror("No file found\n");
        return 0;
    }
    char line[ms];
    int cnt=0;
    while(fgets(line,ms,fp)!=NULL)
    {
       cnt++;
    }
    fclose(fp);
    cargos=(cargo *)malloc(sizeof(cargo));
    fp=fopen(fn,"r");
    int v1;
    double v2,v4;
    char v3[ms];
    int i=0;
    while(fscanf(fp,"%d-%lf-%s-%lf",&v1,&v2,&v3,&v4)>0)
    {
        cargos[i].id=v1;
        cargos[i].weight=v2;
        cargos[i].destination=(char *)malloc(ms * sizeof(char));
        strcpy(cargos[i].destination,v3);
        cargos[i].price=v4;
        i++;
    } 
    delete_cargo(cargos,cnt,12);
    delete_cargo(cargos,cnt,5);
    cnt=sizeof(cargos)/sizeof(cargos[0]);
    cargo exp;
    find_expensive_cargo(cargos,cnt,&exp);
    printf("MOST EXPENSIVE CARGO:%d",exp.id);
    update_price(cargos,cnt);
    save_to_file(cargos,cnt);
    printf("cargos have been saved!!!\n");
}