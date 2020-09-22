//
//  Header.h
//  Assignment2Program2
//
//  Created by Cynthia on 14/6/2020.
//  Copyright © 2020 Cynthia. All rights reserved.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */


using namespace std;
GLuint myList;


// vertex array
typedef GLint vertexCube [3];
vertexCube cube [8] = { {0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, {0,1,1}, {0,0,1},   {1,0,1}, {1,1,1} };

typedef GLfloat vertexPyramid[3];
vertexPyramid pyramid [5] = { {0.5, 1.5, 0.5}, {-0.2, 1.0, -0.2}, {1.2,1,-0.2}, {1.2, 1.0, 1.2}, {-0.2,1,1.2} };
