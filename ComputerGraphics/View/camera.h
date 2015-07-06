#ifndef CAMERA_H
#define CAMERA_H
#include <QGLWidget>
#include <QWidget>
#include <QQuaternion>
#include <QMatrix4x4>
#include <math.h>
#include<controller/arcball.h>

class Camera
{

private:
    int height,width;
    vec eye,up,center;
public:

    Camera();

    //setter functions

    void setViewPort(int height,int width);
    void setEye(vec eye);


    //gettter functions
    void loadPerspective(int mode=0);


};

#endif // CAMERA_H
