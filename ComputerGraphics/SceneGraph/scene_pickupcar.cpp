#include "scene_pickupcar.h"

Scene_PickupCar::Scene_PickupCar()
{
p2=new plyModel("pinkupcar.ply",6870,13402,0);
}

void Scene_PickupCar:: translate(int x,int y,int z)
{
   glTranslatef(x,y,z);
}

void Scene_PickupCar::rotate()
{
    glRotatef(15.0,1.0,1.0,1.0); //rotate 15 degress around x and y-axis
}

void Scene_PickupCar::display()
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

    glScalef(0.5,0.5,0.5);
    glColor3f(0.2,0.2,0.2);
    p2->display_draw();
}

void Scene_PickupCar::scale()
{

}



void Scene_PickupCar::oscillate(int flag)
{
}
