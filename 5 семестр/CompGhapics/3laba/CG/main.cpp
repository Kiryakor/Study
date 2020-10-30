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
<<<<<<< HEAD
#include <math.h>
 
#define PI 3.141592653
=======
>>>>>>> 22f7e5728b8e9ba36ff498404b9e93a97aee71e4

int rot_x = 0;
int rot_y = 0;

<<<<<<< HEAD
=======

//MARK: - Сделать лабу мне надо как-то

>>>>>>> 22f7e5728b8e9ba36ff498404b9e93a97aee71e4
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glRotatef(rot_x, 50., .0, .0);
    glRotatef(rot_y, .0, 50., .0);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // см. выше
    
    glBegin(GL_TRIANGLES);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(.0, .5, .5, .5, -.5, .5);
    glutSolidSphere(0.3, 50, 40);
    float col[] = {1.0,0.0,0.0,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  col);
    glEnd();
    
    
    glBegin(GL_POLYGON);
    glColor3f(.3, .2, .0);
    glVertex3f(.5, -.5, -.5);
    glVertex3f(.5, .5, -.5);
    glVertex3f(-.5, .5, -.5);
    glVertex3f(-.5, -.5, -.5);
    float coll[] = {1.0,1.0,1.0,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR,  coll);
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

void Light() {
<<<<<<< HEAD
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_DEPTH_TEST);
//    GLfloat col[]={1.0, 0.0, 0.0, 1.0};
//    glLightfv(GL_LIGHT0, GL_SPECULAR, col);
//    GLfloat pos[]={1.0, 0.0, 1.0, 0.0};
//    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    // несколько источников света
    GLfloat light5_diffuse[] = {1.0, 0.0, 0.0};
    GLfloat light5_position[] = {0.5 , 0.5 , 1.0, 1.0};
    glEnable(GL_LIGHT5);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, light5_diffuse);
    glLightfv(GL_LIGHT5, GL_POSITION, light5_position);
    glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 0.0);
    glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.4);
    glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.8);
    GLfloat light6_diffuse[] = {0.0, 1.0, 0.0};
    GLfloat light6_position[] = {static_cast<GLfloat>(0.5 * cos(2 * PI / 3)), static_cast<GLfloat>(0.5 * sin(2 * PI / 3)), 1.0, 1.0};
    glEnable(GL_LIGHT6);
    glLightfv(GL_LIGHT6, GL_DIFFUSE, light6_diffuse);
    glLightfv(GL_LIGHT6, GL_POSITION, light6_position);
    glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, 0.0);
    glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 0.4);
    glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 0.8);
    GLfloat light7_diffuse[] = {0.0, 0.0, 1.0};
    GLfloat light7_position[] = {static_cast<GLfloat>(0.5 * cos(4 * PI / 3)), static_cast<GLfloat>(0.5 * sin(4 * PI / 3)), 1.0, 1.0};
    glEnable(GL_LIGHT7);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, light7_diffuse);
    glLightfv(GL_LIGHT7, GL_POSITION, light7_position);
    glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, 0.0);
    glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.4);
    glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.8);
=======
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    GLfloat col[]={1.0, 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_SPECULAR, col);
    GLfloat pos[]={1.0, 0.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
>>>>>>> 22f7e5728b8e9ba36ff498404b9e93a97aee71e4
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
<<<<<<< HEAD
    
    
=======
>>>>>>> 22f7e5728b8e9ba36ff498404b9e93a97aee71e4
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Куб");
    glEnable(GL_DEPTH_TEST);
    Light();
    glutDisplayFunc(display);
    glutSpecialFunc(controlls);
    glutMainLoop();
    return 0;
}
