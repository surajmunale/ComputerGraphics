#ifndef SCENE_CUBE_H
#define SCENE_CUBE_H
#include <SceneGraph/scene_object.h>

class Scene_Cube:public Scene_Object
{
public:
    Scene_Cube();
    virtual void translate(int ,int,int);
    virtual void display();
    virtual void rotate();
    virtual void scale();
    virtual void oscillate(int);

};
#endif // SCENE_CUBE_H
