/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4

   Unit 7 Section 1 Objective 3

   GLUT Polyhedrons

   @author: Steve Leung

   @date: May 4, 2011
*/



#include "glut/glut.h"



// lights

    GLfloat light_position[] = { 1.0, 1.0, 10.0, 0.0 };

    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };



// some surface materials numbers

    // gold
//    GLfloat gold_ambient[] = { 30, 0.1995, 0.0745, 1.0 };


    GLfloat gold_ambient[] = { 0.24725, 0.1995, 0.0745, 1.0 };

    GLfloat gold_diffuse[] = { 0.75164, 0.60648, 0.22658, 1.0 };
                //if zero then: green, red, yellow
    GLfloat gold_specular[] = { 0.628281, 0.555802, 0.366065, 1.0 };

    GLfloat gold_shininess[] = { 51.2 };



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



    // set lights

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);

    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

}



void sphere() {

    glPushMatrix();

        glMaterialfv(GL_FRONT, GL_SPECULAR, copper_specular);

        glMaterialfv(GL_FRONT, GL_DIFFUSE, copper_diffuse);

        glMaterialfv(GL_FRONT, GL_SHININESS, copper_shininess);

        glTranslatef(-0.5, 0.0, 1.0);

        glutSolidSphere(1.0, 64, 10);
                    //radius, number of edge(边), 中心反光程度

    glPopMatrix();

}



void teapot() {

    glPushMatrix();

        glMaterialfv(GL_FRONT, GL_SPECULAR, gold_specular);

        glMaterialfv(GL_FRONT, GL_DIFFUSE, gold_diffuse);

        glMaterialfv(GL_FRONT, GL_SHININESS, gold_shininess);

        glTranslatef(-1.5, 0.0, 3.0);

        glutSolidTeapot(1.0);
        //defalut

    glPopMatrix();

}



void cone() {

    glPushMatrix();

        glTranslatef(2.0, 0.0, 2.8);


        glMaterialfv(GL_FRONT, GL_SPECULAR, gold_specular);

        glMaterialfv(GL_FRONT, GL_DIFFUSE, gold_diffuse);

        glMaterialfv(GL_FRONT, GL_SHININESS, gold_shininess);

        glutSolidCube(1.0);
    

    glPopMatrix();

}



void torus() {

    glPushMatrix();

        glTranslatef(1.5, 0.0, -4.0);



        glMaterialfv(GL_FRONT, GL_SPECULAR, gold_specular);

        glMaterialfv(GL_FRONT, GL_DIFFUSE, gold_diffuse);

        glMaterialfv(GL_FRONT, GL_SHININESS, gold_shininess);

        glutSolidTorus(0.5, 1.0, 32, 32);
                    //inner radius, outer radius, color, number of edge(边)

    glPopMatrix();

}



void tetrahedron() {

    glPushMatrix();

        glTranslatef(4.0, 0.0, -3.0);



        glMaterialfv(GL_FRONT, GL_SPECULAR, copper_specular);

        glMaterialfv(GL_FRONT, GL_DIFFUSE, copper_diffuse);

        glMaterialfv(GL_FRONT, GL_SHININESS, copper_shininess);



        glutSolidTetrahedron();

    glPopMatrix();

}



// render

void render() {

    sphere();

    teapot();

    cone();

    torus();

    tetrahedron();

}



// display registry

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();



    gluLookAt(0.0, 2.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



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

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH|GLUT_MULTISAMPLE ) ;

    glutInitWindowSize(500, 500);

      glutInitWindowPosition(100, 100);



    int windowHandle = glutCreateWindow("Athabasca University - Comp390 U7 S1 O3");

    glutSetWindow(windowHandle);



    glutDisplayFunc( display );

    glutReshapeFunc( reshape );



    initialize();



    glutMainLoop();

}
