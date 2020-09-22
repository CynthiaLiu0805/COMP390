/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Assignment 3 program 3

   @author: Yingxue(Cynthia) Liu
    student number: 3483785

   @details: This program is based on Assignment 2 program 2 and the code in Unit 9 Section 1 Objective 2, adding a background picture to the origin program
        This program is run with visual studio on a virtual machine of windows on macbook

   @date: July 4, 2020

*/



#include <iostream>
#include "windows.h" 
#include "gl/glut.h"
#include "math.h" 


using namespace std;
GLuint myList;

// vertex array
typedef GLint vertexCube[3];
vertexCube cube[8] = { {0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, {0,1,1}, {0,0,1},   {1,0,1}, {1,1,1} };

typedef GLfloat vertexPyramid[3];
vertexPyramid pyramid[5] = { {0.5, 1.5, 0.5}, {-0.2, 1.0, -0.2}, {1.2,1,-0.2}, {1.2, 1.0, 1.2}, {-0.2,1,1.2} };

// image
GLubyte* image;
//unsigned char * l_texture;
GLubyte* l_texture;
BITMAPFILEHEADER fileheader;
BITMAPINFOHEADER infoheader;
RGBTRIPLE rgb;
GLuint texName;





// draw the triangle with position of each vertex
void triangle(GLint n1, GLint n2, GLint n3) {
    glBegin(GL_POLYGON);

    glVertex3fv(pyramid[n1]);
    glVertex3fv(pyramid[n2]);
    glVertex3fv(pyramid[n3]);

    glEnd();
}
void top() {
    //each vertex
    triangle(0, 1, 2);
    triangle(0, 2, 3);
    triangle(0, 3, 4);
    triangle(0, 4, 1);
}


// draw the square with position of each vertex
void quad(GLint n1, GLint n2, GLint n3, GLint n4) {
    glBegin(GL_POLYGON);

    glVertex3iv(cube[n1]);
    glVertex3iv(cube[n2]);
    glVertex3iv(cube[n3]);
    glVertex3iv(cube[n4]);

    glEnd();
}
void body() {
    //each vertex
    quad(0, 1, 2, 3);
    quad(4, 5, 6, 7);
    quad(2, 3, 4, 7);
    quad(0, 5, 6, 1);
    quad(0, 3, 4, 5);
    quad(1, 2, 7, 6);
}

//draw the ground
void ground() {
    glBegin(GL_POLYGON);

    glVertex3f(-1.0, 0.0, -0.5);
    glVertex3f(2.0, 0.0, -0.5);
    glVertex3f(2.0, 0.0, 2.5);
    glVertex3f(-1.0, 0.0, 2.5);

    glEnd();
}

//the gray ground
void grayGround() {
    glBegin(GL_POLYGON);

    glVertex3f(-8.0, -0.1, -8.0);
    glVertex3f(8.0, -0.1, -8.0);
    glVertex3f(8.0, -0.1, 8.0);
    glVertex3f(-8.0, -0.1, 8.0);

    glEnd();
}


void displayHouse() {
    //green ground
    glColor3f(0.0, 1.0, 0.0);
    ground();

    // red cube
    glColor3f(1.0, 0.0, 0.0);
    body();

    //blue pyramid
    glColor3f(0.0, 0.0, 1.0);
    top();

}




void makeImage(void) {

    int i, j = 0;
    FILE* l_file;

    string fn = "side.bmp";
    const char* filename = fn.c_str();

    // open image file, return if error
    fopen_s(&l_file, filename, "rb");
    if (l_file == NULL) return;

    // read file header and header info
    fread(&fileheader, sizeof(fileheader), 1, l_file);
    fseek(l_file, sizeof(fileheader), SEEK_SET);
    fread(&infoheader, sizeof(infoheader), 1, l_file);



    // allocate space for the image file
    l_texture = (GLubyte*)malloc(infoheader.biWidth * infoheader.biHeight * 4);
    memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);



    // read da data
    j = 0;
    for (i = 0; i < infoheader.biWidth * infoheader.biHeight; i++){

        fread(&rgb, sizeof(rgb), 1, l_file);
        l_texture[j + 0] = (GLubyte)rgb.rgbtRed; // Red component
        l_texture[j + 1] = (GLubyte)rgb.rgbtGreen; // Green component
        l_texture[j + 2] = (GLubyte)rgb.rgbtBlue; // Blue component
        l_texture[j + 3] = (GLubyte)255; // Alpha value
        j += 4; // Go to the next position

    }

    fclose(l_file); // Closes the file stream

}



void initialize() {
    // set background color
    glClearColor(0.2, 0.6, 0.8, 0.0);

    // image
    makeImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // set pixel storage mode
    glGenTextures(1, &texName); //generates texture name
    glBindTexture(GL_TEXTURE_2D, texName); //binds texture to name
    //sets wrap and magnifying/minifying parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    //set parameters for 2D texture space
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,l_texture);

}

void background() {
    glEnable(GL_TEXTURE_2D); 
    
    //the background on the left
    glBegin(GL_QUADS); 
    glTexCoord2d(0.0, 0.0); glVertex3f(-8.0, -0.1, -8.0); 
    glTexCoord2d(0.0, 1.0); glVertex3f(-8.0, 16.0, -8.0); 
    glTexCoord2d(1.0, 1.0); glVertex3f(-8.0, 16.0, 8.0); 
    glTexCoord2d(1.0, 0.0); glVertex3f(-8.0, -0.1, 8.0); 
    glEnd();

    //the background on the back
    glBegin(GL_QUADS); 
    glTexCoord2d(0.0, 0.0); glVertex3f(-8.0, -0.1, -8.0); 
    glTexCoord2d(0.0, 1.0); glVertex3f(-8.0, 16.0, -8.0); 
    glTexCoord2d(1.0, 1.0); glVertex3f(8.0, 16.0, -8.0); 
    glTexCoord2d(1.0, 0.0); glVertex3f(8.0, -0.1, -8.0); 
    glEnd();

}

// render
void render() {
   
    background();

    //disable texture so that the polygons can be shown, or they are all black
    glDisable(GL_TEXTURE_2D);

    glColor3f(0.5, 0.5, 0.5);
    grayGround();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    //most far left with rotation
    glPushMatrix();
    glTranslatef(-5, 0, -5);
    glRotatef(45, 0, 1, 0); //rotate about y axis
    displayHouse();
    glPopMatrix();

    //the one after origin one with scaling in x axis
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1.5, 1.0, 1.0);
    displayHouse();
    glPopMatrix();

    //the one one far right corner with scaling in y axis
    glPushMatrix();
    glTranslatef(5, 0, -5);
    glScalef(1.0, 2.0, 1.0);
    displayHouse();
    glPopMatrix();

    //the one on the left of origin one
    glPushMatrix();
    glTranslatef(-5, 0, 0);
    displayHouse();
    glPopMatrix();

    //the one on the right of origin one
    glPushMatrix();
    glTranslatef(5, 0, 0);
    displayHouse();
    glPopMatrix();

    //the center one
    displayHouse();

    //the left closest one
    glPushMatrix();
    glTranslatef(-4, 0, 4);
    glScalef(2.0, 1.0, 1.0);
     displayHouse();
    glPopMatrix();

    //the right closest one
    glPushMatrix();
    glTranslatef(4, 0, 4);
    glScalef(2.0, 1.0, 1.0);
    displayHouse();
    glPopMatrix();
}



// display
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //the viewing position(reference point)
    gluLookAt(5, 4, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 
    render();
    glutSwapBuffers();
}



// reshape
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);
    glMatrixMode(GL_MODELVIEW);
}



// main program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Yingxue Liu - Assignment 3 Program 3");
    glutSetWindow(windowHandle);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initialize();
    glutMainLoop();
}

