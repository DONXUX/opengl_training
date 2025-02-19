#include <Windows.h>
#include <glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);			// 깊이 버퍼 미사용

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(-0.9, -0.9, 0.2);
		glVertex3f(0.9, -0.9, 0.2);
		glVertex3f(0.9, 0.9, 0.2);
		glVertex3f(-0.9, 0.9, 0.2);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.0, 0.5, 0.5);
	glEnd();

	glDepthMask(GL_TRUE);			// 깊이 버퍼 사용
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);		// 프레임 버퍼 미사용
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex3f(-0.9, -0.9, 0.2);
			glVertex3f(0.9, -0.9, 0.2);
			glVertex3f(0.9, 0.9, 0.2);
			glVertex3f(-0.9, 0.9, 0.2);
		glEnd();
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);			// 프레임 버퍼 사용

	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.3);
	glutSolidTeapot(0.3);
	glFlush();
}

int main() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("영상합성");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();

	return 0;
}