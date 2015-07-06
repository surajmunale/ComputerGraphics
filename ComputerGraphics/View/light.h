#ifndef LIGHT_H
#define LIGHT_H
#include <math.h>
#include <GL/glut.h>
class Light
{

public:
        Light();

        GLfloat * getLightPosition();
        GLfloat light_position[];

        void initilizeLight(int mode=0);
        void MoveRandomLight();

};

#endif // LIGHT_H
