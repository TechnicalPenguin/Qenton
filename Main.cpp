#include <iostream>
#include <GL/glut.h>

using namespace std;

int cx = -13;
int cy = 0;
int cz = -45;
bool isWireframeEnabled = false;

void keyboard(unsigned char key, int x, int y)
{
	cout << "Keyboard functioning loaded" << endl;
	if (key == 'w') { cz += 1; }
	if (key == 's') { cz -= 1; }
	if (key == 'a') { cx += 1; }
	if (key == 'd') { cx -= 1; }
	if (key == 'q') { cy -= 1; }
	if (key == 'z') { cy += 1; }

	if (isWireframeEnabled == true && key == 'c')
	{
		isWireframeEnabled = false;
	}
	else if (isWireframeEnabled == false && key == 'c')
	{
		isWireframeEnabled = true;

	}
	if (key == 'z') { cy += 1; }

	glutPostRedisplay();
}
void drawDefaults()
{
	glColor4f(255,0,0,.5);
	glutSolidCube(1);
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
		glColor4f(255, 0, 0, 0); glLineWidth(1);
		glVertex3f(0, -0.1, 0); glVertex3f(19, -0.1,0);
		glEnd();
		glPopMatrix();
	}
	cout << "Grid loaded" << endl;

}
void display()
{
	glPushMatrix();
	glEnable(GL_LIGHT1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(cx, cy, cz);
	glRotatef(40, 1, 1, 0);
	if (isWireframeEnabled == true) {
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
	}
	else {
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_FILL);
	}
	drawDefaults();
	drawGrid();
	glutSwapBuffers();
	glPopMatrix();
	cout << "Display loaded" << endl;

}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35, 1.0f, 0.1f, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.1, 0.1, 0.1, 1);
	cout << "OPENGL Instalized" << endl;

}
void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(0, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutReshapeFunc(reshape);
	glutCreateWindow("Qenton");
	glutKeyboardFunc(keyboard);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	cout << "Main looping started" << endl;

	return 0;
}