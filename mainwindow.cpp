#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "memberinfo.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Image/opening.jpg");
    ui->label_pic->setPixmap(pix.scaled(640,640, Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    memberInfo memb;
    memb.setModal(true);
    memb.exec();

}
