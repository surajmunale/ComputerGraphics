#ifndef SCENE_COW_H
#define SCENE_COW_H
#include <SceneGraph/scene_object.h>
#include <Model/plyModel.h>
#include <GL/glu.h>

class Scene_cow:public Scene_Object
{
public:
    Scene_cow();
    virtual void translate(int ,int,int);
    virtual void display();
    virtual void rotate();
    virtual void scale();
    virtual void oscillate(int);
    plyModel* p2;
    GLfloat light_position[4];
};

#endif // SCENE_COW_H
