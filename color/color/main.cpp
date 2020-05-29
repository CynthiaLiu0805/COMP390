/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 5 Section 2 Objective 1

   Color a polygon



   @author: Steve Leung

   @date: May 4, 2011

*/



#include "glut/glut.h"



// initialize

void initialize() {

    // set background color

    glClearColor(0.9, 0.9, 0.1, 0.0);

}



// render

void render() {

    // color

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);

        glVertex2f(-2.0, -2.0);

        glVertex2f(-2.0, 2.0);

        glVertex2f(2.0, 2.0);

        glVertex2f(2.0, -2.0);

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

int main(int argc, char **argv)

{

    glutInit( &argc, argv );

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;

    glutInitWindowSize(500, 500);

      glutInitWindowPosition(100, 100);



    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U5 S2 O1");

    glutSetWindow(windowHandle);



    glutDisplayFunc( display );

    glutReshapeFunc( reshape );



    initialize();



    glutMainLoop();

}
