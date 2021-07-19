

#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include "gui.h"

class menu_class
{
	void create_menu()
	{
		void GoMenu(int value);
		int object_sub = glutCreateMenu(GoMenu);
		glutAddMenuEntry("Cube", 1);
		glutCreateMenu(GoMenu);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	}
};