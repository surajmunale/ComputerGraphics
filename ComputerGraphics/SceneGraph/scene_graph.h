#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include <SceneGraph/scene_cube.h>
#include <SceneGraph/scene_horse.h>
#include <SceneGraph/scene_object.h>
#include <SceneGraph/scene_base.h>
#include <SceneGraph/scene_cylinder.h>
#include <SceneGraph/scene_topcone.h>
#include <SceneGraph/scene_cow.h>
#include <SceneGraph/scene_egret.h>
#include <SceneGraph/scene_pickupcar.h>
#include <SceneGraph/scene_apple.h>

class Scene_Graph
{

public:

    Scene_Graph();

    Scene_Object *b=new Scene_Base(4.0);
    Scene_Object *b1=new Scene_Base(4.0);
    Scene_Object *b2=new Scene_Base(4.0);
    Scene_Object *b3=new Scene_Base(4.0);
    Scene_Object *b4=new Scene_Base(4.0);
    Scene_Object *surface=new Scene_Base(100.0);

    void clearDisplay(Scene_Object *node);

    void construct();

    void display(Scene_Object *);

    void rotate();
    void translate();

};

#endif // SCENE_GRAPH_H
