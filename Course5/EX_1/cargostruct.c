#include <stdio.h>
#include <stdlib.h>
//struct to be implement
//..
//..
void delete_cargo(cargo *cr,int size,int id)
{
    //to be implement
}
void find_expensive_cargo(cargo *cr,int size,cargo *expensive)
{
    //to be implement
}
void save_to_file()
{
    //to be implement
}
void update_price(cargo *cr,int size)
{
    //to be implement
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
        perror("No file %s found\n",fn);
        return 0;
    }
    char line[100];
    int cnt=0;
    while(fgets(line,100,fp)!=NULL)
    {
       cnt++;
    }
    fclose(fp);
    cargos=(cargo *)malloc(sizeof(cargo));
    fp=fopen(fn,"r");
    int v1;
    double v2,v4;
    char v3[100];
    int i=0;
    while(fscanf(fp,"%d-%lf-%s-%lf",&v1,&v2,&v3,&v4)>0)
    {
        cargos[i].id=v1;
        cargos[i].weight=v2;
        cargos[i].destination=v3;
        cargos[i].price=v4;
        i++;
    } 
    delete_cargo(12);
    delete_cargo(5);
    cargo exp;
    find_expensive_cargo(cargos,&exp);
    update_price();
    save_to_file();
    printf("cargos have been saved!!!\n");
}
