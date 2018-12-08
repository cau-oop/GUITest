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
