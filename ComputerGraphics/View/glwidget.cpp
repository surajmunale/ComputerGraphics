//This is the View Class

#include "glwidget.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include "Model/cube.h"
#include "Model/triangle.h"
#include "Model/sphere.h"
#include <QMouseEvent>
#include <QMatrix4x4>
#include <math.h>

///This is Constructor
GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    clientWidth=0;
    clientHeight=0;
    m_mouseClick = false;

}

///This Method is used to stop the timer.This can be called from controller class.
void GLWidget::startTimer()
{
    timer.start(100);
}

///This Method is used to stop the timer.This can be called from controller class.
void GLWidget::stopTimer()
{
    timer.stop();
}

///This method is used to initilize the widget when it invoke first time.
/// Its like constructor of widjet
void GLWidget::initilizedGL()
{

        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

}

///This method is used to draw the objects on the widget.
/// this method get invoked when glUpdate method get called.
void GLWidget:: paintGL()
{
        glEnable(GL_DEPTH_TEST);
    //scene =0 means first screen.
        //glScalef (1.0, 0.95, 1.0);///use to scale the object which is on the main screen.

        ///Below code dispaly object according to the current shape that user choosen.
        switch(currentShape)
        {
        case 1:
            Cube::rotate();
            Cube::display();
            break;

        case 2:
            Triangle::rotate();
            Triangle::display();
            break;

        case 3:
            sphere::rotate();
            sphere::display();
            break;
        }
}

//This function get called whenever window resize  happens.
void GLWidget::resizeGL(int width,int height)
{

    clientWidth=width;
    clientHeight=height;

        //set the view port
        glViewport( 0, 0, (GLint)width, (GLint)height );
        //below code set the projection using Frustm function .
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum( -1.0, 1.0, -1.0, 1.0, 5.0, 30.0);
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        glTranslatef(0.0f,0.0f,-20.0f);//This line will translate the object by -20 on z axis because of which user can see object far from eye.

    //setFocus();//this function is used for accept the key press /mouse click event by widget.
}
