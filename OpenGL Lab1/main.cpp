#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#define WINDOW_SIZE_WIDTH 800
#define WINDOW_SIZE_HEIGHT 600

using namespace std;

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#define LIST_TRIANGLE 0
#define LIST_QUAD 1

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glNewList(LIST_TRIANGLE, GL_COMPILE);
        glBegin(GL_TRIANGLES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2i(250, 450);
            glColor3f(0.0, 0.0, 1.0);
            glVertex2i(250, 150);
            glColor3f(0.0, 1.0, 0.0);
            glVertex2i(550, 150);
        glEnd();
    glEndList();
    glNewList(LIST_QUAD, GL_COMPILE);
        glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2i(250, 450);
            glColor3f(0.0, 0.0, 1.0);
            glVertex2i(250, 150);
            glColor3f(0.0, 1.0, 0.0);
            glVertex2i(550, 150);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2i(550, 450);
        glEnd();
    glEndList();
    
//    glCallList(LIST_QUAD);
    glCallList(LIST_TRIANGLE);
    
    glutSwapBuffers();
}

#define KEY_ESCAPE '\033'

void keyboard(unsigned char key, int x, int y)
{
    if (key == KEY_ESCAPE ) {
        exit(0);
    }
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Alexey Bondarenko, Lab 1");
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    

    return 0;		
}