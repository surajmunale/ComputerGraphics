//This is the Controller class

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MainWidget->currentShape=1;
    ui->frame_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::initilizeMainScreen()
{
    ui->MainWidget->currentShape=1;
    ui->MainWidget->startTimer();
    ui->MainWidget->show();
    ui->MainWidget->initilizedGL();
    ui->Pwidget->hide();
    ui->Widget->hide();
    ui->Rwidgets->hide();
    ui->Swidget->hide();

}

void MainWindow::initilizePracticeScreen()
{
    ui->Pwidget->currentShape=ui->MainWidget->currentShape;
    ui->Pwidget->show();
    ui->Pwidget->initilizedGL();
    ui->MainWidget->hide();
    ui->Widget->hide();
    ui->Rwidgets->hide();
    ui->Swidget->hide();
}

void MainWindow::initilizeGameScreen()
{
ui->Widget->show();
ui->Widget->initilizedGL();
ui->MainWidget->hide();
ui->Pwidget->hide();
ui->Rwidgets->hide();
ui->Swidget->hide();

ui->Widget->setModel("bunny.ply", 35947,69451);

}

void MainWindow::initilizeResearchScreen()
{
ui->Rwidgets->show();
ui->Rwidgets->initilizedGL();
ui->MainWidget->hide();
ui->Pwidget->hide();
ui->Widget->hide();
ui->ControlWidget->hide();
ui->Swidget->hide();
}

void MainWindow::initilizeSceneScreen()
{
ui->Swidget->show();
ui->Swidget->initilizedGL();
ui->Rwidgets->hide();
ui->MainWidget->hide();
ui->Pwidget->hide();
ui->Widget->hide();
ui->ControlWidget->hide();
}

//Event Handler for PLY Model button
void MainWindow::on_pushButton_clicked()
{
    this->showFullScreen();
    initilizeGameScreen();
}

//Event Handler for Cube game button
void MainWindow::on_pushButton_4_clicked()
{
    ui->MainWidget->currentShape=1;
}

//Event Handler for Cone game button
void MainWindow::on_pushButton_5_clicked()
{
    ui->MainWidget->currentShape=2;
}

//Event Handler for Sphere game button
void MainWindow::on_pushButton_6_clicked()
{
    ui->MainWidget->currentShape=3;
}

//Practice Button
void MainWindow::on_pushButton_7_clicked()
{
    this->showFullScreen();
    initilizePracticeScreen();
}

//Event handler for about box
void MainWindow::on_pushButton_3_clicked()
{
    this->showFullScreen();
    initilizeResearchScreen();
}

//Start the Scene graph
void MainWindow::on_pushButton_11_clicked()
{
    this->showFullScreen();
    initilizeSceneScreen();
}
void MainWindow::on_pushButton_9_clicked()
{
    if(slider==0)
    {
        ui->frame_2->show();
        ui->pushButton_9->setText("-");
        slider=1;
    }
    else
    {
        ui->frame_2->hide();
        ui->pushButton_9->setText("+");
        slider=0;
    }
}

//Spot Light
void MainWindow::on_checkBox_clicked(bool checked)
{
        ui->Widget->spotLight(checked);
}

//Moving light
void MainWindow::on_radioButton_clicked(bool checked)
{
    if(ui->radioButton->isChecked())
    ui->Widget->moveLight(checked);
}

//Spot Light
void MainWindow::on_checkBox_clicked()
{

}

//Moving light
void MainWindow::on_radioButton_clicked()
{

}

//Stationalry light
void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(ui->radioButton_2->isChecked())
    ui->Widget->moveLight(!checked);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {
        //bunny
        case 0:
                ui->Widget->setModel("bunny.ply", 35947,69451);
                ui->Widget->initilizedGL();
                break;

        //Teapot
        case 1:
                    ui->Widget->setModel("",0,0,1);
                    ui->Widget->initilizedGL();
                    break;

        //car
        case 2:
                    ui->Widget->setModel("car.ply", 6870,13402);
                    ui->Widget->initilizedGL();
                    break;

         //plane
         case 3:
                ui->Widget->setModel("balance.ply", 1288,2176);
                ui->Widget->initilizedGL();
                break;

        default:
            break;
    }
}

//flat
void MainWindow::on_radioButton_3_clicked(bool checked)
{
        ui->Widget->setFlatShadding(true);
}

//smooth
void MainWindow::on_radioButton_4_clicked(bool checked)
{
        ui->Widget->setFlatShadding(false);
}

void MainWindow::on_pushButton_8_clicked()
{
    int vertices=0;
    //vertices=ui->lineEdit_2->text().toInt();
    int faces=0;
    //faces=ui->lineEdit_3->text().toInt();
    float scalex,scaley,scalez;
    scalex=ui->lineEdit_4->text().toFloat();
    scaley=ui->lineEdit_5->text().toFloat();
    scalez=ui->lineEdit_6->text().toFloat();

   //if(vertices!=0 && faces!=0)
   //{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("Ply Files (*.ply)"));
    if(fileNames.length()==0)
    {
        return;
    }
    QString fname=fileNames.first();
    ui->Widget->setModel(fname.toStdString(),vertices,faces,0,scalex,scaley,scalez);
    ui->Widget->initilizedGL();
    //}
}

//Edges of the BSP Tree
void MainWindow::on_radioButton_5_clicked(bool checked)
{
    if(checked)
    ui->Rwidgets->setMode(1);
}

//Viewing point
void MainWindow::on_radioButton_6_clicked(bool checked)
{
    if(checked)
    ui->Rwidgets->setMode(2);

}

//create BSP tree.
void MainWindow::on_pushButton_10_clicked()
{
    ui->Rwidgets->setMode(3);
    ui->Rwidgets->ExecuteBSP();
}

//rotate the Scene_graph
void MainWindow::on_pushButton_12_clicked()
{
    ui->Swidget->setTimer(1);
}

void MainWindow::on_pushButton_13_clicked()
{
       ui->Swidget->setTimer(0);
}
