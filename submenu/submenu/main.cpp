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
GLenum renderingMode = GL_SMOOTH;

void init(void) {
    glClearColor(0.6,0.6,0.6,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 300, 0, 300);
    
}

void mainMenu(GLint renderingOption){
    switch (renderingOption) {
        case 1:
            renderingMode = GL_FLAT;
            break;
            
         case 2:
              renderingMode = GL_SMOOTH;
              break;
    }
    glutPostRedisplay();
}

void colorSubMenu(GLint colorOption){
    switch (colorOption) {
        case 1:
            red=0;green=0;blue=1;
            break;
            
        case 2:
            red=0;green=1;blue=0;
        break;
        case 3:
            red=1;green=0;blue=0;
        break;
    }
    glutPostRedisplay();
}

void displayTriangle(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(renderingMode);
    glColor3f(red, green, blue);
    
    glBegin(GL_TRIANGLES);
    glVertex2i(280,20);
    glVertex2i(160, 280);
    glColor3f(1,0,0);
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
    GLint subMenu;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Menu Example");
    
    init();
    glutDisplayFunc(displayTriangle);
    
    subMenu = glutCreateMenu(colorSubMenu);
    glutAddMenuEntry("Blue", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("White", 3);

    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Solid-color Fill", 1);
    glutAddMenuEntry("Color-Interpolation Fill", 2);
    glutAddSubMenu("Color", subMenu);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutReshapeFunc(reshapeFcn);
    glutMainLoop();

}
