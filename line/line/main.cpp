//
//  line.cpp
//  test
//
//  Created by Cynthia on 7/5/2020.
//  Copyright © 2020 Cynthia. All rights reserved.
//

#include <GLUT/glut.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 150);
    
}
void lineSegment(void){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINES);
    glVertex2i(180,15);
    glVertex2i(10,145);
    glEnd();
    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("A line");
    
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
}

