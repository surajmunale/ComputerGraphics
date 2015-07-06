#include "sphere.h"
#include <GL/glut.h>
#include <math.h>

sphere::sphere()
{
}
//Translate the sphere using x,y,x co-ordinates.
void sphere:: translate(int x,int y,int z)
{

    glTranslatef(x,y,z);

}

//Roate the Sphere
void sphere::rotate()
{
    glRotatef(15.0,1.0,1.0,1.0); //rotate 15 degress around x and y-axis
}

//Show the sphere
void sphere:: display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLineWidth(0.2);
    glLineStipple(1, 0x3F07);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    //x axis
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1000.0, 0.0, 0.0);

    //y axis
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1000.0, 0.0);
    //Z axis

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1000.0);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    showSphere();
    // glutSolidSphere(1.0, 10, 10);
    return;
}

///This function is to show the sphere.
void sphere::showSphere()
{
          glEnable(GL_DEPTH_TEST);
          //Enable the lighting
          glEnable(GL_LIGHTING);
          glEnable(GL_LIGHT0);

       int i, j;
       for(i = 0; i <= 10; i++)
       {
           double lat0 = M_PI * (-0.5 + (double) (i - 1) / 10);
           double z0  = sin(lat0);
           double zr0 =  cos(lat0);

           double lat1 = M_PI * (-0.5 + (double) i / 10);
           double z1 = sin(lat1);
           double zr1 = cos(lat1);

           glBegin(GL_QUAD_STRIP);
           for(j = 0; j <= 10; j++)
           {
               double lng = 2 * M_PI * (double) (j - 1) / 10;
               double x = cos(lng);
               double y = sin(lng);

               glNormal3f(x * zr0, y * zr0, z0);
               glVertex3f(x * zr0, y * zr0, z0);
               glNormal3f(x * zr1, y * zr1, z1);
               glVertex3f(x * zr1, y * zr1, z1);
            }
            glEnd();
       }

       glDisable(GL_LIGHTING);
       glDisable(GL_LIGHT0);
       glDisable(GL_COLOR_MATERIAL);

   }
