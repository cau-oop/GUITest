#include "adtopay.h"
#include "ui_adtopay.h"
#include "guestmain.h"
#include "pay.h"

adtopay::adtopay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adtopay)
{
    ui->setupUi(this);
    GuestMain GM;
    QString save = GM.savead;
    ui->label_2->setText(save);
   ui->label_2->setWordWrap(true);
   ui->widget->setVisible(false);
   }

adtopay::~adtopay()
{
    delete ui;
}



void adtopay::on_pushButton_3_clicked()
{
    //아니오
    ui->widget->setVisible(false);
}

void adtopay::on_pushButton_2_clicked()
{
    //예
    hide();
    GuestMain gm;
    gm.setModal(true);
    gm.exec();
}
