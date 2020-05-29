//
//  main.cpp
//  point
//
//  Created by Cynthia on 8/5/2020.
//  Copyright © 2020 Cynthia. All rights reserved.
//


#include "GLUT/glut.h"



// initialize

void initialize() {

    // set background color

    glClearColor(1.0, 1.0, 1.0, 0.0);

}



// render

void render() {

    // points color

    glColor3f(0.0, 0.0, 0.0);



    // points

    glPointSize(10.0);

    glBegin(GL_POINTS);

        glVertex2f(-3.0, 0.0);

        glVertex2f(-2.0, 1.0);

        glVertex2f(-1.0, 2.0);
    
        glVertex2f(0.0, 0.0);

        glVertex2f(1.0, 1.0);

        glVertex2f(2.0, 2.0);

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



    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U3 S2 O1");

    glutSetWindow(windowHandle);



    glutDisplayFunc( display );

    glutReshapeFunc( reshape );



    initialize();



    glutMainLoop();

}
