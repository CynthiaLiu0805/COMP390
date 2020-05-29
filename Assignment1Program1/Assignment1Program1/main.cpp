/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Assignment 1 program 1

   @author: Cynthia Liu
            student number: 3483785
 
   @details: This program draw two shape of houses using openGL line drawing tool, the top one is not anti-aliasing while the bottom one is

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



// render the upper pattern
void render_upper(){
    //set the color to black
    glColor3f(0.0, 0.0, 0.0);
    //the triangle
    glBegin (GL_LINE_LOOP);
            //top
            glVertex2f (-2,4);
            //right
            glVertex2f (-0.5,3.8);
            //left
            glVertex2f (-3,3);
    glEnd ();
    /*the rectangle, here can only use three lines to complete
     since one line is the same as the bottom of triangle*/
    glBegin (GL_LINE_STRIP);
            //upper right
            glVertex2f (-0.9,3.67);
            //bottom right
            glVertex2f (-0.3,2.1);
            //bottom left
            glVertex2f (-2.1,1.5);
            //upper left
            glVertex2f (-2.6,3.15);
    glEnd ();
}

// render the bottom pattern
void render_bottom(){
    //set the color to black
    glColor3f(0.0, 0.0, 0.0);
    //the triangle
    glBegin (GL_LINE_LOOP);
            //top
            glVertex2f (-1,1);
            //right
            glVertex2f (0.5,0.8);
            //left
            glVertex2f (-2,0);
    glEnd ();
    /*the rectangle, here can only use three lines to complete
     since one line is the same as the bottom of triangle*/
    glBegin (GL_LINE_STRIP);
            //upper right
            glVertex2f (0.1,0.67);
            //bottom right
            glVertex2f (0.7,-1.1);
            //bottom left
            glVertex2f (-1.1,-1.65);
            //upper left
            glVertex2f (-1.6,0.15);
    glEnd ();
}

// display registry
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // viewing
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //disable anti-aliasing to draw the first shape
    glDisable (GL_MULTISAMPLE_ARB);
    render_upper();
    
    //enable anti-aliasing for second shape
    glEnable (GL_MULTISAMPLE_ARB);
    render_bottom();
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
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE) ;
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Comp390 Assignment1Program1");
    glutSetWindow(windowHandle);
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    initialize();
    glutMainLoop();
}

