//
//  main.cpp
//  CG
//
//  Created by Кирилл on 10.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <GLUT/glut.h>

int rot_x = 0;
int rot_y = 0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    
    float ambient[4] = {0.5, 0.5, 0.5, 1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
    
    glRotatef(rot_x, 10., .0, .0);
    glRotatef(rot_y, .0, 10., .0);
    
    glBegin(GL_POLYGON);
    glColor3f(.3, .2, .0);
    glVertex3f(.5, -.5, -.5);
    glVertex3f(.5, .5, -.5);
    glVertex3f(-.5, .5, -.5);
    glVertex3f(-.5, -.5, -.5);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(.0, .0, 1.);
    glVertex3f(.5, -.5, .5);
    glVertex3f(.5, .5, .5);
    glVertex3f(-.5, .5, .5);
    glVertex3f(-.5, -.5, .5);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(.4, .5, .3);
    glVertex3f(.5, -.5, -.5);
    glVertex3f(.5, .5, -.5);
    glVertex3f(.5, .5, .5);
    glVertex3f(.5, -.5, .5);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(.0, 1., .0);
    glVertex3f(-.5, -.5, .5);
    glVertex3f(-.5, .5, .5);
    glVertex3f(-.5, .5, -.5);
    glVertex3f(-.5, -.5, -.5);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.0, 1.0);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
    
    glFlush();
    glutSwapBuffers();
}

void controlls(int k, int x, int y) {
    switch (k) {
        case GLUT_KEY_UP:
            rot_x--;
            break;
        case GLUT_KEY_DOWN:
            rot_x++;
            break;
        case GLUT_KEY_LEFT:
            rot_y--;
            break;
        case GLUT_KEY_RIGHT:
            rot_y++;
            break;
        case GLUT_KEY_F1:
            exit(0);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Куб");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutSpecialFunc(controlls);
    glutMainLoop();
    return 0;
}
