

#include "prefix.h";
#include <math.h>;



#include "prefix.h";
#include <math.h>;

#define ESCAPE '\033'

int Width = 800, Height = 800;
float X = 0, Y = 0, Z = 10;

void Display(void)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(X,Y,Z, 0,0,0, 0,1,0);
    float verticies[300];
    int i, j, k;
    float x=0,y=0,z=0;
    for(i=0; i<10; i++)
    {
        for (j=0; j<10; j++)
        {
            k = ( i*10 + j ) * 3;
            z= sqrt(x) + sqrt(y);
            verticies[k]= x;
            verticies[k + 1] = z;
            verticies[k + 2] = y;
            x+=1;
        }
        x = 0;
        y+=1;
    }
    //индексы вершин для построения прямоугольников
    int index = 0;
    int quards[324];
    for(i=0; i<10; i++)
    {
        for (j=0; j<9; j++)
        {
            k = i*9 + j;
            if (k%10 == 9) 	continue;
            quards[index] =  k;
            quards[index + 1] = k+1;
            quards[index + 2] = k+11;
            quards[index + 3] = k+10;
            index += 4;
        }
    }
    glNewList(1,GL_COMPILE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glutWireDodecahedron();
    
    glTranslated(6,0,0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glutSolidOctahedron();
    
    glColor3ub(0,0,100);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glutSolidOctahedron();
    
    glEndList();
    
    glNewList(2,GL_COMPILE);
    
    glTranslated(4,0,0);
    //оси
    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(10,0,0);
    glVertex3f(0,0,0);
    glVertex3f(0,2,0);
    glVertex3f(0,0,0);
    glVertex3f(0,0,10);
    glEnd();
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, verticies);
    //сначала сплошного заданного цвета
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawElements(GL_QUADS, 324, GL_UNSIGNED_INT, quards);
    //затем грани
    glColor3ub(0,0,100);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_QUADS, 324, GL_UNSIGNED_INT, quards);
    //завершение построения
    glDisableClientState(GL_VERTEX_ARRAY);
    glEndList();
    
    glPushMatrix();
    glTranslated(-10,10,0);
    glColor3ub(242,178,103);
    glCallList(1);
    glColor3ub(242,178,103);
    glCallList(2);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-10,3,0);
    glScalef(1.2,1.2,1.2);
    glColor3ub(242,178,103);
    glCallList(1);
    glColor3ub(242,178,103);
    glCallList(2);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-10,-5,0);
    glScalef(1.5,1.5,1.5);
    glColor3ub(242,178,103);
    glCallList(1);
    glColor3ub(242,178,103);
    glCallList(2);
    glPopMatrix();
    
    glFlush();
}
void Reshape(int width,int height){
    glViewport(0,0,width,height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -100, 100);
    glMatrixMode( GL_MODELVIEW );
}
void Keyboard( unsigned char key, int x, int y ){
    
    if( key == ESCAPE ) exit(0);
    float stepz=0.5;
    if( key == '+')
    {
        Z -= stepz;
        glutPostRedisplay();
    }
    if( key == '-')
    {
        Z += stepz;
        glutPostRedisplay();
    }
}
void Special( int key, int x, int y )
{
    float stepx=0.5,stepy=0.5;
    if( key == GLUT_KEY_UP)
    {
        Y += stepy;
        glutPostRedisplay();
    }
    if( key == GLUT_KEY_DOWN)
    {
        Y -= stepy;
        glutPostRedisplay();
    }
    if( key == GLUT_KEY_LEFT)
    {
        X += stepx;
        glutPostRedisplay();
    }
    if( key == GLUT_KEY_RIGHT)
    {
        X -= stepx;
        glutPostRedisplay();
    }
}
void Initialize()
{
    glClearColor(0.66, 0.8, 0.91, 0.1);//цвет фона (R, G, B, alpha);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -100, 100);
}

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };


int main(int argc, char *argv[]){
    glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("lab2");
    
    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(Special);
    Initialize();
    glutMainLoop();
}