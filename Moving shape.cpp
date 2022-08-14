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


static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */
void display(){

    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0,0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.2,0.9);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.4, 0.4);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.4, -0.4);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.2, -0.9);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.4,0.4);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.6,0.5);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.8, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.6, -0.5);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.4, -0.4);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.4,0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.2,-0.5);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.2, 0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.6,0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.4,-0.3);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.4, 0.3);
    glEnd();
}
void shapes(float start)
{
   for(int i=1,j=start;i<=5;i++)
 {
     glPushMatrix();
     glRotatef(j,0.0,0.0,1.0);
     glScalef(0.6,0.2,1);
     glTranslatef(0.6,0.0,1.0);

     display();
     j=j+72;
     glPopMatrix();

 }
       glutSwapBuffers();
}
void anim()
{
    float beginning = 0;
    while(1)
    {
        if (beginning>360)
        {
            beginning=0;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        shapes(beginning);
        beginning+=0.75;
    }
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,0);
    glutCreateWindow(" Creating a triangle and displaying it.");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(anim);
    glutMainLoop();
    return 0;
}
