//
//  prefix.h
//  OpenGL Lab1
//
//  Created by Alexey Bondarenko on 9/20/15.
//  Copyright (c) 2015 Alexey Bondarenko. All rights reserved.
//

#ifndef OpenGL_Lab1_prefix_h
#define OpenGL_Lab1_prefix_h

#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif


#endif
