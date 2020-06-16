/* Athabasca University

   Comp390 - Introduction to Computer Graphics


   @author: Cynthia Liu

   @date: June 24, 2020

*/



#include "glut/glut.h"
#include <string.h>
#include <algorithm>


//color
GLfloat red1 =0.0, green1=0.0, blue1=0.0;
GLfloat red2 =0.0, green2=0.0, blue2=0.0;
GLfloat red3 =0.0, green3=0.0, blue3=0.0;
GLfloat ambient[4], diffuse[4], specular[4], shininess[1];
GLfloat lightElement[3];


//lights

    GLfloat light_position1[] = { -10.0, 10.0, 10.0, 0.0 };
    GLfloat light_position2[] = { 10.0, 10.0, 10.0, 0.0 };
    GLfloat light_position3[] = { 0,0,10,0 };   // behind the viewer


    GLfloat light1[] = { red1, green1, blue1, 1.0 };
    GLfloat light2[] = { red2, green2, blue2, 1.0 };
    GLfloat light3[] = { red3, green3, blue3, 1.0 };

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




void mainMenu(GLint renderingOption){
    glutPostRedisplay();
}

void Light1SubMenu(GLint colorOption){
    switch (colorOption) {
        //Off
        case 1:
            red1=0;green1=0;blue1=0;
        break;
        //white
        case 2:
            red1=1;green1=1;blue1=1;
        break;
        //red
        case 3:
            red1=1;green1=0;blue1=0;
        break;
        //blue
        case 4:
            red1=0;green1=0;blue1=1;
        break;
        //green
        case 5:
            red1=0;green1=1;blue1=0;
        break;
    }
    glutPostRedisplay();
}

void Light2SubMenu(GLint colorOption){
    switch (colorOption) {
        //Off
        case 1:
            red2=0;green2=0;blue2=0;
        break;
        //white
        case 2:
            red2=1;green2=1;blue2=1;
        break;
        //red
        case 3:
            red2=1;green2=0;blue2=0;
        break;
        //blue
        case 4:
            red2=0;green2=0;blue2=1;
        break;
        //green
        case 5:
            red1=0;green1=1;blue1=0;
        break;
    }
    glutPostRedisplay();
}

void Light3SubMenu(GLint colorOption){
    switch (colorOption) {
        //Off
        case 1:
            red3=0;green3=0;blue3=0;
        break;
        //white
        case 2:
            red3=1;green3=1;blue3=1;
        break;
        //red
        case 3:
            red3=1;green3=0;blue3=0;
        break;
        //blue
        case 4:
            red3=0;green3=0;blue3=1;
        break;
        //green
        case 5:
            red3=0;green3=1;blue3=0;
        break;
    }
    glutPostRedisplay();
}

void MaterialSubMenu(GLint materialOption){
    switch (materialOption) {
        //Gold
        case 1:
            std::copy(gold_specular, gold_specular + 4, specular);
            std::copy(gold_diffuse, gold_diffuse + 4, diffuse);
            std::copy(gold_shininess, gold_shininess + 4, shininess);
            break;
        //Silver
        case 2:
            std::copy(silver_specular, silver_specular + 4, specular);
            std::copy(silver_diffuse, silver_diffuse + 4, diffuse);
            std::copy(silver_shininess, silver_shininess + 4, shininess);
            break;
        //Copper
        case 3:
            std::copy(copper_specular, copper_specular + 4, specular);
            std::copy(copper_diffuse, copper_diffuse + 4, diffuse);
            std::copy(copper_shininess, copper_shininess + 4, shininess);
        break;
    }
    glutPostRedisplay();
}

void LightElementsSubMenu(GLint lightOption){
    switch (lightOption) {
        //Ambient only
        case 1:
            lightElement[0]=GL_AMBIENT;
            lightElement[1]=NULL;
            lightElement[2]=NULL;
        break;
        //Ambient and diffuse
        case 2:
            lightElement[0]=GL_AMBIENT;
            lightElement[1]=GL_DIFFUSE;
            lightElement[2]=NULL;
        break;
        //Ambient, diffuse and specular
        case 3:
            lightElement[0]=GL_AMBIENT;
            lightElement[1]=GL_DIFFUSE;
            lightElement[2]=GL_SPECULAR;
            
        break;
    }
    glutPostRedisplay();
}

void displayLight(){
    glEnable(GL_LIGHT1);
    GLfloat light1[] = { red1, green1, blue1, 1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    
    for (GLfloat element : lightElement){
        glLightfv(GL_LIGHT1, element, light1);
    }
    glEnable(GL_LIGHT2);
    GLfloat light2[] = { red2, green2, blue2, 1.0 };
    glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
    for (GLfloat element : lightElement){
        glLightfv(GL_LIGHT2, element, light2);
    }
    glEnable(GL_LIGHT3);
    GLfloat light3[] = { red3, green3, blue3, 1.0 };
    glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
    for (GLfloat element : lightElement){
        glLightfv(GL_LIGHT3, element, light3);
    }
}


void material(){

    
    glPushMatrix();

            glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
            glutSolidSphere(1.0, 64, 10);

    glPopMatrix();
    
    
    
}
// initialize

void initialize() {


    // set background color
    glClearColor(0.5, 0.7, 0.5, 0.0);
    glEnable (GL_BLEND);
    // enable depth test
    glEnable(GL_DEPTH_TEST);

    // enable lighting

    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

// render
void render() {

    glColor3f(0.5, 0.5, 0.5);

    material();
    displayLight();
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

int main(int argc, char **argv){

    glutInit( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Cynthia Liu - Assignment 3 program 1");
    glutSetWindow(windowHandle);
    glutDisplayFunc( display );

    
    GLint Light1;
    Light1 = glutCreateMenu(Light1SubMenu);
    glutAddMenuEntry("Off", 1);
    glutAddMenuEntry("White Light", 2);
    glutAddMenuEntry("Red Light", 3);
    glutAddMenuEntry("Blue Light", 4);
    glutAddMenuEntry("Green Light", 5);

    GLint Light2;
    Light2 = glutCreateMenu(Light2SubMenu);
    glutAddMenuEntry("Off", 1);
    glutAddMenuEntry("White Light", 2);
    glutAddMenuEntry("Red Light", 3);
    glutAddMenuEntry("Blue Light", 4);
    glutAddMenuEntry("Green Light", 5);
    
    GLint Light3;
    Light3 = glutCreateMenu(Light3SubMenu);
    glutAddMenuEntry("Off", 1);
    glutAddMenuEntry("White Light", 2);
    glutAddMenuEntry("Red Light", 3);
    glutAddMenuEntry("Blue Light", 4);
    glutAddMenuEntry("Green Light", 5);

    GLint Material;
    Material = glutCreateMenu(MaterialSubMenu);
    glutAddMenuEntry("Gold", 1);
    glutAddMenuEntry("Silver", 2);
    glutAddMenuEntry("Copper", 3);
    
    GLint LightElement;
    LightElement = glutCreateMenu(LightElementsSubMenu);
    glutAddMenuEntry("Ambient only", 1);
    glutAddMenuEntry("Ambient and Diffuse", 2);
    glutAddMenuEntry("Ambient, Diffuse and Specular", 3);
    
    glutCreateMenu(mainMenu);
    glutAddSubMenu("Light1", Light1);
    glutAddSubMenu("Light2", Light2);
    glutAddSubMenu("Light3", Light3);
    glutAddSubMenu("Material Properties", Material);
    glutAddSubMenu("Light Elements", LightElement);

    glutAddMenuEntry("Quit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutReshapeFunc( reshape );
    initialize();
    glutMainLoop();

}
