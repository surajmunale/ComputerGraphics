#include "researchwidget.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <QMouseEvent>
#include <QMatrix4x4>
#include <list>
#include <string>
#include<math.h>
using namespace std;

ResearchWidget::ResearchWidget(QWidget *parent) :
    QGLWidget(parent)
{

}

//This function is used to convert the Screen co-ordinate to the world co-ordinate
void ResearchWidget::convertTo3D(QPoint p)
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
        cur_x=wx;
        cur_y=wy;
    }

}

///This method is used to initilize the widget when it invoke first time.
/// Its like constructor of widjet
void ResearchWidget::initilizedGL()
{
    glClearColor(0.2,0.2,0.2,1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}

void ResearchWidget:: paintGL()
{
   // glColor3f(1,0,0);
    //QPainter p(this);
    //p.setPen(Qt::green);
    //p.drawText(10,10,"s");
    switch(mode)
    {
    //edges
    case 1:

        if(counter==0)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.0001,0.0001);
        glEnd();

        if(counter>0 && (counter%2)==0)
        {
            glBegin(GL_LINES);
                glVertex2f(last_x,last_y);
                glVertex2f(cur_x,cur_y);
            glEnd();
            bsppoint p1,p2;
            p1.x=last_x;
            p1.y=last_y;
            p2.x=cur_x;
            p2.y=cur_y;
            elist.push_back(make_pair(p1,p2));
        }

        break;

    //viewing point
    case 2:
             glBegin( GL_POINTS );
              glColor3f( 0.95f, 0.207, 0.031f );
                glVertex2f(cur_x,cur_y);
            glEnd();
        break;

    //Drawing normals:
    case 3:
        for (std::list< std::pair<bsppoint,bsppoint> >::iterator it = elist.begin(); it != elist.end(); it++)
        {
            GLfloat x1,y1,x2,y2,xdif,ydif,a1,b1,a2,b2;
            x1=(*it).first.x;
            y1=(*it).first.y;

            x2=(*it).second.x;
            y2=(*it).second.y;

            xdif = x2 - x1;
            ydif = y2 - y1;

            a1 = x2 - ydif/2.0;
            b1= y2 + xdif/2.0;
            a2= x2 + ydif/2.0;
            b2= y2 - xdif/2.0;
            GLfloat input_val=((x2-x1)*(cur_y-y1))-((y2-y1)*(cur_x-x1));
            double position=sin(input_val);
            if(position>=1)
            {
                a1=x2;
                b1=y2;

                a2=a2;
                b2=b2;
            }

            else if(position<=1)
            {
                a2=x2;
                b2=y2;

                a1=a1;
                b1=b1;
            }


            glBegin(GL_LINES);
                glVertex2f(a1,b1);
                glVertex2f(a2,b2);
            glEnd();
        }

        break;

    }

}
void ResearchWidget::setMode(int val)
{
    mode=val;
    if(val==2)
    {
        counter=0;
    }
}
//creat the BSP
void ResearchWidget::ExecuteBSP()
{
        update();
       //std::cout << *it->x << ' '<<*it->y;
}
//This function get called whenever window resize  happens.
void ResearchWidget::resizeGL(int width,int height)
{

        glViewport( 0, 0, (GLint)width, (GLint)height );
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();

}

///Mouse Event listener
void ResearchWidget::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        last_x=cur_x;
        last_y=cur_y;
        convertTo3D(event->pos());
        //m_currentPoint=event->pos();
        counter++;
        update();
    }

}
