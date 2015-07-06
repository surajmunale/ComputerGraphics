#ifndef PRACTICEWIDGET_H
#define PRACTICEWIDGET_H

#include <QGLWidget>

class PracticeWidget : public QGLWidget
{
    Q_OBJECT

private:

    QPoint m_lastPoint;
       // member variable - flag of click beginning
    bool m_mouseClick;

public:

    explicit PracticeWidget(QWidget *parent = 0);

    void initilizedGL();

    void paintGL();

    void resizeGL(int w,int h);

    void convertTo3D(QPoint);

    int currentShape;

    int clientWidth,clientHeight;

signals:
 void mouseClickEvent();
 void keyPressEvent();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent ( QMouseEvent * e );
    void keyPressEvent(QKeyEvent* event);

public slots:

};

#endif // PRACTICEWIDGET_H
