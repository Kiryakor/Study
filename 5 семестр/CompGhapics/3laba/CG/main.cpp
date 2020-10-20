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


//MARK: - Сделать лабу мне надо как-то

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
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    GLfloat col[]={1.0, 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_SPECULAR, col);
    GLfloat pos[]={1.0, 0.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
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
