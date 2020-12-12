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

#define GL_PI 3.1415f

GLfloat al = 0.5f;
GLfloat xRot = 0.45f;
GLfloat yRot = 0.35f;
GLboolean bOutline = (GLboolean)true;
GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
float mat1_dif[] = { 1.0f, 0.3f, 0.8f };
float mat1_amb[] = { 0.3f, 0.9f, 0.2f };
float mat1_spec[] = { 1.0f, 0.5f, 0.8f };
float mat1_shininess = 0.7f * 128;
GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 0.2 };
GLfloat light_diffuse[] = { 0.3, 0.4, 0.9, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLenum shademode = GL_FLAT;
GLfloat colv[4];
GLfloat ex = 100.0f;
GLfloat ey = 259.0f;
GLfloat ez = 100.0f;
GLfloat delta = 0.1f;
GLfloat deltaR = 0.01f;
GLfloat lightPos[] = { 100.0f, 80.0f, 85.0f, 1.0f };
GLfloat floor_1[] = { 0.0f, 1.0f, 0.0f, 0.0f };
GLfloat shadowMat[16];
GLfloat x1 = 100.0;
GLfloat y_1 = 25.0;
GLfloat z1 = 130.0;
GLfloat x2 = 10.0;
GLfloat y2 = 10.0;
GLfloat z2 = 120.0;
GLfloat x3 = 110.0;
GLfloat y3 = 10.0;
GLfloat z3 = 115.0;
GLfloat cx = (x1 + x2 + x3) / 3;
GLfloat cy = (y_1 + y2 + y3) / 3;
GLfloat cz = (z1 + z2 + z3) / 3;
GLfloat vercube[8][3] = { { 80, 10, 0 },{ 100, 10, 0 },{ 100, 10, 20 },{ 80, 10, 20 },{ 80, 30, 0 },{ 100, 30, 0 },{ 100, 30, 20 },{ 80, 30, 20 } };
GLfloat centr_cube[3];
GLfloat vertringle[3][3] = { { 100, 25, 130 },{ 120, 10, 120 },{ 110, 10, 115 } };

void gltMakeShadowMatrix(GLfloat vPlaneEquation[], GLfloat vLightPos[], GLfloat destMat[]) {
    GLfloat dot;
    dot = vPlaneEquation[0] * vLightPos[0] + vPlaneEquation[1] * vLightPos[1] +
    vPlaneEquation[2] * vLightPos[2] + vPlaneEquation[3] * vLightPos[3];
    destMat[0] = dot - vLightPos[0] * vPlaneEquation[0];
    destMat[4] = 0.0f - vLightPos[0] * vPlaneEquation[1];
    destMat[8] = 0.0f - vLightPos[0] * vPlaneEquation[2];
    destMat[12] = 0.0f - vLightPos[0] * vPlaneEquation[3];
    destMat[1] = 0.0f - vLightPos[1] * vPlaneEquation[0];
    destMat[5] = dot - vLightPos[1] * vPlaneEquation[1];
    destMat[9] = 0.0f - vLightPos[1] * vPlaneEquation[2];
    destMat[13] = 0.0f - vLightPos[1] * vPlaneEquation[3];
    destMat[2] = 0.0f - vLightPos[2] * vPlaneEquation[0];
    destMat[6] = 0.0f - vLightPos[2] * vPlaneEquation[1];
    destMat[10] = dot - vLightPos[2] * vPlaneEquation[2];
    destMat[14] = 0.0f - vLightPos[2] * vPlaneEquation[3];
    destMat[3] = 0.0f - vLightPos[3] * vPlaneEquation[0];
    destMat[7] = 0.0f - vLightPos[3] * vPlaneEquation[1];
    destMat[11] = 0.0f - vLightPos[3] * vPlaneEquation[2];
    destMat[15] = dot - vLightPos[3] * vPlaneEquation[3];
}

void DrawLight(){
    glPushMatrix();
    glTranslatef(lightPos[0], lightPos[1], lightPos[2]);
    glColor3ub(255, 255, 0);
    glutSolidSphere(5.0f, 10, 10);
    glPopMatrix();
}

void treugol_i_cube_bez_c(){
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y_1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glEnd();
    glPushMatrix();
    glTranslatef(80, 0, 150);
    glBegin(GL_QUADS);
    glVertex3fv(&vercube[0][0]);
    glVertex3fv(&vercube[1][0]);
    glVertex3fv(&vercube[2][0]);
    glVertex3fv(&vercube[3][0]);
    glVertex3fv(&vercube[4][0]);
    glVertex3fv(&vercube[5][0]);
    glVertex3fv(&vercube[6][0]);
    glVertex3fv(&vercube[7][0]);
    glVertex3fv(&vercube[4][0]);
    glVertex3fv(&vercube[7][0]);
    glVertex3fv(&vercube[3][0]);
    glVertex3fv(&vercube[0][0]);
    glVertex3fv(&vercube[2][0]);
    glVertex3fv(&vercube[6][0]);
    glVertex3fv(&vercube[5][0]);
    glVertex3fv(&vercube[1][0]);
    glEnd();
    glPopMatrix();
}

void treugol_i_cube(){
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y_1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glEnd();
    glPushMatrix();
    glTranslatef(200.f, centr_cube[1], 160.f);
    glutSolidTeapot(20);
    glPopMatrix();
}

void shadow_obj(){
    glPushMatrix();
    glMultMatrixf(shadowMat);
    treugol_i_cube();
    glPopMatrix();
}

void SetupRC(){
    int i;
    centr_cube[0] = 0.f;
    centr_cube[1] = 0.f;
    centr_cube[2] = 0.f;
    for (i = 0; i < 8; i++){
        centr_cube[0] += vercube[i][0];
        centr_cube[1] += vercube[i][1];
        centr_cube[2] += vercube[i][2];
    }
    centr_cube[0] /= 8.f;
    centr_cube[1] /= 8.f;
    centr_cube[2] /= 8.f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat1_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat1_dif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat1_spec);
    glMaterialf(GL_FRONT, GL_SHININESS, mat1_shininess);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 128);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(shademode);
    glFrontFace(GL_CCW);
    gltMakeShadowMatrix(floor_1, lightPos, shadowMat);
}

void Drawfloor(){
    colv[0] = 0.9f;
    colv[1] = 0.7f;
    colv[2] = 0.7f;
    colv[3] = 0.75f;
    glColor4fv(colv);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(250.0f, 0.0f, 0.0f);
    glVertex3f(250.0f, 0.0f, 250.0f);
    glVertex3f(0.0f, 0.0f, 250.0f);
    glEnd();
    glLineWidth(2.f);
    glBegin(GL_LINES);
    for (int i = 0; i < 250; i += 5){
        glColor3d(0, 0, 0);
        glVertex3d(i, 0, 0);
        glVertex3d(i, 0, 250);
    }
    glEnd();
}

void RenderScene(void){
    glLoadIdentity();
    gluLookAt(ex, ey, ez, cx, cy, cz, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glFrontFace(GL_CW);
    glPushMatrix();
    glScalef(1.0f, -1.0f, 1.0f);
    glTranslatef(0.0f, -2.0f * 1, 0.0f);
    glColor3f(0.4f, 0.05f, 0.1f);
    treugol_i_cube();
    DrawLight();
    glPopMatrix();
    glFrontFace(GL_CCW);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    Drawfloor();
    glEnable(GL_DEPTH_TEST);
    glColor4f(0.1f, 0.1f, 0.1f, al);
    shadow_obj();
    glDisable(GL_BLEND);
    glColor3f(0.4f, 0.05f, 0.1f);
    treugol_i_cube();
    glDisable(GL_DEPTH_TEST);
    DrawLight();
    glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.5, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

void SpecialKeys(int key, int x, int y){
    GLfloat dx, dz;
    if (key == GLUT_KEY_UP){
        GLfloat vx = ex - cx;
        GLfloat vy = ey - cy;
        GLfloat vz = ez - cz;
        vx *= (1.0f + deltaR);
        vy *= (1.0f + deltaR);
        vy *= (1.0f + deltaR);
        ex = vx + cx;
        ey = vy + cy;
        ez = vz + cz;
        glutPostRedisplay();
    }
    if (key == GLUT_KEY_DOWN){
        GLfloat vx = ex - cx;
        GLfloat vy = ey - cy;
        GLfloat vz = ez - cz;
        vx *= (1.0f - deltaR);
        vy *= (1.0f - deltaR);
        vy *= (1.0f - deltaR);
        ex = vx + cx;
        ey = vy + cy;
        ez = vz + cz;
        glutPostRedisplay();
    }
    if (key == GLUT_KEY_LEFT){
        dx = -ez; dz = ex;
        GLfloat s = sqrtf(ex*ex + ey*ey + ez*ez);
        ex += delta*dx; ez += delta*dz;
        GLfloat s1 = sqrtf(ex*ex + ey*ey + ez*ez) / s;
        ex /= s1; ey /= s1; ey /= s1;
        glutPostRedisplay();
    }
    if (key == GLUT_KEY_RIGHT){
        dx = -ez; dz = ex;
        GLfloat s = sqrtf(ex*ex + ey*ey + ez*ez);
        ex -= delta*dx; ez -= delta*dz;
        GLfloat s1 = sqrtf(ex*ex + ey*ey + ez*ez) / s;
        ex /= s1; ey /= s1; ey /= s1;
        glutPostRedisplay();
    }
    if (key == GLUT_KEY_HOME){
        GLfloat LX = lightPos[0] - cx;
        GLfloat LZ = lightPos[2] - cz;
        GLfloat radVn[] = { LZ, -LX };
        GLfloat dl = sqrt(LZ*LZ + LX*LX);
        GLfloat nlightPosX = lightPos[0] + delta*LZ;
        GLfloat nlightPosZ = lightPos[2] - delta*LX;
        GLfloat LX_1 = nlightPosX - cx;
        GLfloat LZ_1 = nlightPosZ - cz;
        GLfloat dl_1 = sqrt(LZ_1*LZ_1 + LX_1*LX_1);
        LX_1 *= dl / dl_1;
        LZ_1 *= dl / dl_1;
        lightPos[0] = cx + LX_1;
        lightPos[2] = cz + LZ_1;
        gltMakeShadowMatrix(floor_1, lightPos, shadowMat);
        glutPostRedisplay();
    }
    if (key == GLUT_KEY_F9){
        glPushMatrix();
        glRotatef(2.f, 0.f, 0.f, 1.f);
        Drawfloor();
        treugol_i_cube();
        glPopMatrix();
        gltMakeShadowMatrix(floor_1, lightPos, shadowMat);
        glutPostRedisplay();
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(768, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    SetupRC();
    glutMainLoop();
    return 0;
}
