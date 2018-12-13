#include "loginfail2.h"
#include "ui_loginfail2.h"

LoginFail2::LoginFail2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginFail2)
{
    ui->setupUi(this);
}

LoginFail2::~LoginFail2()
{
    delete ui;
}

void LoginFail2::on_pushButton_clicked()
{
    close();
}
