#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glut.h>

char filename[200];

typedef struct
{
	int id;
	char des[200];
	int nsal;
	double pr;
} product;

int size;
product *products;

int get_size()
{
	int counter=0;
	FILE *fp=fopen(filename,"r");
	char line[200];
	while(fgets(line,200,fp)!=NULL)
	{
		if(line[0]=='\n') continue;
		if(line[0]=='#') continue;
		
		counter++;
	}
	fclose(fp);
	return counter;
}

void read_data()
{
	FILE *fp=fopen(filename,"r");
	char line[200];
	int i=0;
	int code=10;
	while(fgets(line,200,fp)!=NULL)
	{
		if(line[0]=='\n') continue;
		if(line[0]=='#') continue;
		
		char *token=strtok(line,"-");
		products[i].id=code;
		strcpy(products[i].des,token);
		token=strtok(NULL,"-");
		products[i].nsal=atoi(token);
		token=strtok(NULL,"-");
		products[i].pr=atof(token);
		i++;
		code+=2;
	}
	fclose(fp);
}

void sort()
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(products[j].nsal>products[j+1].nsal)
			{
				product temp=products[i];
				products[j]=products[j+1];
				products[j+1]=temp;
			}
		}
	}
}

void drawAxes()
{
	glColor3f(1,0,0);
	glBegin(GL_LINES);
	    glVertex3f(0,0,0);
        glVertex3f(50,0,0);
    glEnd();
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x00AA);
	glBegin(GL_LINES);
	     glVertex3f(0,0,0);
        glVertex3f(-50,0,0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	glFlush();
	
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	    glVertex3f(0,0,0);
        glVertex3f(0,50,0);
    glEnd();
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x00AA);
	glBegin(GL_LINES);
	     glVertex3f(0,0,0);
        glVertex3f(0,-50,0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);      

	glFlush(); 
}

void display()
{
	glClearColor(0.5,0.5,0.5,0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxes();
	glColor3f(1,0,1);
	for(int i=0;i<size;i++)
	{
		glBegin(GL_LINES);
		glVertex2i(products[i].id,0);
		glVertex2i(products[i].id,products[i].nsal);
		glEnd();
	}
	glFlush();
}

void initiate()
{
	strcpy(filename,"products.txt");
	size=get_size();
	printf("Size:%d\n",size);
	products=(product *)malloc(size * sizeof(product));
	read_data();
	for(int i=0;i<size;i++)
	{
		printf("ID:%d \t DES:%s \t SALES:%d \t PRICE:%.2lf\n",products[i].id,products[i].des,products[i].nsal,products[i].pr);
	}
}

void delete_data()
{
	free(products);
}

int main(int argc,char **argv)
{
	initiate();
	glutInit(&argc,argv);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(640,480);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("Stats");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50,50,-50,50);
	
	glutDisplayFunc(display);
	glutMainLoop();
	delete_data();
}
