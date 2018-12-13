#include "memberfail.h"
#include "ui_memberfail.h"

MemberFail::MemberFail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemberFail)
{
    ui->setupUi(this);
}

MemberFail::~MemberFail()
{
    delete ui;
}

void MemberFail::on_pushButton_clicked()
{
    close();
}
