/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 8 Section 2 Objective 1

   Light sources



   @author: Steve Leung

   @date: May 4, 2011

*/



#include "glut/glut.h"



// lights

    GLfloat light_position0[] = { -10.0, 10.0, 10.0, 0.0 };

    GLfloat light_position1[] = { 10.0, 10.0, 10.0, 0.0 };

    GLfloat light_position2[] = { 0,0,10,0 };   // behind the viewer


    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat green_light[] = { 0.2, 1.0, 0.2, 1.0 };

    GLfloat red_light[] = { 1.0, 0.4, 0.4, 1.0 };

    GLfloat blue_light[] = { 0.2, 0.2, 1.0, 1.0 };

    GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };



// some surface materials parameters

    // gold
    GLfloat gold_ambient[] = { 0.24725, 0.1995, 0.0745, 1.0 };
    GLfloat gold_diffuse[] = { 0.75164, 0.60648, 0.22658, 1.0 };
    GLfloat gold_specular[] = { 0.628281, 0.555802, 0.366065, 1.0 };
    GLfloat gold_shininess[] = { 51.2 };


    // silver
    GLfloat silver_ambient[] = { 0.19225, 0.19225, 0.19225, 1.0 };
    GLfloat silver_diffuse[] = { 0.50754, 0.50754, 0.50754, 1.0 };
    GLfloat silver_specular[] = { 0.508273, 0.508273, 0.508273, 1.0 };
    GLfloat silver_shininess[] = { 51.2 };


    // copper
    GLfloat copper_ambient[] = { 0.2295, 0.08825, 0.0275, 1.0 };
    GLfloat copper_diffuse[] = { 0.5508, 0.2118, 0.066, 1.0 };
    GLfloat copper_specular[] = { 0.580594, 0.223257, 0.0695701, 1.0 };
    GLfloat copper_shininess[] = { 51.2 };



// initialize

void initialize() {

    // set background color

    glClearColor(0.5, 0.7, 0.5, 0.0);



    // enable depth test

    glEnable(GL_DEPTH_TEST);



    // enable lighting

    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    glEnable(GL_LIGHT1);

    glEnable(GL_LIGHT2);            // don't forget to enable light 2



    // set lights

    // light 0, top left

    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);

    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);



    // light 1, top right

    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, red_light);

    glLightfv(GL_LIGHT1, GL_SPECULAR, red_light);



    // light 2

     glLightfv(GL_LIGHT2, GL_POSITION, light_position2);

     glLightfv(GL_LIGHT2, GL_DIFFUSE, blue_light);

     glLightfv(GL_LIGHT2, GL_SPECULAR, blue_light);



    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

}



// render

void render() {

    glColor3f(0.5, 0.5, 0.5);

    glPushMatrix();

//        glMaterialfv(GL_FRONT, GL_SPECULAR, gold_specular);
//
//        glMaterialfv(GL_FRONT, GL_DIFFUSE, gold_diffuse);
//
//        glMaterialfv(GL_FRONT, GL_SHININESS, gold_shininess);

        glutSolidSphere(1.0, 64, 10);

    glPopMatrix();

}



// display registry

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();



    gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



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



    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U8 S2 O1");

    glutSetWindow(windowHandle);



    glutDisplayFunc( display );

    glutReshapeFunc( reshape );



    initialize();



    glutMainLoop();

}
