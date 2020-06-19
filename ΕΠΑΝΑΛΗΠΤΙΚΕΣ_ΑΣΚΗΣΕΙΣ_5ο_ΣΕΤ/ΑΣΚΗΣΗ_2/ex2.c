#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double width;
    double height;
}rectangle;

double area(rectangle r)
{
   return r.width * r.height;
}

void sort(rectangle *rectangles,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(area(rectangles[j])>area(rectangles[j+1]))
            {
              rectangle temp=rectangles[j];
              rectangles[j]=rectangles[j+1];
              rectangles[j+1]=temp;
            }
        }
    }
}

int main()
{
    rectangle rectangles[10];
    for(int i=0;i<10;i++)
    {
        printf("Give width:");
        scanf("%lf",&rectangles[i].width);
        printf("Give height:");
        scanf("%lf",&rectangles[i].height);
    }
    sort(rectangles,10);
    for(int i=0;i<10;i++)
    {
        printf("AREA OF Rectangle_%d=%lf\n",i+1,area(rectangles[i]));
        printf("Rectangle_%d\n",i+1);
        printf("Width:%lf\n",rectangles[i].width);
        printf("Height:%lf\n",rectangles[i].height);
    }
}