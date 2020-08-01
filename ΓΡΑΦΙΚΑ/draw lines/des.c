#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>

typedef struct
{
	GLuint design[8];
	GLfloat red,green,blue;
}line;

line lines[3];

void read_data()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<8;j++)
		{
			printf("Give design point %d:",j+1);
			scanf("%d",&lines[i].design[j]);
		}
		printf("Give red color:");
		scanf("%f",&lines[i].red);
		printf("Give green color:");
		scanf("%f",&lines[i].green);
		printf("Give blue color:");
		scanf("%f",&lines[i].blue);
	}
}

void loading()
{
	printf("Data read by user please wait...");
	for(int i=0;i<4;i++)
	{
		printf("...");
		Sleep(1000);
	}
	printf("\nDesign complete,ready for use\n");
}

void initiate()
{
	read_data();
	loading();
}

void drawlines()
{
	glClearColor(0.7,0.7,0.7,0);
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0;i<3;i++)
	{
		glColor3f(lines[i].red,lines[i].green,lines[i].blue);
		if(i%2==0)
		{
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1,0x00FF);
			glBegin(GL_LINE_STRIP);
			for(int j=0;j<8;j+=2)
			{
				glVertex2i(lines[i].design[j],lines[i].design[j+1]);
			}
			glEnd();
			glDisable(GL_LINE_STIPPLE);
		}
		else
		{
			glBegin(GL_LINES);
			for(int j=0;j<8;j+=2)
			{
				glVertex2i(lines[i].design[j],lines[i].design[j+1]);
			}
			glEnd();
		}
	}
	glFlush();
}

int main(int argc,char **argv)
{
	initiate();
	glutInit(&argc,argv);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(640,480);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("Graphics use");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-5,30,-5,30);
	
	glutDisplayFunc(drawlines);
	glutMainLoop();
}
