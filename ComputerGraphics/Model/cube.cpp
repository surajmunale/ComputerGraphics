#include "cube.h"
#include <GL/glut.h>

Cube::Cube()
{
};

    //Translate the Cube using x,y,x co-ordinates.
    void Cube:: translate(int x,int y,int z)
    {
       glTranslatef(x,y,z);
    }

    //Roate the Cube
    void Cube::rotate()
    {
        glRotatef(15.0,1.0,1.0,1.0); //rotate 15 degress around x and y-axis
    }

    //Show the cube
    void Cube:: display()
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glLineWidth(0.2);
        //Dotted line
        glLineStipple(1, 0x3F07);
        glEnable(GL_LINE_STIPPLE);

        glBegin(GL_LINES);

        //x Axis
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(100.0, 0.0, 0.0);

        // y axis
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 100.0, 0.0);

        //z axis
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 100.0);

        glEnd();

        glDisable(GL_LINE_STIPPLE);

      /* create 3D-Cube */
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
          return;
    }
