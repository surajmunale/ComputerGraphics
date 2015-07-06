#ifndef SCENE_APPLE_H
#define SCENE_APPLE_H
#include <SceneGraph/scene_object.h>
#include <Model/plyModel.h>
#include <GL/glu.h>

class Scene_Apple:public Scene_Object
{
public:
    Scene_Apple();
    virtual void translate(int ,int,int);
    virtual void display();
    virtual void rotate();
    virtual void scale();
    virtual void oscillate(int);
    plyModel* p2;
    GLfloat light_position[4];
};

#endif // SCENE_APPLE_H
