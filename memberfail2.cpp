#include "memberfail2.h"
#include "ui_memberfail2.h"

MemberFail2::MemberFail2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemberFail2)
{
    ui->setupUi(this);
}

MemberFail2::~MemberFail2()
{
    delete ui;
}

void MemberFail2::on_pushButton_clicked()
{
    close();
}
