#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QTimer>
#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initilizedGL();

    void paintGL();

    void resizeGL(int w,int h);

    void stopTimer();

    void startTimer();

    int clientWidth,clientHeight;

    int currentShape;

public slots:

private:
    QTimer timer;
    QPoint m_lastPoint;
    bool m_mouseClick;
};

#endif // GLWIDGET_H
