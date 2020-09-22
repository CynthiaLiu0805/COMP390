//
//  reflection.cpp
//  Assignment4Program2
//
//  Created by Cynthia on 15/7/2020.
//  Copyright © 2020 Cynthia. All rights reserved.
//
/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Assignment 4 program 2


   @author: Yingxue(Cynthia) Liu
    student number: 3483785
 
   @details: This program is based on the code in program 1 and implement a shadow for the wall.
 
   @date: July 15, 2020

*/
#include <iostream>


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "glut/glut.h"
#define GL_SILENCE_DEPRECATION
#include "plane.hpp"
#include "reflection.hpp"



using namespace std;



    // viewer
    vector3 viewer(-90.0, 160.0, 100.0);



    // floor
    vector3 floorNormal(0.0, 1.0, 0.0);

    //floor equation
    plane   floorDef(0.0, 4.0, 0.0, 0.0);
    vector3 floorLimit1(-75.0, 0, -75.0);
    vector3 floorLimit2(-75.0, 0, 75.0);
    vector3 floorLimit3(75.0, 0, 75.0);
    vector3 floorLimit4(75.0, 0, -75.0);

    

    // wall
    vector3 wallNormal1(0.0, 0.0, 1.0);
    plane   wall1(0.0, 0.0, 4.0, 0.0);
    vector3 wallLimit1(-25.0, 0.0, 0.0);
    vector3 wallLimit2(-25.0, 50.0, 0.0);
    vector3 wallLimit3(25.0, 50.0, 0.0);
    vector3 wallLimit4(25.0, 0.0, 0.0);

    vector3 wallNormal2(0.0, 1.0, 0.0);
    plane   wall2(0.0, 1.0, 0.0, 0.0);
    vector3 wallLimit5(-25.0, 0.0, 0.0);
    vector3 wallLimit6(-25.0, 50.0, 0.0);
    vector3 wallLimit7(25.0, 50.0, 25.0);
    vector3 wallLimit8(25.0, 0.0, 25.0);



    // colors
    vector3 grey(0.75, 0.75, 0.75);
    vector3 lightRed(0.75, 0.1, 0.1);
    vector3 grey_white(0.9, 0.9, 0.9);

    

    // lighting position
    vector3 lightPosition(50, 50, 100.0);



    // lighting elements
    float ambient_coef = 0.3;
    float diffuse_coef = 0.7;
    float reflect_coef = 0.4;
    float local_coef   = 0.6;


// arrays used in the ray tracer - hold characteristics of the different planar surfaces
plane planes[] = { floorDef, wall1,wall2 }; // plane equations
//vector3 colors[] = { white, lightRed, lightBlue, lightGreen, lightYellow, grey, grey, grey, black, cyan }; // colors
vector3 normals[] = { floorNormal, wallNormal1, wallNormal2}; // normals

// vector used to hold intersection points - used in ray tracer (avoids some redundant calculations)
vector3 fInt(0.0, 0.0, 0.0); // floor/ray intersection
vector3 wall1Int(0.0, 0.0, 0.0); // red face of cube/ray intersection
vector3 wall2Int(0.0, 0.0, 0.0); // blue face of cube/ray intersection
//vector3 gwInt(0.0, 0.0, 0.0); // green face of cube/ray intersection
//vector3 ywInt(0.0, 0.0, 0.0); // yellow face of cube/ray intersection
//vector3 topInt(0.0, 0.0, 0.0); // top face of cube/ray intersection
//vector3 rightInt(0.0, 0.0, 0.0); // right mirror wall/ray intersection
//vector3 leftInt(0.0, 0.0, 0.0); // left mirror wall/ray intersection
//vector3 backInt(0.0, 0.0, 0.0); // back mirror wall/ray intersection


void initialize() {

    // set background color
    glClearColor(0.5, 0.7, 0.5, 0.0);

    // set the limits of the wall
    wall1.setP1(wallLimit1);
    wall1.setP2(wallLimit2);
    wall1.setP3(wallLimit3);
    wall1.setP4(wallLimit4);
    
    wall2.setP1(wallLimit5);
    wall2.setP2(wallLimit6);
    wall2.setP3(wallLimit7);
    wall2.setP4(wallLimit8);
    
    // set the limits of the floor
    floorDef.setP1(floorLimit1);
    floorDef.setP2(floorLimit2);
    floorDef.setP3(floorLimit3);
    floorDef.setP4(floorLimit4);
}



// calculate local color by intensity * base color
vector3 localColor(vector3 intersect, vector3 baseColor, vector3 normal) {

    // calculate unit vector
    vector3 origin = lightPosition.subtract(intersect);
    vector3 unitVec = origin.normalize();

    // calculate dot product
    float dotProd = unitVec.dot(normal);

    // calculate intensity
    float ambientContr = ambient_coef;
    float diffuseContr = diffuse_coef * dotProd;
    float intensity = ambientContr + diffuseContr;

    if (intensity > 1.0) intensity = 1.0;
    float r = intensity * baseColor.x;
    float g = intensity * baseColor.y;
    float b = intensity * baseColor.z;

    return vector3(r,g,b);
}

//find maximum among 4 numbers
float maximum(float a, float b, float c, float d){
    return max(max(a, b), max(c, d));
}

//find minimum among 4 numbers
float minimum(float a, float b, float c, float d){
    return min(min(a, b), min(c, d));
}

// check whether a point is in a plane
bool inPlane(vector3 point, plane plane) {
    // check each boundaries
    if ((point.x <= maximum(plane.p1x, plane.p2x, plane.p3x, plane.p4x)+0.1) &&
         (point.x >= minimum(plane.p1x, plane.p2x, plane.p3x, plane.p4x)-0.1) &&
         (point.y <= maximum(plane.p1y, plane.p2y, plane.p3y, plane.p4y)+0.1) &&
         (point.y >= minimum(plane.p1y, plane.p2y, plane.p3y, plane.p4y)-0.1) &&
         (point.z <= maximum(plane.p1z, plane.p2z, plane.p3z, plane.p4z)+0.1) &&
         (point.z >= minimum(plane.p1z, plane.p2z, plane.p3z, plane.p4z)-0.1))
        return true;
    else
        return false;
}

//check if a ray intersect with a plane
bool hasIntersection (vector3 viewerPosition, vector3 direction) {
    //find the intersection of viewer and current intersect(viewer add direction is a vector from origin point to the point that's looping on)
    vector3 floorIntersection = floorDef.intersect(viewerPosition, viewerPosition.add(direction)); // floor intersection
    vector3 wallIntersection1 = wall1.intersect(viewerPosition, viewerPosition.add(direction)); // wall intersection
    
//    vector3 wallIntersection2 = wall1.intersect(viewerPosition, viewerPosition.add(direction)); // wall intersection
    

    // check if the point is on the floor
    if( (inPlane(floorIntersection, floorDef) ) || (inPlane(wallIntersection1, wall1) ) )
        return true;
    else
        return false;
}

//the resursive method to display
vector3 rayTracer(vector3 viewerPosition, vector3 direction, int count, vector3 wallNormal) {
    
    // check if the ray has intersection with the plane
    if ( (!hasIntersection(viewerPosition, direction)) || (count > 5)  ) {
        return vector3(0.5, 0.7, 0.5);
    } else {
        
        //find the intersection
        vector3 floorIntersection = floorDef.intersect(viewerPosition, viewerPosition.add(direction));
        vector3 wallIntersection = wall1.intersect(viewerPosition, viewerPosition.add(direction));

        //assume the vector from floorIntersection to lightPosition intersect with wall, find the intersection
        vector3 intersectionWithWall = wall1.intersect(floorIntersection, lightPosition);

        
        // set the color of the intersection
        if( inPlane(wallIntersection, wall1) ) {
            return localColor(wallIntersection, lightRed, wallNormal);
        }
        
        else {
            
            vector3 floorColor =  localColor(floorIntersection, grey, floorNormal);
            vector3 reflectiveRay = direction.reflect(floorNormal);
            vector3 rayNormal = reflectiveRay.normalize();
            
            //recursive method to set reflective color
            vector3 reflectiveColor = rayTracer(floorIntersection, rayNormal, count + 1, wallNormal);
            
            //check if the intersection with wall is on the wall
            if ( (intersectionWithWall.x >= wall1.p1x) && (intersectionWithWall.x <= wall1.p3x) && (intersectionWithWall.y >= wall1.p4y) && (intersectionWithWall.y <= wall1.p3y) ) {
                    floorColor = grey.scalar(ambient_coef);
            
                }
            
            floorColor = floorColor.scalar(local_coef).add(reflectiveColor.scalar(reflect_coef));
            

            return floorColor;
        }
    }
}

void render_wall(vector3 wallNormal,plane wall){
    for (int m=-350; m<350; m++) {
        for(int n=-350; n<350; n++) {
            vector3 intersect = vector3(m, n, 0); //the point that is loading
            vector3 direction = intersect.subtract(viewer); //direction from viewer to the point
            vector3 color = rayTracer(viewer, direction, 0, wallNormal); //color for current point

            glColor3f(color.x, color.y, color.z); // sets current color
            glRecti(m, n, m+1, n+1);
        }
    }
}

//render
void render() {
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // loops through each pixel in the display
    render_wall(wallNormal1, wall1);
    render_wall(wallNormal2, wall2);

}

// display registry

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(viewer.x, viewer.y, viewer.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    render();
    glutSwapBuffers();
}



// reshape registry
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 350.0);
    glMatrixMode(GL_MODELVIEW);
}



// main program

int main(int argc, char **argv){
    glutInit( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Cynthia Liu - Assignment4Program2");
    glutSetWindow(windowHandle);
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    initialize();
    glutMainLoop();
}
