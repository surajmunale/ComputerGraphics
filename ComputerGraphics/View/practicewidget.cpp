#include "practicewidget.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include "Model/cube.h"
#include "Model/triangle.h"
#include "Model/sphere.h"
#include <QMouseEvent>
#include <QMatrix4x4>
#include <math.h>

PracticeWidget::PracticeWidget(QWidget *parent) :
    QGLWidget(parent)
{

}

///This method is used to initilize the widget when it invoke first time.
/// Its like constructor of widjet
void PracticeWidget::initilizedGL()
{

        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

}
void PracticeWidget:: paintGL()
{
    glEnable(GL_DEPTH_TEST);

     //Again object get dispalyed over screen according to the current object.
        switch(currentShape)
        {

        case 1:
                Cube::display();
            break;
        case 2:
                Triangle::display();

            break;
        case 3:
                sphere::display();

            break;
        }

}

//This function get called whenever window resize  happens.
void PracticeWidget::resizeGL(int width,int height)
{

    clientWidth=width;
    clientHeight=height;
    glViewport( 0, 0, (GLint)width, (GLint)height );
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90, 1,2,9);

        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        glTranslatef(0.0f,0.0f,-15.0f); //This line will translate the object by -20 on z axis because of which user can see object far from eye.

        gluLookAt(0,0,6,0,0,5,0,1,0);//if we dont use this then user cant see left face or right face. this function will change the angle of eye.


    setFocus();//this function is used for accept the key press /mouse click event by widget.
}

//This function is used to convert the Screen co-ordinate to the world co-ordinate
void PracticeWidget::convertTo3D(QPoint p)
{

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    //these  variable stores the screen co-ordinates(x,y,z)
    GLfloat x, y, z;
    //these  variable stores the world co-ordinates(wx,wy,wz)
    GLdouble wx, wy, wz;

    //store the modelview,projectionview,viewport information in respective array.
    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    x = float(p.x());
    y = (float)viewport[3] - (float)p.y();//this is used becausescreen co-ordinates are from top left and world co-ordinates are from bottom left.
                                          //So to convert just subtract the y from y of viewport.
    z = 0;
    glReadPixels(x, y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);//in Z depth co-ordinates is stored.

    //get the world coordinates from the screen coordinates
    if(gluUnProject(x,y,z,modelview,projection,viewport,&wx, &wy, &wz))
    {
        //now apply the translation on object using this world co-ordinate.
       Cube::translate((GLfloat)wx, (GLfloat)wy, (GLfloat)wz);
    }

}

///Mouse Event listener
void PracticeWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {

        m_lastPoint  = event->pos();
        //m_lastPoint=mapFromGlobal(m_lastPoint);
        convertTo3D(m_lastPoint);
        updateGL();
    }
}

//on mouse move store the mouse poistion as a latest and use that during click.
void PracticeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton))
        event->pos();
}

///Keypress event listener
void PracticeWidget::keyPressEvent(QKeyEvent* event)
{
        switch (event->key())
        {
        case Qt::Key_Down:

            //gluLookAt(1,5,5,0,0,0,0,1,0);
            glScalef (0.95, 0.95, 0.95);      /* modeling transformation */
            updateGL();
            break;

        case Qt::Key_Up:
            glScalef (1.05, 1.05, 1.05);      /* modeling transformation */
            updateGL();
            break;
        default:
            break;
        }
}
