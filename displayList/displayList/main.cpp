/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 3 Section 4 Objective 2

   Draw a line



   @author: Steve Leung

   @date: May 4, 2011

*/



#include "glut/glut.h"



GLuint myList;



// initialize

void initialize() {

    // set background color

    glClearColor(1.0, 1.0, 1.0, 0.0);



    // setup a display list

    myList = glGenLists(1);

    glNewList(myList, GL_COMPILE);

        glBegin(GL_POLYGON);

            glVertex2f(-1.0, -1.0);

            glVertex2f(-1.0, 1.0);

            glVertex2f(1.0, 1.0);

            glVertex2f(1.0, -1.0);

        glEnd();

    glEndList();

}



// render

void render() {
    
    
    
    

    // color

    glColor3f(0.0, 0.0, 0.0);



    // wire frame

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



    // call the display list

    glTranslatef(-4.0, 0.0, 0.0);

    glCallList(myList);



    glTranslatef(4.0, 0.0, 0.0);

    glCallList(myList);



    glTranslatef(4.0, 0.0, 0.0);

    glCallList(myList);

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



    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U3 S4 O2");

    glutSetWindow(windowHandle);



    glutDisplayFunc( display );

    glutReshapeFunc( reshape );



    initialize();



    glutMainLoop();

}
