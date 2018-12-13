#include "newphone.h"
#include "ui_newphone.h"
#include "memberinfo.h"
//전화번호 재설정
NewPhone::NewPhone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPhone)
{
    ui->setupUi(this);
}

NewPhone::~NewPhone()
{
    delete ui;
}

void NewPhone::on_pushButton_clicked()
{
    QString newph;
    newph = ui->lineEdit->text();
    hide();
    memberInfo memb;
    memb.setModal(true);
    memb.exec();
}
