//
//  plane.hpp
//  Assignment4Program1
//
//  Created by Cynthia on 12/7/2020.
//  Copyright © 2020 Cynthia. All rights reserved.
//

#ifndef plane_hpp
#define plane_hpp

#include <stdio.h>

#include "vector3.hpp"
#pragma once



#endif






class plane {

public:

    // constructors

    plane();

    plane(float a1, float b1, float c1, float d1): a(a1), b(b1), c(c1), d(d1) {};



    // methods

    vector3 intersect(vector3 v1, vector3 v2);



    vector3 getP1();

    vector3 getP2();

    vector3 getP3();

    vector3 getP4();



    void setP1(vector3 v);

    void setP2(vector3 v);

    void setP3(vector3 v);

    void setP4(vector3 v);



    // data elements - formula

    float a;

    float b;

    float c;

    float d;



    // data elements - coordinates of corners

    float p1x, p1y, p1z,

          p2x, p2y, p2z,

          p3x, p3y, p3z,

          p4x, p4y, p4z;

};
