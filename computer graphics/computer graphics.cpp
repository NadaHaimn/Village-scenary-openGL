/* #include<GL\glut.h>

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	bool f = true;

	for (float x = -1.0; x < 1.0; x += 0.25) {
		f = !f;
		for (float y = -1.0; y < 1.0; y += 0.25) {
			if (f) {
				glColor3f(1.0, 1.0, 1.0);
			}
			else {
				glColor3f(0.0, 0.0, 0.0);
			}
			f = !f;

			glBegin(GL_QUADS);
			glVertex2f(x, y);
			glVertex2f(x + 0.25, y);
			glVertex2f(x + 0.25, y + 0.25);
			glVertex2f(x, y + 0.25);
			glEnd();
		}
	}
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(300, 50);
	glutInitWindowSize(700, 700);

	glutCreateWindow("Cheatboard");

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}*/

/*void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0,0.0);
	glBegin(GL_QUADS);


	for (int i = -1; i <= 1; i += 2) {

		glColor3f(1.0, 1.0, 1.0);

		glVertex2f(-0.5*i, 1.0*i);
		glVertex2f(-1.0*i, 1.0*i);
		glVertex2f(-1*i, 0.5*i);
		glVertex2f(-0.5*i, 0.5*i);

		glVertex2f(0.5*i, 1.0*i);
		glVertex2f(0.0*i, 1.0*i);
		glVertex2f(0.0*i, 0.5*i);
		glVertex2f(0.5 * i, 0.5 * i);

		glVertex2f(0.0 * i, 0.5 * i);
		glVertex2f(-0.5 * i, 0.5 * i);
		glVertex2f(-0.5 * i, 0.0 * i);
		glVertex2f(0.0 * i, 0.0 * i);

		glVertex2f(1.0 * i, 0.5 * i);
		glVertex2f(0.5 * i, 0.5 * i);
		glVertex2f(0.5 * i, 0.0 * i);
		glVertex2f(1.0 * i, 0.0 * i);
	}
	glEnd();
	glFlush();
}
int main(int argc , char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(350, 350);
	glutInitWindowPosition(500, 200);
	glutCreateWindow("NadaHaimnEslam 221433");

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}*/