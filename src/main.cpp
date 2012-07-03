#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <ctime>
#include "mathcore.h"

using namespace std;

//set up some useful variables
int window_width = 1280;
int window_height = 720;
int mouse_old_x, mouse_old_y;
int mouse_buttons = 0;
float rotate_x = 0.0, rotate_y = 0.0;
float translate_z = -1.0;

//forward declare some methods
void initGL();
void display();
void keyboard( unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);

int main( int argc, char** argv)
{
    // Create GL context
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize( window_width, window_height);
    glutCreateWindow( "Nuparu");
    
    // initialize GL
    initGL();
    
    // register callbacks
    glutDisplayFunc( display);
    glutKeyboardFunc( keyboard);
    glutMouseFunc( mouse);
    glutMotionFunc( motion);
    
    // start rendering mainloop
    glutMainLoop();
}

void initGL()
{
    // default initialization
    glClearColor( 0.4, 0.4, 0.4, 1.0);
    glDisable( GL_DEPTH_TEST);
    
    // viewport
    glViewport( 0, 0, window_width, window_height);
    
    // projection
    glMatrixMode( GL_PROJECTION);
    glLoadIdentity();
    
    // TODO (maybe):  make these not hardcoded?
    gluPerspective(45.0, (GLfloat)window_width / (GLfloat) window_height, .00001, 1000.0);
    
    //shading stuff
    glShadeModel(GL_FLAT);  //use flat since in a 2D engine lighting will probably be baked
    
    //enable GL feature stuff and settings
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // set view matrix
    //this is a terrible way to implement a camera, obviously we'll want to change this later, but for the sake of this test it works fine
    glMatrixMode(GL_MODELVIEW);             
    glLoadIdentity();
    glTranslatef(0.0, 0.0, translate_z);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    
    GLUquadric* sphere;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_LINE );
    glPushMatrix();
    glTranslatef(0.0f, 0.0f,0.0f);
    gluSphere(sphere, 0.30, 20, 20);
    glPopMatrix();
    
    glutSwapBuffers();
    glutPostRedisplay();
}

void keyboard( unsigned char key, int /*x*/, int /*y*/)
{
    switch( key) {
        case( 27) :
            exit( 0);
    }
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN) {
        mouse_buttons |= 1<<button;
    } else if (state == GLUT_UP) {
        mouse_buttons = 0;
    }
    
    mouse_old_x = x;
    mouse_old_y = y;
    glutPostRedisplay();
}

void motion(int x, int y)   
{
    float dx, dy;
    dx = (float)(x - mouse_old_x);
    dy = (float)(y - mouse_old_y);
    
    if (mouse_buttons & 1) {
        rotate_x += dy * 0.2f;
        rotate_y += dx * 0.2f;
    } else if (mouse_buttons & 4) {
        translate_z += dy * 0.01f;
    }
    
    mouse_old_x = x;
    mouse_old_y = y;
}








