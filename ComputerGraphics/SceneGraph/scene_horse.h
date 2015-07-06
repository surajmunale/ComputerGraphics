#ifndef SCENE_HORSE_H
#define SCENE_HORSE_H
#include <SceneGraph/scene_cube.h>
#include <Model/plyModel.h>
#include <GL/glu.h>
class Scene_horse : public Scene_Object
{
    //Scene_Cube
public:
     Scene_horse();
     virtual void translate(int ,int,int);
     virtual void display();
     virtual void rotate();
     virtual void scale();
     virtual void oscillate(int);
     plyModel* p2;
     GLfloat light_position[4];

};

#endif // SCENE_HORSE_H
