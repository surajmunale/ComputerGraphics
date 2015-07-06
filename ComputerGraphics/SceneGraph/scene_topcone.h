#ifndef SCENE_TOPCONE_H
#define SCENE_TOPCONE_H
#include <SceneGraph/scene_object.h>

class Scene_TopCone:public Scene_Object
{
public:
    Scene_TopCone();
    virtual void translate(int ,int,int);
    virtual void display();
    virtual void rotate();
    virtual void scale();
    virtual void oscillate(int);

};

#endif // SCENE_TOPCONE_H
