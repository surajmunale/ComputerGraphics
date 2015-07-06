#include "scene_cylinder.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include "GL/gl.h"
#include "GL/freeglut.h"

Scene_Cylinder::Scene_Cylinder(float a,float b,float c,float d,float red,float green,float blue)
{
    this->a=a;
    this->b=b;
    this->c=c;
    this->d=d;
    this->red=red;
    this->green=green;
    this->blue=blue;
}

void Scene_Cylinder:: translate(int x,int y,int z)
{
  glTranslatef(x,y,z);
}

void Scene_Cylinder::rotate()
{
   glRotatef(15.0,1.0,1.0,1.0); //rotate 15 degress around x and y-axis
}

void Scene_Cylinder::display()
{
   glColor3d(red,green,blue);
   glutSolidCylinder(a,b,c,d);
}

void Scene_Cylinder::scale()
{

}
void Scene_Cylinder::oscillate(int flag)
{
}
