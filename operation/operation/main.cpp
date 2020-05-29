/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 4 Section 1 Objective 4

   Translate, rotate, scale a rectangle



   @author: Steve Leung

   @date: May 16, 2011

*/



#include "glut/glut.h"



// initialize

void initialize() {

    // set background color

    glClearColor(1.0, 1.0, 1.0, 0.0);

}



// render

void render() {

    // points color

    glColor3f(0.0, 0.0, 0.0);



    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_POLYGON);

        glVertex2f(-1.0f, -1.0f);

        glVertex2f(-1.0f, 1.0f);

        glVertex2f(1.0f, 1.0f);

        glVertex2f(1.0f, -1.0f);

    glEnd();



}



// display registry

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();



    // viewing

    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



    // original - no transformation, in the middle

//    render();



    // translation only, move to bottom left

    glPushMatrix();

    glTranslatef(-3.0, -3.0, 0.0);

    render();

    glPopMatrix();



    // rotation only, rotate by 45 degree

//    glPushMatrix();
//
//    glRotatef(45.0, 0.0, 0.0, 1.0);
//
//    render();
//
//    glPopMatrix();



    // scaling only, become smaller

    glPushMatrix();

    glScalef(0.5, 0.5, 0.0);

    render();

    glPopMatrix();



    // translation, rotation, and scaling, the upper right one

    glPushMatrix();

    glTranslatef(3.0, 3.0, 0.0);

    glRotatef(45.0, 0.0, 0.0, 1.0);

    glScalef(0.5, 0.5, 0.0);

    render();

    glPopMatrix();



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



    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U4 S1 O4");

    glutSetWindow(windowHandle);



    glutDisplayFunc( display );

    glutReshapeFunc( reshape );



    initialize();



    glutMainLoop();

}
