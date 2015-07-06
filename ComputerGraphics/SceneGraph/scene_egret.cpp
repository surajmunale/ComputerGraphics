#include "scene_egret.h"

Scene_Egret::Scene_Egret()
{
    p2=new plyModel("egret.ply",976,1527,0);
}

void Scene_Egret:: translate(int x,int y,int z)
{
   glTranslatef(x,y,z);
}

void Scene_Egret::rotate()
{
    glRotatef(15.0,1.0,1.0,1.0); //rotate 15 degress around x and y-axis
}

void Scene_Egret::display()
{
    glEnable(GL_DEPTH_TEST);

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

    glScalef(0.001,0.001,0.001);
    glColor3f(1,1,1);
    p2->display_draw();
}

void Scene_Egret::scale()
{

}


void Scene_Egret::oscillate(int flag)
{
}
