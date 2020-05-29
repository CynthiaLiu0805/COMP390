/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Assignment 1 program 2

   @author: Cynthia Liu
            student number: 3483785
 
   @details: This program draw one shape of houses first and then use it to translate to the other four houses

   @date: June 4, 2020

*/



#include "GLUT/glut.h"
#include <stdlib.h>
#include <math.h>


// initialize
void initialize() {
    // set background color
    glClearColor(1.0, 1.0, 1.0, 0.0);
}



// render the first shape: the one in the middle
void render(){
    //set the color to black
    glColor3f(0.0, 0.0, 0.0);
    //the triangle
    glBegin (GL_LINE_LOOP);
            //top
            glVertex2f (0,2.5);
            //right
            glVertex2f (0.75,2);
            //left
            glVertex2f (-0.75,2);
    glEnd ();
    /*the rectangle, here can only use three lines to complete
     since one line is the same as the bottom of triangle*/
    glBegin (GL_LINE_STRIP);
            //upper right
            glVertex2f (0.5,2);
            //bottom right
            glVertex2f (0.5,1);
            //bottom left
            glVertex2f (-0.5,1);
            //upper left
            glVertex2f (-0.5,2);
    glEnd ();
}

//rotate by 30


// display registry
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // viewing
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    render();
    
    //first from left
    glPushMatrix();
    glRotatef(30.0, 0.0, 0.0, 1.0);
    glTranslatef(-3.5, 1., 0.0);
    render();
    glPopMatrix();
    
    
    //second from left
    glPushMatrix();
    glRotatef(15.0, 0.0, 0.0, 1.0);
    glTranslatef(-1.75, 0.25, 0.0);
    render();
    glPopMatrix();
    
    //second from right
    glPushMatrix();
    glRotatef(-15.0, 0.0, 0.0, 1.0);
    glTranslatef(1.75, 0.25, 0.0);
    render();
    glPopMatrix();
    
    //first from right
    glPushMatrix();
    glRotatef(-30.0, 0.0, 0.0, 1.0);
    glTranslatef(3.5, 1, 0.0);
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

int main(int argc, char **argv){
    glutInit( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Comp390 Assignment1Program1");
    glutSetWindow(windowHandle);
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    initialize();
    glutMainLoop();
}

