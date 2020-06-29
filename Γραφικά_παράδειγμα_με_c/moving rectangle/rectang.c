#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

int spot[4];
float color[3];

void read_data()
{
	for(int i=0;i<4;i++)
	{
		printf("Give spot %d:",i+1);
		scanf("%d",&spot[i]);
	}
	printf("Give red color:");
	scanf("%f",&color[0]);
	printf("Give green color:");
	scanf("%f",&color[1]);
	printf("Give blue color:");
	scanf("%f",&color[2]);
}

void display()
{
	glClearColor(0.5,0.5,0.5,0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(color[0],color[1],color[2]);
	glRecti(spot[0],spot[1],spot[2],spot[3]);
	glFlush();
}

void keybord(unsigned char key,int x,int y)
{
	if(key=='t')
	{
		spot[1]++;
		spot[3]++;
	}
	else if(key=='h')
	{
		spot[0]++;
		spot[2]++;
	}
	else if(key=='f')
	{
		spot[0]--;
		spot[2]--;
	}
	else if(key=='g')
	{
		spot[1]--;
		spot[3]--;
	}
	glutPostRedisplay();
}

void initiate()
{
	read_data();
	char fn[200];
	fflush(stdin);
	printf("Give filename:");
	gets(fn);
	FILE *fp=fopen(fn,"r");
	fprintf(fp,"Rectangle parameters\n");
	for(int i=0;i<4;i++)
	{
		fprintf(fp,"POINT_%d:%d\n",i+1,spot[i]);
	}
	for(int i=0;i<3;i++)
	{
		fprintf(fp,"Color:%f\n",color[i]);
	}
	fclose(fp);
	
}

int main(int argc,char **argv)
{
	initiate();
	glutInit(&argc,argv);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(640,480);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("Moving rectangle");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50,50,-50,50);
	
	glutKeyboardFunc(keybord);
	glutDisplayFunc(display);
	glutMainLoop();
}
