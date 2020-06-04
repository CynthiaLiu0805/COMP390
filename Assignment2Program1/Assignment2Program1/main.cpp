/* Athabasca University
   Comp390 - Introduction to Computer Graphics
   @author: Cynthia Liu

   @date: June 14, 2020

*/



#include <iostream>

#include "glut/glut.h"



using namespace std;
GLuint myList;



// vertex array
typedef GLint vertexCube [3];
vertexCube cube [8] = { {0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, {0,1,1}, {0,0,1}, {1,0,1}, {1,1,1} };

typedef GLfloat vertexPyramid[3];
vertexPyramid pyramid [5] = { {0.5, 1.5, 0.5}, {-0.2, 1.0, -0.2}, {1.2,1,-0.2}, {1.2, 1.0, 1.2}, {-0.2,1,1.2} };



// get matrix
void showMatrix() {
    GLdouble m[16];
    glGetDoublev(GL_MODELVIEW, m);
    
    for (int i=0; i<4; i++) {
        cout << m[i*4] << " " << m[i*4+1] << " " << m[i*4+2] << " " << m[i*4+3] << endl;
    }
    cout << endl;
    
}





// draw the triangle with position of each vertex
void triangle (GLint n1, GLint n2, GLint n3) {
    glBegin (GL_POLYGON);
    
        glVertex3fv (pyramid[n1]);
        glVertex3fv (pyramid[n2]);
        glVertex3fv (pyramid[n3]);
    
    glEnd();
}
void top () {
    //each vertex
    triangle(0, 1, 2);
    triangle(0, 2, 3);
    triangle(0, 3, 4);
    triangle(0, 4, 1);
}


// draw the square with position of each vertex
void quad (GLint n1, GLint n2, GLint n3, GLint n4) {
    glBegin (GL_POLYGON);
    
        glVertex3iv (cube[n1]);
        glVertex3iv (cube[n2]);
        glVertex3iv (cube[n3]);
        glVertex3iv (cube[n4]);
    
    glEnd();
}
void body () {
    //each vertex
     quad(0,1,2,3);
     quad(4,5,6,7);
     quad(2,3,4,7);
     quad(0,5,6,1);
     quad(0,3,4,5);
     quad(1,2,7,6);
}

//draw the ground
void ground(){
    glBegin (GL_POLYGON);
    
        glVertex3f (-1.0, 0.0, -0.5);
        glVertex3f (2.0,0.0, -0.5);
        glVertex3f (2.0, 0.0, 2.5);
        glVertex3f (-1.0, 0.0, 2.5);
    
    glEnd();
}

// initialize
void initialize() {
    // set background color
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
    myList = glGenLists(1);

    glNewList(myList, GL_COMPILE);
       
        //green ground
        glColor3f(0.0, 1.0, 0.0);
        ground();
    
        // red cube
        glColor3f(1.0, 0.0, 0.0);
        body();
    
        //blue pyramid
        glColor3f(0.0, 0.0, 1.0);
        top();
    
    glEndList();
    
}




// render
void render() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glCallList(myList);
}



// display registry
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //the viewing position(reference point)
    gluLookAt(3, 3, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
int main(int argc, char **argv){
    glutInit( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Assignment 2 Program 1 - Cynthia Liu");
    glutSetWindow(windowHandle);
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    initialize();
    glutMainLoop();
}
