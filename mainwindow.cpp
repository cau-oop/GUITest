#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "memberinfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
