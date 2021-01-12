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
#include <stdio.h>
#include <stdlib.h>

GLint loc;
GLuint v, f, f2, p;
float a = 0;

void changeSize(int w, int h) {
    if (h == 0)
        h = 1;
    float ratio = 1.0* w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

void drawCar() {
    glPushMatrix();
    glPushMatrix();                   // основание
    glScalef(2,.5,1);
    glutSolidCube(.5);
    glPopMatrix();
    glTranslatef(0,0,.25);
    glPushMatrix();
    glTranslatef(-.4,-.2,0);
    glutSolidTorus(.05,.1,8,8);       // колесо
    glTranslatef(.8,0,0);
    glutSolidTorus(.05,.1,8,8);       // колесо
    glPopMatrix();
    glTranslatef(0,0,-.5);
    glPushMatrix();
    glTranslatef(-.4,-.2,0);
    glutSolidTorus(.05,.1,8,8);       // колесо
    glTranslatef(.8,0,0);
    glutSolidTorus(.05,.1,8,8);       // колесо
    glPopMatrix();
    glPopMatrix();

}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);
    glRotatef(a, 0, 1, 0);
    drawCar();
    a += 0.50;
    glutSwapBuffers();
}

int printOglError(char *file, int line) {
    GLenum glErr;
    int retCode = 0;
    glErr = glGetError();
    while (glErr != GL_NO_ERROR){
        retCode = 1;
        glErr = glGetError();
    }
    
    return retCode;
}

void setShaders() {
    char *vs = NULL,
    *fs = NULL;
    v = glCreateShader(GL_VERTEX_SHADER);
    f = glCreateShader(GL_FRAGMENT_SHADER);
    f2 = glCreateShader(GL_FRAGMENT_SHADER);
    free(vs);
    free(fs);
    glCompileShader(v);
    glCompileShader(f);
    glCompileShader(f2);
    p = glCreateProgram();
    glAttachShader(p, f);
    glAttachShader(p, f2);
    glAttachShader(p, v);
    glLinkProgram(p);
    glUseProgram(p);
    loc = glGetUniformLocation(p, "time");
}

int main(int argc, char **argv) {
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(200, 200);
    glutInit(&argc, argv);
    glutCreateWindow("лаба 7");
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.2, 0.2, 1.0);
    glEnable(GL_CULL_FACE);
    setShaders();
    glutMainLoop();
}
