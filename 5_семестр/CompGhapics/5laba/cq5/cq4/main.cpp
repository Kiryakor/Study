//
//  main.cpp
//  cq4
//
//  Created by Кирилл on 13.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <GLUT/glut.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

GLfloat ctrlpoints[4][4][3];
GLUnurbsObj *theNurb;
GLuint theTeapot;

#define stripeImageWidth 64

GLubyte stripeImage[4 * stripeImageWidth];
GLuint texName;
GLfloat xequalzero[] = { 1.0, 0.0, 1.0, 0.0 };
GLfloat slanted[] = { 1.0, 0.0, 5.0, 0.0 };
GLfloat *currentCoeff;
GLenum currentPlane;
GLint currentGenMode;
GLint fog;

void init_nurb() {
    int u, v;
    for (u = 0; u<4; u++) {
        for (v = 0; v<4; v++) {
            ctrlpoints[u][v][0] = 3.0*((GLfloat)u - 1.5);
            ctrlpoints[u][v][1] = 2.0*((GLfloat)v - 1.5);
            if ((u == 1 || u == 2) && (v == 1 || v == 2))
                ctrlpoints[u][v][2] = 3.0;
            else
                ctrlpoints[u][v][2] = -3.0;
        }
    }
    GLfloat mat_diffuse[] = { 1.0, 0.7, 0.3, 1.0 };
    GLfloat mat_specular[] = { 1.0, 0.5, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 100.0 };
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    theNurb = gluNewNurbsRenderer();
    gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 5.0);
    gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);
    glutPostRedisplay();
}

void makeStripeImage(){
    int j;
    for (j = 0; j < stripeImageWidth; j++){
        stripeImage[4 * j] = (GLubyte)((j <= 4) ? 255 : 0);
        stripeImage[4 * j + 1] = (GLubyte)((j>4) ? 255 : 0);
        stripeImage[4 * j + 2] = (GLubyte)0;
        stripeImage[4 * j + 3] = (GLubyte)255;
    }
}

void display(){
    GLfloat knots[8] = { 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(330.0, 20.0, 0.0, 0.0);
    glScalef(2.0, 0.5, 1.0);
    gluBeginSurface(theNurb);
    gluNurbsSurface(theNurb, 8, knots, 8, knots, 4 * 3, 3,&ctrlpoints[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(theNurb);
    glPopMatrix();
    glFlush();
    glPushMatrix();
    glTranslatef(-2.0, 1.1, 0.0);
    glCallList(theTeapot);
    glPopMatrix();
    glFlush();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    makeStripeImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 5);
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_1D, texName);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0,
    GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    currentCoeff = xequalzero;
    currentGenMode = GL_OBJECT_LINEAR;
    currentPlane = GL_OBJECT_PLANE;
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
    glTexGenfv(GL_S, currentPlane, currentCoeff);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_1D);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    GLfloat position[] = { 500.0, 1030.0, 950.0, 0.0 };
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    {
        GLfloat mat1[3] = { 1.0, 1.0, 1.0 };
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat1);
        mat1[0] = 1.0; mat1[1] = 0.0; mat1[2] = 0.0;
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat1);
        mat1[0] = 1.0; mat1[1] = 1.0; mat1[2] = 1.0;
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat1);
        glMaterialf(GL_FRONT, GL_SHININESS, 5.0);
    }
    glEnable(GL_FOG);
    {
        GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };
        fog = GL_EXP;
        glFogi(GL_FOG_MODE, fog);
        glFogfv(GL_FOG_COLOR, fogColor);
        glFogf(GL_FOG_DENSITY, 0.35);
        glHint(GL_FOG_HINT, GL_NICEST);
        glFogf(GL_FOG_START, 1.0);
        glFogf(GL_FOG_END, 5.0);
    }
    theTeapot = glGenLists(1);
    glNewList(theTeapot, GL_COMPILE);
    glTranslatef(0.0, 0.0, 0.0);
    glutSolidTeapot(0.8);
    glTranslatef(2.2, 0.0, 0.0);
    glutSolidTeapot(0.6);
    glTranslatef(1.5, 0.0, 0.0);
    glutSolidTeapot(0.4);
    glEndList();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 3.0, 8.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'x':
        case 'X':
            currentGenMode = GL_EYE_LINEAR;
            currentPlane = GL_EYE_PLANE;
            glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
            glTexGenfv(GL_S, currentPlane, currentCoeff);
            glutPostRedisplay();
            break;
        case 'w':
        case 'W':
            currentGenMode = GL_OBJECT_LINEAR;
            currentPlane = GL_OBJECT_PLANE;
            glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
            glTexGenfv(GL_S, currentPlane, currentCoeff);
            glutPostRedisplay();
            break;
        case 's':
        case 'S':
            currentCoeff = slanted;
            glTexGenfv(GL_S, currentPlane, currentCoeff);
            glutPostRedisplay();
            break;
        case 'a':
        case 'A':
            currentCoeff = xequalzero;
            glTexGenfv(GL_S, currentPlane, currentCoeff);
            glutPostRedisplay();
            break;
        case 'd':
        case 'D':
            if (fog == GL_EXP){
                fog = GL_EXP2;
            } else if (fog == GL_EXP2){
                fog = GL_LINEAR;
            } else if (fog == GL_LINEAR) {
                fog = GL_EXP;
            }
            glFogi(GL_FOG_MODE, fog);
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Компьютерная графика №5");
    init_nurb();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
