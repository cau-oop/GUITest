#include "memberinfo.h"
#include "ui_memberinfo.h"
#include "password.h"

memberInfo::memberInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberInfo)
{
    ui->setupUi(this);
}

memberInfo::~memberInfo()
{
    delete ui;
}

void memberInfo::on_pushButton_clicked()
{
    password pass;
    pass.setModal(true);
    pass.exec();

}
