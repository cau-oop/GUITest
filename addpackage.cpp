#include "addpackage.h"
#include "ui_addpackage.h"

addPackage::addPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPackage)
{
    ui->setupUi(this);
}

addPackage::~addPackage()
{
    delete ui;
}
