//
//  main.cpp
//  menu
//
//  Created by Cynthia on 13/5/2020.
//  Copyright © 2020 Cynthia. All rights reserved.
//

#include "GLUT/glut.h"

GLsizei winWidth=400, winHeight=400;

GLfloat red =1.0, green=1.0, blue=1.0;
GLenum fillMode = GL_SMOOTH;

void init(void) {
    glClearColor(0.6,0.6,0.6,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 300, 0, 300);
    
}

void fillOption(GLint selectedOption){
    switch (selectedOption) {
        case 1:
            fillMode = GL_FLAT;
            break;
            
         case 2:
              fillMode = GL_SMOOTH;
              break;
    }
    glutPostRedisplay();
}

void displayTriangle(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(fillMode);
    glColor3f(red, green, blue);
    
    glBegin(GL_TRIANGLES);
    glVertex2i(280,20);
    glVertex2i(160, 280);
    glColor3f(red,0,0);
    glVertex2i(20,100);
    glEnd();
    
    glFlush();
}

void reshapeFcn(GLint newWidth, GLint newHeight){
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, GLfloat(newWidth), 0, GLfloat(newHeight));
    displayTriangle();
    glFlush();
}

int main (int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Menu Example");
    
    init();
    glutDisplayFunc(displayTriangle);
    
    glutCreateMenu(fillOption);
    glutAddMenuEntry("Solid-color Fill", 1);
    glutAddMenuEntry("Color-Interpolation Fill", 2);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutReshapeFunc(reshapeFcn);
    glutMainLoop();

    
    
}
