#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

//−2.1820 < x < 2.6558 and 0 ≤ y < 9.9983.

float x=0,y=0,probability;
float nx,ny;

void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(-2.1820,2.6558,0,9.9983);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

void animate(){

	probability= (rand() % 10000) /10000.0;
	if(probability < 0.01){
		nx = 0;
		ny = 0.16*y;
	}
	else if(probability < 0.86){
		nx = 0.85 * x + 0.04 * y;
		ny = -0.04 * x + 0.85 * y + 1.6;
	}
	else if(probability < 0.93){
		//nx = 0.2 * x − 0.26 * y;
		nx = 0.2 *x - 0.26 * y;
		ny = 0.23 * x + 0.22 * y + 1.6;
	}
	else{
		nx = (-0.15) * x + 0.28 * y;
		ny = 0.26 * x + 0.24 * y + 0.44;
	}
	x=nx;
	y=ny;
	
	glutPostRedisplay();
}

void display(){
	
	glPointSize(1.5);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
	
	glutSwapBuffers();
}

void main(int argc, char *argv[]){
	
	glutInit(&argc,argv);
	
	glutInitWindowSize(600,600);
	glutCreateWindow("BRANSLEY FERN");
	
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutDisplayFunc(display);
	
	init();
	
	glutIdleFunc(animate);
	glutMainLoop();
}
