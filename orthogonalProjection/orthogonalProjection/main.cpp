/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 6 Section 3 Objective 6 - 1

   Orthogonal projection



   @author: Steve Leung

   @date: May 4, 2011

*/



#include "glut/glut.h"





// initialize

void initialize() {

    // set background color

    glClearColor(1.0, 1.0, 1.0, 0.0);



    // smooth the lines

    glEnable( GL_BLEND );

    glEnable( GL_LINE_SMOOTH );

}



// render

void render() {

    // #1 Green cube

    glColor3f(0.0, 1.0, 0.0);

    glPushMatrix();

        glRotatef(45, 1.0, 1.0, 0.0);

        glutWireCube(0.2);

    glPopMatrix();



    // #2 Red cube

    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();

        glRotatef(45, 1.0, 1.0, 0.0);

        glTranslatef(0.0, 0.0, -0.5);    // <-- change the z-value
                                        // need to be smaller than 0, change the distance to the flame, not the size

        glutWireCube(0.2);

    glPopMatrix();

}



// display registry

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();



    // set to projection matrix stack

    glMatrixMode(GL_PROJECTION);



    // viewing - Ortho

    glOrtho(0.0, 0.0, 0.0, 0.0, 10.0, -10.0);



    // viewing - gluLookAt

    gluLookAt(0.0, 0.0, -2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
                        //need to have > zero value



    // viewing - gluPerspective

    gluPerspective(60.0, 1.0, 1.0, 20.0);



    glMatrixMode(GL_MODELVIEW);

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



    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U6 S3 O6 - Ortho");

    glutSetWindow(windowHandle);



    glutDisplayFunc( display );

    glutReshapeFunc( reshape );



    initialize();



    glutMainLoop();

}
