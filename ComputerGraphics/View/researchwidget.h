#include <list>
#include <string>
using namespace std;
#ifndef RESEARCHWIDGET_H
#define RESEARCHWIDGET_H

#include <QGLWidget>

class bsppoint
{
public:
GLfloat x,y;
};
typedef std::list< std::pair<bsppoint,bsppoint> > edgelist;

class ResearchWidget : public QGLWidget
{
    Q_OBJECT
private:

    GLfloat last_x,last_y,cur_x,cur_y;
    GLfloat view_x,view_y;

       // member variable - flag of click beginning
    bool m_mouseClick;
    int mode=1;
    int counter=0;
    edgelist elist;

public:
    explicit ResearchWidget(QWidget *parent = 0);

    void initilizedGL();

    void paintGL();

    void resizeGL(int w,int h);

    void convertTo3D(QPoint);

    void setMode(int val);

    void ExecuteBSP();

signals:
 void mouseClickEvent();

protected:
    //void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent ( QMouseEvent * e );
};

#endif // RESEARCHWIDGET_H
