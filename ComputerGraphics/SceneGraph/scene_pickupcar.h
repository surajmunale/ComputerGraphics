#ifndef SCENE_PICKUPCAR_H
#define SCENE_PICKUPCAR_H
#include <SceneGraph/scene_object.h>
#include <Model/plyModel.h>
#include <GL/glu.h>

class Scene_PickupCar:public Scene_Object
{
public:
    Scene_PickupCar();
    virtual void translate(int ,int,int);
    virtual void display();
    virtual void rotate();
    virtual void scale();
    virtual void oscillate(int);
    plyModel* p2;
    GLfloat light_position[4];
};

#endif // SCENE_PICKUPCAR_H
