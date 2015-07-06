#include "light.h"
#include <GL/glut.h>
#include <time.h>
Light::Light()
{

}

void Light::initilizeLight(int mode)
{
    switch(mode)
    {

        //Bunny
        case 1:

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
        break;
    }
}
void Light::MoveRandomLight()
{
    srand( (unsigned)time( NULL ) );

    float iSecret=(float) rand()/RAND_MAX;
    light_position[0]=iSecret ;

    iSecret=(float) rand()/RAND_MAX;
    light_position[1]=iSecret ;

    iSecret=(float) rand()/RAND_MAX;
    light_position[2]=iSecret ;

     iSecret=(float) rand()/RAND_MAX;
    light_position[3]=iSecret ;

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

}
GLfloat* Light::getLightPosition()
{
    return light_position;
}
