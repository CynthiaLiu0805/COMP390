/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 3 Section 5 Objective 1

   Mouse interaction



   @author: Steve Leung

   @date: May 19, 2011

*/



//#include "windows.h"
#include <unistd.h>

#include "glut/glut.h"



GLfloat angle = 0.0f, rx = 1.0f, ry = 0.0f, rz = 0.0f;

GLint motion = 0;



// initialization

void initialize(void) {

    glClearColor(0.8, 0.8, 0.8, 0.0);

    glShadeModel(GL_SMOOTH);

}



// swap rotating axes

void swap_axis() {

    if (rx == 1.0) {

        rx = 0.0f; ry = 1.0f; rz = 0.0f;

    }

    else if (ry == 1.0) {

        rx = 0.0f; ry = 0.0f; rz = 1.0f;

    }

    else if (rz == 1.0) {

        rx = 1.0f; ry = 0.0f; rz = 0.0f;

    }

}



// main rendering routine

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glPushMatrix();

    glRotatef(angle, rx, ry, rz);

    glBegin(GL_POLYGON);

        glColor3f(1.0, 0.0, 0.0);

        glVertex3f(-1.12, -1.0, 0.0);

        glColor3f(0.0, 1.0, 0.0);

        glVertex3f(0.0, 1.0, 0.0);

        glColor3f(0.0, 0.0, 1.0);

        glVertex3f(1.12, -1.0, 0.0);

    glEnd();

    glPopMatrix();



    glFlush();

    glutSwapBuffers();

}



void mouseF(int button, int state, int x, int y) {

    switch( button ) {

        case GLUT_LEFT_BUTTON:

            switch( state ) {

                case GLUT_UP:

                    if (motion == 0) motion = 1;

                    else motion = 0;

                    break;

            }

    }

}



void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(-1.5, 1.5, -1.5, 1.5, -5.0, 5.0);

    glMatrixMode(GL_MODELVIEW);

}



void spin() {

    if (motion == 1) return;



    if (angle < 360.0f) {

        usleep(25);

        angle += 1.0f;

        display();

    }

    else {

        angle = 0.0f;

        swap_axis();

    }

}



int main(int argc, char **argv)

{

    glutInit( &argc, argv );

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;

    glutInitWindowSize(500, 500);

      glutInitWindowPosition(100, 100);



    int windowHandle = glutCreateWindow("Comp390 U3 S5 O1");

    glutSetWindow(windowHandle);



    glutMouseFunc( mouseF );

    glutDisplayFunc( display );

    glutReshapeFunc( reshape );

    glutIdleFunc( spin );



    initialize();



    glutMainLoop();

}
