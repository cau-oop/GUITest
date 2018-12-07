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

void addPackage::on_pushButton_clicked()
{

}

void addPackage::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
        {
            ui->comboBox_2->clear();
            ui->comboBox_2->addItem("연남동");
            ui->comboBox_2->addItem("서교동");
            ui->comboBox_2->addItem("동교동");
        }
        if(index == 1)
        {
            ui->comboBox_2->clear();
            ui->comboBox_2->addItem("삼청동");
            ui->comboBox_2->addItem("사직동");
            ui->comboBox_2->addItem("계동");
        }
        if(index == 2)
        {
            ui->comboBox_2->clear();
            ui->comboBox_2->addItem("신사동");
            ui->comboBox_2->addItem("논현동");
            ui->comboBox_2->addItem("도곡동");
        }
}
