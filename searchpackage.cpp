#include "searchpackage.h"
#include "ui_searchpackage.h"

searchpackage::searchpackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchpackage)
{
    ui->setupUi(this);
}

searchpackage::~searchpackage()
{
    delete ui;
}


void searchpackage::on_priceslider_valueChanged(int value)
{
    ui->pricelabel->setText(QString("%1").arg(value));

}

void searchpackage::on_searchbut_clicked()
{

if(ui->asklocation->isChecked())
{
   comparedata[0] = ui->ansloc->text();
}
if(ui->askminp->isChecked())
{
    comparedata[1] = ui->pricelabel->text();
}
}
