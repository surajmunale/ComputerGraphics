#ifndef SCENE_CYLINDER_H
#define SCENE_CYLINDER_H
#include <SceneGraph/scene_object.h>

class Scene_Cylinder:public Scene_Object
{
public:
    Scene_Cylinder(float a,float b,float c,float d,float red,float green,float blue);
    virtual void translate(int ,int,int);
    virtual void display();
    virtual void rotate();
    virtual void scale();
    virtual void oscillate(int);
    float a,b,c,d,red,green,blue;

};

#endif // SCENE_CYLINDER_H
