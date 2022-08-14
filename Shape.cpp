/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include "windows.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void drawFigure(){
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.9, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.7, 0.12);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.7, -0.12);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.7, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.5, 0.25);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.3, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.7, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.5, -0.25);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.3, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.3, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.2, 0.25);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.1, 0.12);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.1, -0.12);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.2, -0.25);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.3, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.2, 0.25);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.1, 0.12);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.1, -0.12);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.2, -0.25);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.1, 0.12);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.1, -0.12);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, -0.25);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.25, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0, 0.25);
    glEnd();

}

void draw() {
    int angle = 90;

    for (int i=0; i<5; i++) {
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glScalef(0.5, 0.3, 1.0);
        glTranslatef(0.9, 0.0, 1.0);
        drawFigure();
        glPopMatrix();
        angle += 72;
    }

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Complex shape");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
