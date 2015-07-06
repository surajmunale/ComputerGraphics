#ifndef SCENE_GUN_H
#define SCENE_GUN_H
#include <Model/plyModel.h>
#include <GL/glu.h>
class Scene_Gun
{
public:
    Scene_Gun();
    plyModel* p2;
    GLfloat light_position[4];
    void display();
};

#endif // SCENE_GUN_H
