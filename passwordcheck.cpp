#include "passwordcheck.h"
#include "ui_passwordcheck.h"
#include "password.h"
//비밀번호 확인

extern QString pw;
PasswordCheck::PasswordCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordCheck)
{
    ui->setupUi(this);
}

PasswordCheck::~PasswordCheck()
{
    delete ui;
}

void PasswordCheck::on_pushButton_clicked()
{
    QString pass = pw;

    if(pass == ui->lineEdit->text())
    {
        ui->label->setText("") ;
        hide();
        password pw;
        pw.setModal(true);
        pw.exec();
    }
    else {
        ui->label->setText("비밀번호가 일치하지 않습니다.") ;
    }
}
