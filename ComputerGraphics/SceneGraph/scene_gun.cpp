#include "scene_gun.h"
#include <GL/glut.h>
#include <GL/glu.h>
Scene_Gun::Scene_Gun()
{
 p2=new plyModel("gun.ply",4171,8210,0);
}

void Scene_Gun::display()
{
    glEnable(GL_DEPTH_TEST);

/*
    light_position[0]=1.0;
    light_position[1]=1.0;
    light_position[2]=1.0;
    light_position[3]=0.0;

    GLfloat ambient0[]={0.2, 0.2, 0.2, 1.0}; // Farbdefinitionen
    GLfloat diffuse0[]={0.2, 0.2, 0.2, 1.0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse0);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
*/
    glColor3f(1,1,1);
    glPushMatrix();
    glScalef(1.0,1.0,1.0);
    glRotatef(-90,0,1,0);
    glTranslatef(0,-1,0);
    p2->display_draw();
    glTranslatef(-10,0,0);
    glScalef(0.2,0.2,0.2);
    glutWireSphere(1,16,16);
    glPopMatrix();
}
