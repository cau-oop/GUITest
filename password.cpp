#include "password.h"
#include "ui_password.h"
#include "mainwindow.h"
#include "memberinfo.h"
//비밀번호 재설정
extern QString pw;
password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
}

password::~password()
{
    delete ui;
}

void password::on_pushButton_clicked()
{

    pw = ui->lineEdit->text();
    hide();
    memberInfo memb;
    memb.setModal(true);
    memb.exec();

}
