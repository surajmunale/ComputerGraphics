#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T19:23:05
#
#-------------------------------------------------

QT       += core gui opengl widgets multimedia


TARGET = ComputerGraphics
TEMPLATE = app


SOURCES += main.cpp\
    Model/cube.cpp \
    Model/sphere.cpp \
    Model/triangle.cpp \
    View/glwidget.cpp \
    View/practicewidget.cpp\
    controller/gmanager.cpp \
    View/mainwindow.cpp \
    View/gamewidget.cpp \
    controller/arcball.cpp \
    Model/plyModel.cpp \
    View/camera.cpp \
    View/light.cpp \
    View/researchwidget.cpp \
    View/scenewidget.cpp \
    SceneGraph/scene_cube.cpp \
    SceneGraph/scene_horse.cpp \
    SceneGraph/scene_object.cpp \
    SceneGraph/scene_graph.cpp \
    SceneGraph/scene_base.cpp \
    SceneGraph/scene_cylinder.cpp \
    SceneGraph/scene_topcone.cpp \
    SceneGraph/scene_cow.cpp \
    SceneGraph/scene_egret.cpp \
    SceneGraph/scene_pickupcar.cpp \
    SceneGraph/scene_apple.cpp \
    SceneGraph/scene_gun.cpp

HEADERS  += \
    Model/cube.h \
    Model/sphere.h \
    Model/triangle.h \
    View/glwidget.h \
    View/mainwindow.h \
    View/practicewidget.h\
    controller/gmanager.h \
    View/gamewidget.h \
    controller/arcball.h \
    Model/plyModel.h \
    View/camera.h \
    View/light.h \
    View/researchwidget.h \
    View/scenewidget.h \
    SceneGraph/scene_cube.h \
    SceneGraph/scene_horse.h \
    SceneGraph/scene_object.h \
    SceneGraph/scene_graph.h \
    SceneGraph/scene_base.h \
    SceneGraph/scene_cylinder.h \
    SceneGraph/scene_topcone.h \
    SceneGraph/scene_cow.h \
    SceneGraph/scene_egret.h \
    SceneGraph/scene_pickupcar.h \
    SceneGraph/scene_apple.h \
    SceneGraph/scene_gun.h


FORMS    += \
    View/mainwindow.ui

LIBS += -lglut -L/usr/local/lib -lGLU

OTHER_FILES += \
    Model/pickup_big.ply \
    Model/car.ply \
    Model/bunny.ply \
    Model/balance.ply

RESOURCES +=


