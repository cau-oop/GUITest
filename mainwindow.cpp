#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    QPixmap pix("C:/Users/hansn/Test/opening.jpg");
    ui->label_pic->setPixmap(pix.scaled(640,640, Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
