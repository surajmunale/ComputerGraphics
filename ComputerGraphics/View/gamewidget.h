#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include <QGLWidget>
#include <QTimer>
#include <QWidget>
#include<controller/arcball.h>
#include<Model/plyModel.h>
#include <View/camera.h>
#include <View/light.h>

const vec eye( 0.0f, 0.0f, 5.0f );
const vec centre( 0.0f, 0.0f, 0.0f );
const vec up( 0.0f, 1.0f, 0.0f );

class GameWidget : public QGLWidget
{

    Q_OBJECT

public:

    explicit GameWidget(QWidget *parent = 0);

    void initilizedGL();

    void paintGL();

    void resizeGL(int w,int h);

    void spotLight(bool check);

    void moveLight(bool check);

    void setModel(string filepath=NULL,long long int vertices=0,long long int faces=0,int nonplymodel=0);

    void setModel(string filepath,long long int vertices,long long int faces,int nonplymodel,float scalex,float scaley,float scalez);
    void fetchVertexFaces(string filename,long long int *,long long int*);
    void drawAxis();
    void setPresective();
    void setFlatShadding(bool set);
    int prespectiveid=0;

private:
    QTimer timer;
    QPoint m_lastPoint;

    Camera camera;
    Light light;

    QPointF pixelPosToViewPos(const QPointF& p);
    bool m_mouseClick;
    int height,width,movelight=0,shadetype=0;
    float scalex,scaley,scalez;

    vec eye,up,center;
    plyModel* p2;
    GLfloat light_position[4];

public slots:
     void spotLighting();
signals:

    void mouseClickEvent();
    void keyPressEvent();

protected:

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent ( QMouseEvent * e );
    void mouseReleaseEvent(QMouseEvent* e);
    void keyPressEvent(QKeyEvent* event);
};

#endif // GAMEWIDGET_H
