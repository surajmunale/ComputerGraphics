/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <View/practicewidget.h>
#include <View/researchwidget.h>
#include <View/scenewidget.h>
#include "View/gamewidget.h"
#include "View/glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    GLWidget *MainWidget;
    PracticeWidget *Pwidget;
    GameWidget *Widget;
    QFrame *frame_2;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_9;
    ResearchWidget *Rwidgets;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QPushButton *pushButton_10;
    SceneWidget *Swidget;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QWidget *ControlWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_11;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1273, 543);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setCursor(QCursor(Qt::ArrowCursor));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(0);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        MainWidget = new GLWidget(frame);
        MainWidget->setObjectName(QStringLiteral("MainWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MainWidget->sizePolicy().hasHeightForWidth());
        MainWidget->setSizePolicy(sizePolicy1);
        MainWidget->setCursor(QCursor(Qt::ArrowCursor));

        verticalLayout->addWidget(MainWidget);

        Pwidget = new PracticeWidget(frame);
        Pwidget->setObjectName(QStringLiteral("Pwidget"));
        sizePolicy1.setHeightForWidth(Pwidget->sizePolicy().hasHeightForWidth());
        Pwidget->setSizePolicy(sizePolicy1);
        Pwidget->setCursor(QCursor(Qt::OpenHandCursor));

        verticalLayout->addWidget(Pwidget);

        Widget = new GameWidget(frame);
        Widget->setObjectName(QStringLiteral("Widget"));
        sizePolicy1.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy1);
        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(30, 0, 1191, 51));
        QPalette palette;
        QBrush brush(QColor(226, 192, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(225, 246, 246, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(240, 250, 250, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(112, 123, 123, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(150, 164, 164, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        frame_2->setPalette(palette);
        frame_2->setStyleSheet(QLatin1String("color:rgb(226, 192, 255)\n"
"\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 111, 27));
        groupBox_2 = new QGroupBox(frame_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(500, 0, 211, 41));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 20, 61, 21));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(100, 20, 91, 21));
        groupBox_3 = new QGroupBox(frame_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(710, 0, 401, 51));
        pushButton_8 = new QPushButton(groupBox_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(0, 30, 99, 21));
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 30, 61, 21));
        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(230, 30, 61, 21));
        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(330, 30, 61, 21));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 30, 16, 17));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 30, 16, 17));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 30, 16, 17));
        groupBox_4 = new QGroupBox(frame_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(130, 0, 351, 41));
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(120, 20, 101, 22));
        radioButton_2 = new QRadioButton(groupBox_4);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(220, 20, 141, 22));
        checkBox = new QCheckBox(groupBox_4);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(0, 20, 121, 22));
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(0, 0, 31, 51));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QStringLiteral("color:rgb(205, 203, 255)"));
        pushButton_9->setFlat(true);

        verticalLayout->addWidget(Widget);

        Rwidgets = new ResearchWidget(frame);
        Rwidgets->setObjectName(QStringLiteral("Rwidgets"));
        sizePolicy1.setHeightForWidth(Rwidgets->sizePolicy().hasHeightForWidth());
        Rwidgets->setSizePolicy(sizePolicy1);
        radioButton_5 = new QRadioButton(Rwidgets);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 0, 117, 22));
        radioButton_5->setChecked(true);
        radioButton_6 = new QRadioButton(Rwidgets);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(130, 0, 131, 22));
        pushButton_10 = new QPushButton(Rwidgets);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(280, 0, 99, 27));

        verticalLayout->addWidget(Rwidgets);

        Swidget = new SceneWidget(frame);
        Swidget->setObjectName(QStringLiteral("Swidget"));
        sizePolicy1.setHeightForWidth(Swidget->sizePolicy().hasHeightForWidth());
        Swidget->setSizePolicy(sizePolicy1);
        pushButton_12 = new QPushButton(Swidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(0, 0, 99, 27));
        pushButton_13 = new QPushButton(Swidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(110, 0, 99, 27));

        verticalLayout->addWidget(Swidget);


        verticalLayout_2->addWidget(frame);

        ControlWidget = new QWidget(centralWidget);
        ControlWidget->setObjectName(QStringLiteral("ControlWidget"));
        sizePolicy1.setHeightForWidth(ControlWidget->sizePolicy().hasHeightForWidth());
        ControlWidget->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(ControlWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(ControlWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);


        verticalLayout_3->addWidget(groupBox);

        pushButton_11 = new QPushButton(ControlWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButton_11);

        pushButton = new QPushButton(ControlWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButton);

        pushButton_7 = new QPushButton(ControlWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_3 = new QPushButton(ControlWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(ControlWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addWidget(ControlWidget);

        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(pushButton, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_6);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), ControlWidget, SLOT(hide()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), ControlWidget, SLOT(hide()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Computer Graphicss", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Bunny", 0)
         << QApplication::translate("MainWindow", "TeaPot", 0)
         << QApplication::translate("MainWindow", "Car", 0)
         << QApplication::translate("MainWindow", "BalanceChairs", 0)
        );
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Shading", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "Flat", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "Gouraud", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "PLYFile", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Load", 0));
        label_3->setText(QApplication::translate("MainWindow", "X", 0));
        label_4->setText(QApplication::translate("MainWindow", "Y", 0));
        label_5->setText(QApplication::translate("MainWindow", "Z", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Light", 0));
        radioButton->setText(QApplication::translate("MainWindow", "SpotLight", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "Stationalry Light", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Moving Light", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("MainWindow", "Settings", 0));
#endif // QT_NO_TOOLTIP
        pushButton_9->setText(QApplication::translate("MainWindow", "+", 0));
        radioButton_5->setText(QApplication::translate("MainWindow", "Edges", 0));
        radioButton_6->setText(QApplication::translate("MainWindow", "Viewing Point", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "Create BSP", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "Start", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "Stop", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Change Shape", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Cube", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Cone", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Sphere", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "Start Game", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PLY Model", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "practice", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Research", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
