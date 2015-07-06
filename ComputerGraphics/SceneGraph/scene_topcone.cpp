#include "scene_topcone.h"
#include <GL/glut.h>
#include <math.h>

Scene_TopCone::Scene_TopCone()
{
}
void Scene_TopCone:: translate(int x,int y,int z)
{
  glTranslatef(x,y,z);
}
void Scene_TopCone::rotate()
{
   glRotatef(15.0,1.0,1.0,1.0); //rotate 15 degress around x and y-axis
}

void Scene_TopCone::display()
{
    GLfloat x,y,angle;
int iPivot = 1; float r2=3.8;
    glBegin(GL_TRIANGLE_FAN);
        // Pinnacle of cone is shared vertex for fan, moved up z-axis
        // to produce a cone instead of a circle
        glVertex3f(0.0f, 0.0f, 2.4f);
        // Loop around in a circle and specify even points
        //along the circle  as the vertices of the triangle fan
        for(angle = 0.0f; angle < (4.0f*M_PI); angle += (M_PI/8.0f))
            {
                // Calculate x and y position of the next vertex
                x = r2*sin(angle);
                y = r2*cos(angle);
                if((iPivot % 2) == 0)
                           glColor3f(0.0, 1.0, 0.0);
                else
                           glColor3f(1.0, 0.0, 0.0);

                iPivot++;

                glVertex2f(x,y);
             }
     glEnd();



}

void Scene_TopCone::scale()
{

}

void Scene_TopCone::oscillate(int flag)
{
}
