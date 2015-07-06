#include "scene_cube.h"
#include <GL/glut.h>

Scene_Cube::Scene_Cube()
{
}
 void Scene_Cube:: translate(int x,int y,int z)
{
   glTranslatef(x,y,z);
}
 void Scene_Cube::rotate()
{
    glRotatef(15.0,1.0,1.0,1.0); //rotate 15 degress around x and y-axis
}

 void Scene_Cube::display()
{
     glScalef(0.6,0.6,0.6);
    glBegin(GL_QUADS);

        //right
        glColor3f(1.0,0.0,1.0);

        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);

        //bottom

        glColor3f(0.0,1.0,1.0);

        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,1.0);


        //front
        glColor3f(0.0,0.0,1.0);

        glVertex3f(1.0,1.0,1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);

        //top
        glColor3f(0.0,1.0,0.0);

        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);

        //back

        glColor3f(1.0,1.0,0.0);

        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(1.0,-1.0,-1.0);


        //left
        glColor3f(1.0,0.0,0.0);

        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(1.0,1.0,-1.0);
        glEnd();

}

void Scene_Cube::scale()
{

}

void Scene_Cube::oscillate(int flag)
{
}
