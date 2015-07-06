#ifndef SCENE_BASE_H
#define SCENE_BASE_H
#include <SceneGraph/scene_object.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

#include <SceneGraph/scene_cube.h>
#include <SceneGraph/scene_horse.h>
#include <SceneGraph/scene_object.h>
#include <SceneGraph/scene_cylinder.h>
#include <SceneGraph/scene_topcone.h>
#include <SceneGraph/scene_cow.h>
#include <SceneGraph/scene_egret.h>
#include <SceneGraph/scene_pickupcar.h>
#include <SceneGraph/scene_apple.h>

class Scene_Base:public Scene_Object
{
public:
    Scene_Base(float redius);
    virtual void translate(int ,int,int);
    virtual void display();
    virtual void rotate();
    virtual void scale();
    virtual void oscillate(int);

    float redius;
    GLuint loadBMP_custom(const char * imagepath);
    GLuint Texture ;
    //Base Elements
    //Main pole
    Scene_Object *c1=new Scene_Cylinder(0.5,6,16,16,1,0,0);

    //pole1->egret
    Scene_Object *c2=new Scene_Cylinder(0.1,3,16,16,0,1,0);

    //pole2->cow
    Scene_Object *c3=new Scene_Cylinder(0.1,2,16,16,0,0,1);

    //pole3->car
    Scene_Object *c4=new Scene_Cylinder(0.1,3,16,16,0,1,1);

    //pole4->car
    Scene_Object *c5=new Scene_Cylinder(0.1,3,16,16,1,1,0);

    //pole 5->cube
    Scene_Object *c6=new Scene_Cylinder(0.1,3,16,16,0.5,1,0.5);

    //top cone
    Scene_Object *topcone=new Scene_TopCone();

    //cow
    Scene_Object *cow1=new Scene_cow();

    //horse
    Scene_Object *horse1=new Scene_horse();

    //egret
    Scene_Object *egret1=new Scene_Egret();


    //pickupcar
    Scene_Object *pickupcar=new Scene_PickupCar();

    //cube
    Scene_Object *c=new Scene_Cube;

    //apple
    Scene_Object *apple=new Scene_Apple();
};

#endif // SCENE_BASE_H
