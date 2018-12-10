#include "searchresult.h"
#include "ui_searchresult.h"

searchresult::searchresult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchresult)
{
    ui->setupUi(this);
    QLabel i_label("Start", &searchlabel);

}

searchresult::~searchresult()
{
    delete ui;
}
