#include "pay.h"
#include "ui_pay.h"
#include "adtopay.h"

Pay::Pay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pay)
{
    ui->setupUi(this);
}

Pay::~Pay()
{
    delete ui;
}

void Pay::on_pushButton_clicked()
{
    close();
    adtopay a;
    a.hide();
}

void Pay::on_pushButton_2_clicked()
{
    close();
}
