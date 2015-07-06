#include "gmanager.h"
#include <View/mainwindow.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <GL/glut.h>
GManager::GManager()
{

}
void GManager::initilizeController()
{
    MainWindow* w=new MainWindow();
    w->initilizeMainScreen();

    int WIDTH = 450;
    int HEIGHT = 550;

    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->width();
    int screenHeight = desktop->height();
    int x = (screenWidth - WIDTH) / 2;
    int y = (screenHeight - HEIGHT) / 2;

    w->resize(WIDTH,HEIGHT);
    w->move(x,y);
    w->show();

}
