#include <iostream>
#include <GL/glut.h>

using namespace std;

int cx = -13;
int cy = 0;
int cz = -45;

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'w') { cz += 1; }
	if (key == 's') { cz -= 1; }
	if (key == 'a') { cx += 1; }
	if (key == 'd') { cx -= 1; }
	if (key == 'q') { cy -= 1; }
	if (key == 'z') { cy += 1; }

	glutPostRedisplay();
}
void theCube()
{
	glColor3f(1,1,1);
	glutSolidCube(0.4);
	
}
void drawGrid()
{
	int i;
	for (i = 0; i < 40; i++)
	{
		glPushMatrix();
		if (i < 20) { glTranslatef(0, 0, i); }
		if (i >= 20) { glTranslatef(i - 20, 0, 0); glRotatef(-90, 0, 1, 0); }

		glBegin(GL_LINES);
		glColor3f(1, 1, 1); glLineWidth(1);
		glVertex3f(0, -0.1, 0); glVertex3f(19, -0.1,0);
		glEnd();
		glPopMatrix();
	}
}
void display()
{
	glPushMatrix();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(cx, cy, cz);
	glRotatef(40, 1, 1, 0);
	drawGrid();
	theCube();
	glutSwapBuffers();
	glPopMatrix();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35, 1.0f, 0.1f, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1, 0.1, 0.1, 1);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Qenton"); 
	glutKeyboardFunc(keyboard);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}