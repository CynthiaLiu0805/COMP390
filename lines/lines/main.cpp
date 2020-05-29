/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 3 Section 2 Objective 2

   Draw a line



   @author: Steve Leung

   @date: May 4, 2011

*/



#include "GLUT/glut.h"
#include <stdlib.h>
#include <math.h>

void setPixel(int x, int y)
{
    glColor3f(0.0, 0.0, 0.0); //Set pixel to black
    glBegin(GL_POINTS);
    glVertex2i(x, y); //Set pixel coordinates
    glEnd();
    glFlush(); //Render pixel
}


// initialize

void initialize() {

    // set background color

    glClearColor(1.0, 1.0, 1.0, 0.0);

}



// render

void render() {
    // points color
    glColor3f(0.0, 0.0, 0.0);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH |GLUT_RGBA | GLUT_MULTISAMPLE);
    // line
    glBegin(GL_LINES);
        glVertex2f(-3.0, 0.0);
        glVertex2f(0.0, 3.0);
    glVertex2f(0.0, 0.0);
        glVertex2f(3.0, 3.0);
    glEnd();
}

void rect(){
        // color, black
        glColor3f(0.0, 0.0, 0.0);
        // rectangle
        glBegin(GL_QUADS);
            glVertex2f(-2.0f, -2.5f);
            glVertex2f(-2.0f, 2.5f);
            glVertex2f(3.0f, 2.5f);
            glVertex2f(3.0f, -2.5f);
        glEnd();
}

void polygon(){
    //多边形
    glColor3f(0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
              glVertex2i (0,0);
              glVertex2i (1,0);
              glVertex2i (2,1);
              glVertex2i (1,2);
              glVertex2i (0,2);
              glVertex2i (-1,1);
    glEnd ();
}

void triangles(){
    //分开的三角形
    glColor3f(0.0, 0.0, 0.0);
    glBegin (GL_TRIANGLES);
              glVertex2i (1,0);
              glVertex2i (2,1);
              glVertex2i (2,-1);
              glVertex2i (0,0);
              glVertex2i (-1,-1);
              glVertex2i (-1,1);
    glEnd ();
}

void triangleStrip(){
    //分开的三角形
    glColor3f(0.0, 0.0, 1.0);
    glBegin (GL_TRIANGLE_STRIP);
              glVertex2i (-1,1);
              glVertex2i (0,0);
              glVertex2i (0,2);
              glVertex2i (1,0);
              glVertex2i (1,2);
              glVertex2i (2,1);
    glEnd ();
}


void triangleFan(){
    //多边形
    glColor3f(0.0, 0.0, 0.0);
    glBegin (GL_TRIANGLE_FAN);
              glVertex2i (0,0);
              glVertex2i (1,0);
              glVertex2i (2,1);
              glVertex2i (1,2);
              glVertex2i (0,2);
              glVertex2i (-1,1);
    glEnd ();
}


// display registry

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // viewing
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //    render();
    //    rect();
//    polygon();
//    triangles();
//    triangleStrip();
    triangleFan();
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

GLint points [8][3] = { {0, 0, 0}, {0, 1, 0}, {1, 0, 0}, {1, 1, 0},
                                                             {0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1} };
typedef GLint vertex3 [3];
vertex3 pt [8] = { {0, 0, 0}, {0, 1, 0}, {1, 0, 0}, {1, 1, 0},
                                                {0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1} };

void quad (GLint n1, GLint n2, GLint n3, GLint n4)
{
        glBegin (GL_QUADS);
                glVertex3iv (pt [n1]);
                glVertex3iv (pt [n2]);
                glVertex3iv (pt [n3]);
                glVertex3iv (pt [n4]);
        glEnd ();
}
void cube ()
{
        quad (6, 2, 3, 7);
        quad (5, 1, 0, 4);
        quad (7, 3, 1, 5);
        quad (4, 0, 2, 6);
        quad (2, 0, 1, 3);
        quad (7, 5, 4, 6);
}

// main program

int main(int argc, char **argv){
    
    
    glutInit( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U3 S2 O2");
    glutSetWindow(windowHandle);
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    initialize();
    glutMainLoop();
}
