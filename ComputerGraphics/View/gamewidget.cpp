#include "gamewidget.h"
#include "GL/glut.h"
#include "Model/cube.h"
#include <QMouseEvent>
#include <QQuaternion>
#include <QMatrix4x4>
#include <math.h>
#include <QMessageBox>
#include<QLineEdit>
#include <time.h>
#include <iostream>
#include <Model/plyModel.h>
#include<controller/arcball.h>
#include <View/camera.h>

GameWidget::GameWidget(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::ClickFocus);
    connect(&timer,SIGNAL(timeout()),this,SLOT(spotLighting()));
    scalex=scaley=scalez=1;
}
void GameWidget:: setModel(string filepath,long long int vertices,long long int faces,int nonplymodel)
{

        if(filepath.compare("bunny.ply")==0)
        {
            scalex=1.0;
            scaley=1.0;
            scalez=1.0;
            prespectiveid=1;
        }
        if(filepath.compare("car.ply")==0)
        {
            scalex=0.03;
            scaley=0.03;
            scalez=0.03;
            prespectiveid=2;
        }
        if(filepath.compare("balance.ply")==0)
        {
            scalex=-0.001;
            scaley=-0.001;
            scalez=-0.001;
            prespectiveid=3;
        }
        if(nonplymodel==1)
        {
            scalex=0.12;
            scaley=0.12;
            scalez=0.12;
            prespectiveid=4;
        }
        fetchVertexFaces(filepath,&faces,&vertices);
        p2=new plyModel(filepath,vertices,faces,nonplymodel);
}

void GameWidget::fetchVertexFaces(string filename,long long int *f,long long int *v)
{
    char myArray[filename.size()+1];//as 1 char space for null is also required
    //strcpy(myArray, filename.c_str());
    strcpy(myArray, filename.c_str());
    FILE *file = fopen(myArray, "r");
    if (file == NULL)
    {
        perror("ply_load_mesh");

        return ;
    }

    char buffer[80];
    do {

        char c=fscanf(file,"%s",buffer);

        if (c == NULL)
        {
            puts("skip_header(): fgets error");
        }

        if(strcmp(buffer, "vertex") == 0)
        {
            c=fscanf(file,"%s",buffer);
            *v=atoi(buffer);
        }
        if(strcmp(buffer, "face") == 0)
        {
            c=fscanf(file,"%s",buffer);
            *f=atoi(buffer);
        }
    } while (strcmp(buffer, "end_header") != 0);

    fclose(file);
}

void GameWidget:: setModel(string filepath,long long int vertices,long long int faces,int nonplymodel,float scalex,float scaley,float scalez)
{
       if(p2!=NULL)
       {
           free(p2);
       }
       this->scalex=scalex;
       this->scaley=scaley;
       this->scalez=scalez;
       fetchVertexFaces(filepath,&faces,&vertices);
       p2=new plyModel(filepath,vertices,faces,nonplymodel);
}

void GameWidget:: spotLighting()
{

    GLfloat pp[] = { 1.0, 1.0, 1.0, 0.0 };
    srand( (unsigned)time( NULL ) );

    float iSecret=(float) rand()/RAND_MAX;
    pp[0]=iSecret ;

    iSecret=(float) rand()/RAND_MAX;
    pp[1]=iSecret ;

    iSecret=(float) rand()/RAND_MAX;
    pp[2]=iSecret ;

    iSecret=(float) rand()/RAND_MAX;
    pp[3]=iSecret ;

    glLightfv(GL_LIGHT0, GL_POSITION, pp);

    updateGL();
}
void GameWidget::drawAxis()
{
    glLineWidth(0.2);
    //Dotted line
    glLineStipple(1, 0x3F07);
    glEnable(GL_LINE_STIPPLE);

    glBegin(GL_LINES);

    //x Axis
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);

    // y axis
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 100.0, 0.0);

    //z axis
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 100.0);

    glEnd();

    glDisable(GL_LINE_STIPPLE);
}

///This method is used to initilize the widget when it invoke first time.
/// Its like constructor of widget
void GameWidget::initilizedGL()
{
    glClearColor(0.2,0.2,0.2,1);

    glEnable(GL_DEPTH_TEST);

    light_position[0]=1.0;
    light_position[1]=1.0;
    light_position[2]=1.0;
    light_position[3]=0.0;

    GLfloat ambient0[]={0.2, 0.2, 0.2, 1.0}; // Farbdefinitionen
    GLfloat diffuse0[]={0.2, 0.2, 0.2, 1.0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse0);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void GameWidget:: paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawAxis();
    arcball_rotate();

    glScalef(scalex,scaley,scalez);

    glColor3f(0.1, 0.6, 0.8);
    if(shadetype==1)
    {
        p2->display_flat_draw();
    }
    else
    {
      p2->display_draw();
    }

    QGLWidget::swapBuffers();

    if(movelight)
    {
         glLightfv(GL_LIGHT0, GL_POSITION,light_position);
    }
}

void GameWidget::setPresective()
{
        camera.loadPerspective(prespectiveid);
        updateGL();
}

//This function get called whenever window resize  happens.
void GameWidget::resizeGL(int width,int height)
{

    this->height=height;
    this->width=width;
    glViewport(0,0,(GLint)width, (GLint)height);
    camera.setEye(eye);
    camera.setViewPort(height,width);
    camera.loadPerspective(1);
    setFocus();
    updateGL();
}

///Mouse Event listener
void GameWidget::mousePressEvent(QMouseEvent *event)
{
   int invert_x = (width- event->pos().x()) - 1; // OpenGL viewport coordinates are Cartesian
   arcball_start(invert_x,event->pos().y());
}

void GameWidget::mouseReleaseEvent(QMouseEvent *event)
{
    setFocus();
}

//on mouse move store the mouse poistion as a latest and use that during click.
void GameWidget::mouseMoveEvent(QMouseEvent *event)
{

        int x=event->pos().x();
        int y=event->pos().y();
        this->setFocus();
        int invert_x = (width- event->pos().x()) - 1; // OpenGL viewport coordinates are Cartesian
        arcball_move(invert_x,y);
        updateGL();
}
void GameWidget::spotLight(bool check)
{
    if(check)
    {
        timer.start(500);
    }
    else
    {
        timer.stop();
    }
}

void GameWidget::moveLight(bool check)
{
    if(check)
    {
        movelight=1;
    }
    else
    {
        movelight=0;
    }
}

void GameWidget::setFlatShadding(bool set)
{
    if(set)
    {
        shadetype=1;
        updateGL();
    }
    else
    {
        shadetype=0;
        updateGL();
    }

}
void GameWidget::keyPressEvent(QKeyEvent* event)
{

        switch (event->key())
        {
        case Qt::Key_Down:
            scalex-=0.002;
            scaley-=0.002;
            scalez-=0.002;
            updateGL();
            break;

        case Qt::Key_Up:
            scalex+=0.002;
            scaley+=0.002;
            scalez+=0.002;
            updateGL();
            break;

        default:
            break;
        }
}
