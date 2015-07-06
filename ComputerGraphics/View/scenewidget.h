#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QGLWidget>
#include <SceneGraph/scene_cube.h>
#include <SceneGraph/scene_horse.h>
#include <SceneGraph/scene_object.h>
#include <SceneGraph/scene_graph.h>
#include <SceneGraph/scene_gun.h>
#include <QtMultimedia/QSound>
#include <QTimer>

class SceneWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = 0);

    void initilizedGL();

    void paintGL();

    void resizeGL(int w,int h);

    void setTimer(int value);

    void rotateBase();

    Scene_Graph g;

    QTimer timer;

    GLdouble camerax=0,cameray=2,cameraz=3,LookAtx=0,LookAty=0,LookAtz=0;
    float angle=0.0;
    float lx=0.0f,ly=0.0f,lz=-1.0f;
    int osscilate=0 ,osscilate_timer=0;
    int width,height;

    QSound *ambience=new QSound("ambience.wav",this);
    QSound *gunsound= new QSound("gun.wav", this);

    QSound *keypad= new QSound("game.wav", this);

    Scene_Gun *gun=new Scene_Gun();

signals:

    void keyPressEvent();



protected:

    void keyPressEvent(QKeyEvent* event);

};

#endif // SCENEWIDGET_H
