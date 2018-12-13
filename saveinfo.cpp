#include "saveinfo.h"
#include "ui_saveinfo.h"

SaveInfo::SaveInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveInfo)
{
    ui->setupUi(this);
}

SaveInfo::~SaveInfo()
{
    delete ui;
}
