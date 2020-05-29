/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 4 Section 2 Objective 2



   @author: Steve Leung

   @date: May 4, 2011

*/



#include "glut/glut.h"





void initialize(void) {

    // set background color

    glClearColor(0.5, 0.7, 0.5, 0.0);

}



void render() {

    // original

    glColor3f(0.5, 0.1, 0.1);

    glBegin( GL_QUADS );

        glVertex3f(-2.0, -2.0, 0.0);

        glVertex3f(-2.0, 2.0, 0.0);

        glVertex3f(2.0, 2.0, 0.0);

        glVertex3f(2.0, -2.0, 0.0);

    glEnd();

}



void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();



    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



    render();



    glFlush();

    glutSwapBuffers();

}



void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);

    glMatrixMode(GL_MODELVIEW);

}



//int main(int argc, char **argv){
//    glutInit( &argc, argv );
//    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    int windowHandle = glutCreateWindow("Comp390 Unit 4 Section 2 Objective 2");
//    glutSetWindow(windowHandle);
//    glutReshapeWindow (400,400);
//    glutDisplayFunc( display );
//    glutReshapeFunc( reshape);
//    initialize();
//    glutMainLoop();
//}
