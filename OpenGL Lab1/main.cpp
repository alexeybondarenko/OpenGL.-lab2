

#include "prefix.h";

using namespace std;

#define WINDOW_SIZE_WIDTH 800
#define WINDOW_SIZE_HEIGHT 600

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#define LIST_BACKGROUND 0
#define LIST_PLANE 1

static GLint leftCorner[2] = {200, 200};
void display ()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glNewList(LIST_BACKGROUND, GL_COMPILE);
        glBegin(GL_QUADS);
            glColor3f(0.63, 0.8, 0.99);
            glVertex2i(0, 0);
            glVertex2i(WINDOW_SIZE_WIDTH, 0);
            glVertex2i(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
            glVertex2i(0, WINDOW_SIZE_HEIGHT);
        glEnd();
    glEndList();
    
    
    GLint bottomCorner[2] = {leftCorner[0] + 45, leftCorner[1] - 45};
    GLint rightWingBody[2] = {leftCorner[0] + 50, leftCorner[1] - 20};
    GLint leftWingBody[2] = {leftCorner[0] + 40, leftCorner[1] - 30};
    
    GLint leftWingCorner[2] = {leftCorner[0] + 30, leftCorner[1] - 50};
    GLint rightWingCorner[2] = {leftCorner[0] + 60, leftCorner[1] - 15};
    
    glNewList(LIST_PLANE, GL_COMPILE);
        glBegin(GL_TRIANGLES);
            glColor3f(.9, .9, .9);
            glVertex2iv(leftCorner);
            glVertex2iv(bottomCorner);
            glVertex2iv(rightWingBody);
        glEnd();
        glBegin(GL_TRIANGLES);
            glColor3f(.99, .99, .99);
            glVertex2iv(leftCorner);
            glVertex2iv(bottomCorner);
            glVertex2iv(leftWingBody);
        glEnd();
        glBegin(GL_TRIANGLES);
            glColor3f(1, 1, 1);
            glVertex2iv(leftWingCorner);
            glVertex2iv(leftCorner);
            glVertex2iv(leftWingBody);
        glEnd();
        glBegin(GL_TRIANGLES);
            glColor3f(.98, .98, .98);
            glVertex2iv(rightWingCorner);
            glVertex2iv(leftCorner);
            glVertex2iv(rightWingBody);
        glEnd();

    glEndList();
    
    glCallList(LIST_BACKGROUND);
    glCallList(LIST_PLANE);
    
    glutSwapBuffers();
}

#define KEY_ESCAPE 33
#define KEY_LEFT 37
#define KEY_TOP 38
#define KEY_RIGHT 39
#define KEY_DOWN 40

#define KEY_PLUS 61
#define KEY_MINUS 45

#define STEP 2

bool move(unsigned char key)
{
    bool moved = false;

    switch ((int) key) {
        case KEY_PLUS: {
            moved = true;
            leftCorner[0] += STEP;
            break;
        }
        case KEY_MINUS: {
            moved = true;
            leftCorner[0] -= STEP;
            break;
        }
    }
    
    return moved;
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == KEY_ESCAPE ) {
        exit(0);
    }
    if (move(key)) {
        display();
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