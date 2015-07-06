#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <list>
#include <QMatrix4x4>

//abstract class.
//cant creat the object of this class
class Scene_Object
{
public:
    Scene_Object();
    virtual void translate(int ,int,int)=0;
    virtual void display()=0;
    virtual void rotate()=0;
    virtual void scale()=0;
    virtual void oscillate(int)=0;
    int isDisplayed=0;
    std::list<Scene_Object*> childrens;
    QVector3D tranMatrix;
    QVector4D rotationMatrix;
    QVector3D scaleMatrix;

};

#endif // SCENE_OBJECT_H
