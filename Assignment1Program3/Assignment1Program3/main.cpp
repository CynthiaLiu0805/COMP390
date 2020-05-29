/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Assignment 1 program 3

   @author: Cynthia Liu
            student number: 3483785
 
   @details: This program draw a square with four different colours at each vertex. It is accomplished by drawing two separated triangles


   @date: June 4, 2020

*/



#include "glut/glut.h"



// initialize
void initialize() {
    // set background color
    glClearColor(1.0, 1.0, 1.0, 0.0);
}



// render
void render() {
    glBegin(GL_TRIANGLES);
        //red, left bottom
        glColor3f(1, 0, 0);
        glVertex3f(-2.0f, -2.0f, 0);
    
        //green, left top
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(-2.0f, 2.0f, 0.0f);
    
        //blue, right top
        glColor3f(0.0, 0.0, 1.0 );
        glVertex3f(2.0f, 2.0f, 0.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
        //red, left bottom
        glColor3f(1, 0, 0);
        glVertex3f(-2.0f, -2.0f, 0);
    
        //blue, right top
        glColor3f(0.0, 0.0, 1.0 );
        glVertex3f(2.0f, 2.0f, 0.0f);

        //yellow, right bottom
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(2.0f, -2.0f, 0.0f);
    glEnd();
}



// display registry
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // viewing
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    render();
    glutSwapBuffers();
}



// reshape registry

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);
    glMatrixMode(GL_MODELVIEW);
}



// main program
int main(int argc, char **argv){
    glutInit( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB ) ;
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Assignment 1 Program 3");
    glutSetWindow(windowHandle);
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    initialize();
    glutMainLoop();
}

