#include <QApplication>
#include <GL/glut.h>
#include <controller/gmanager.h>
#include <View/mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInit( &argc, argv );
    GManager* manager=new GManager();
    manager->initilizeController();
    return a.exec();
}
