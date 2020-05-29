/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 6 Section 2 Objective 3

   3D transformation matrix



   @author: Steve Leung

   @date: May 4, 2011

*/



#include <iostream>

#include "glut/glut.h"



using namespace std;



// vertex array

typedef GLint vertex3 [3];



vertex3 pt [8] = { {0,0,0}, {0,1,0}, {1,0,0}, {1,1,0}, {0,0,1}, {0,1,1}, {1,0,1}, {1,1,1} };



// initialize

void initialize() {

    // set background color

    glClearColor(1.0, 1.0, 1.0, 0.0);

}



// get matrix

 void showMatrix() {

    GLdouble m[16];

    glGetDoublev(GL_MODELVIEW, m);



    for (int i=0; i<4; i++) {

        cout << m[i*4] << " " << m[i*4+1] << " " << m[i*4+2] << " " << m[i*4+3] << endl;

    }



    cout << endl;

}



// adapt from Hearn & Baker, ed. 4, p. 77

void quad (GLint n1, GLint n2, GLint n3, GLint n4) {

    glBegin (GL_LINE_LOOP);

        glVertex3iv (pt[n1]);

        glVertex3iv (pt[n2]);

        glVertex3iv (pt[n3]);

        glVertex3iv (pt[n4]);

    glEnd();

}



void cube () {

    quad(6,2,3,7);

    quad(5,1,0,4);

    quad(7,3,1,5);

    quad(4,0,2,6);

    quad(2,0,1,3);

    quad(7,5,4,6);

}



// render

void render() {

    
    // original

    glColor3f(0.0, 0.0, 0.0);

    cube();



    // translation codes to be added here

    glPushMatrix();
    glTranslatef(-2, 0, 0);
    glColor3f(1.0, 0.0, 0.0);// color red
    cube();
    glPopMatrix();

    // translation and scaling codes to be added here

    glPushMatrix();
    glTranslatef(2, 0, 0);
    glScalef(0.5, 0.5,0.5);
    glColor3f(0.0, 1.0, 0.0);// color green
    cube();
    glPopMatrix();


    // translation and rotation codes to be added here
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(315, 0,0 , 1); //rotate about z axis
    glColor3f(0.0, 0.0, 1.0); // color blue
    cube();
    glPopMatrix();



    // translation, scaling and rotation codes
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(315, 0, 0, 1);

    glColor3f(1.0, 1.0, 0.0); // color yellow
    cube();
    glPopMatrix();

}



// display registry

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();



    // viewing

    gluLookAt(1.5, 1.5, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

//    gluLookAt(0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



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



    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U6 S2 O3");

    glutSetWindow(windowHandle);



    glutDisplayFunc( display );

    glutReshapeFunc( reshape );



    initialize();



    glutMainLoop();

}
