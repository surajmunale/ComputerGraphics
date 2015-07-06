#include "scenewidget.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <SceneGraph/scene_graph.h>
#include <QMouseEvent>
#include<controller/arcball.h>
#include <SceneGraph/scene_cylinder.h>
#include <QtMultimedia/QSound>

typedef unsigned char BYTE;
SceneWidget::SceneWidget(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    keypad->setLoops(10000);
    ambience->setLoops(10000);
    keypad->play();

    connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    //timer.start(200);
    g.construct();

}

void SceneWidget::initilizedGL()
{
    glClearColor(0.2,0.2,0.2,1);
    glEnable(GL_DEPTH_TEST);


}

//http://stackoverflow.com/questions/6723124/how-can-i-move-object-without-redrawing-the-other-objects

void SceneWidget:: paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //g.clearDisplay(g.surface);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(100,(float)width/height,0.01,150.0);

    gun->display();

    LookAtx=camerax+lx;
    LookAty=cameray+ly;
    LookAtz=cameraz+lz;
    gluLookAt(camerax,cameray,cameraz,LookAtx,LookAty,LookAtz,0,1,0);

    if(timer.isActive())
    {
        osscilate_timer=(osscilate_timer+1)%10;
        if(osscilate_timer%10==0)
        {
            osscilate=(osscilate+1)%2;

            g.b->oscillate(osscilate);
            g.b1->oscillate(osscilate);
            g.b2->oscillate(osscilate);
            g.b3->oscillate(osscilate);
            g.b4->oscillate(osscilate);

        }

        //rotate the base
        int tmp1=g.b->rotationMatrix.w();
        g.b->rotationMatrix.setW(tmp1+10);
        g.b->isDisplayed=0;

        tmp1=g.b1->rotationMatrix.w();
        g.b1->rotationMatrix.setW(tmp1+10);
        g.b1->isDisplayed=0;

        tmp1=g.b2->rotationMatrix.w();
        g.b2->rotationMatrix.setW(tmp1+10);
        g.b1->isDisplayed=0;

        tmp1=g.b3->rotationMatrix.w();
        g.b3->rotationMatrix.setW(tmp1+10);
        g.b1->isDisplayed=0;

        tmp1=g.b4->rotationMatrix.w();
        g.b4->rotationMatrix.setW(tmp1+10);
        g.b1->isDisplayed=0;
    }

    g.display(g.surface);

}

//This function get called whenever window resize  happens.
void SceneWidget::resizeGL(int width,int height)
{
        this->width=width;
        this->height=height;
        glViewport( 0, 0, (GLint)width, (GLint)height );

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(100,(float)width/height,0.01,150.0);

        //gluLookAt(camera.x, camera.y, camera.z,  lookat.x, lookat.y, lookat.z, 0, 1, 0)
        //gluLookAt(0,2,5,0,0,0,0,1,0);
        LookAtx=camerax+lx;
        LookAty=cameray+ly;
        LookAtz=cameraz+lz;
        gluLookAt(camerax,cameray,cameraz,LookAtx,LookAty,LookAtz,0,1,0);

}

void SceneWidget::setTimer(int value)
{
    if(value==1)
    {
        keypad->stop();
        ambience->play();
        timer.start(300);

    }
    else
    {
        ambience->stop();
        keypad->play();
        timer.stop();
    }
}
void  SceneWidget::rotateBase()
{
    updateGL();
}


///Keypress event listener
///w->up
/// a->left
/// s->bottom
/// d->right
///
void SceneWidget::keyPressEvent(QKeyEvent* event)
{
    float move_fraction = 0.4f;
    float angle_fraction = 0.04f;
        /*if(keypress==0)
        {
            return;
        }*/
        switch (event->key())
        {
        case Qt::Key_Up:
            angle += angle_fraction;
            ly = sin(angle);
            lz = -cos(angle);
            updateGL();
            break;

        case Qt::Key_Down:
            angle -= angle_fraction;
            ly = sin(angle);
            lz = -cos(angle);
            updateGL();
            break;

        case Qt::Key_Left:
            break;

        case Qt::Key_Right:
            break;

        case Qt::Key_W:
            camerax += lx * move_fraction;
            cameraz  += lz * move_fraction;
            //glTranslatef(0,0,1);
            updateGL();
            break;

        case Qt::Key_A:
            angle -= angle_fraction;
            lx = sin(angle);
            lz = -cos(angle);
            updateGL();
            break;

        case Qt::Key_S:
            camerax -= lx * move_fraction;
            cameraz  -= lz * move_fraction;
            updateGL();
            break;

        case Qt::Key_D:
            angle += angle_fraction;
            lx = sin(angle);
            lz = -cos(angle);
            updateGL();
            break;
        case Qt::Key_Return:

            gunsound->play();

            break;
        case Qt::Key_Escape:
            this->close();

            break;

        default:
            break;
        }
}
