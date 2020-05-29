//
//  example.cpp
//  clipping
//
//  Created by Cynthia on 18/5/2020.
//  Copyright © 2020 Cynthia. All rights reserved.
//

#include "glut/glut.h"

class wcPt2D{
public: GLfloat x,y;
};

void init(void) {
    glClearColorIiEXT(1, 1, 1, 0);
    
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
    
    glMatrixMode(GL_MODELVIEW);
}

void triangle(wcPt2D *verts) {
    GLint k;
    
    glBegin(GL_TRIANGLES);
    for(k=0;k<3;k++)
        glVertex2f(verts[k].x, verts[k].y);
    glEnd();
}

void displayFcn(){
    wcPt2D verts[3] = {(-50,-25),(50,-25),(0,50)};
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0, 0, 1);
    glViewport(0, 0, 300, 300);
    triangle(verts);
    
    glColor3f(1, 0, 0);
    glViewport(300, 0, 300, 300);
    glRotatef(90, 0, 0, 1);
    triangle(verts);
    
    glFlush();
}



//comment out the other main to run
int main (int argc, char ** argv) {
    glutInit( &argc, argv );
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB) ;
    glutInitWindowSize(600, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Split-Screen Example");
    
    init();

    glutDisplayFunc(displayFcn);
    glutMainLoop();
    
}
