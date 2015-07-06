#include "camera.h"
#include "GL/glut.h"
#include <math.h>

Camera::Camera()
{
}

void Camera:: setViewPort(int height, int width)
{
    Camera::height=height;
    Camera::width=width;
}

void Camera:: setEye(vec eye)
{
    Camera::eye=eye;
}

void Camera ::loadPerspective(int mode)
{
    if(mode==0)
    {
        //load the Perspective which is setted by external parameters.
        //if Mode==0 then Perspective is not predefined whatever user had set just load the same.

        static float x = 0.75, y = 0.85, z = 0.8;
        static float lx = -1, ly = -1, lz = -1;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(20, width / height, .85, 1000);
        gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0, 1, 0);
        arcball_setzoom(20.0f,eye,up);
    }

    switch(mode)
    {
        //Bunny
        case 1:
        static float x = 0.75, y = 0.85, z = 0.8;
        static float lx = -1, ly = -1, lz = -1;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(20, width / height, .85, 1000);
        gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0, 1, 0);
        arcball_setzoom(20.0f,eye,up);
        break;

        //Tea Pot
        case 2:
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluLookAt(0,0,5,0,0,0,0,1,0);
        gluPerspective(45,(float)width/height,0.01,100);
        arcball_setzoom(5.0f,eye,up);
        break;

        //Car
        case 3:
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(20, width / height, .85, 1000);
        gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0, 1, 0);
        arcball_setzoom(20.0f,eye,up);
        break;

        //Plane
        case 4:
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(20, width / height, .85, 1000);
        gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0, 1, 0);
        arcball_setzoom(20.0f,eye,up);
        break;
    }
}
