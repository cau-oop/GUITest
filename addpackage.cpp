#include "addpackage.h"
#include "ui_addpackage.h"

addPackage::addPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPackage)
{

    ui->setupUi(this);
    ui->loc_combo->addItems(QStringList()<<"대한민국" <<"중국"<<"일본"<<"태국"<<"필리핀"<<"베트남"<<"말레이시아"<<"라오스"<<"미얀마"<<"싱가포르"<<"서남아"<<"대만"<<"홍콩"<<"괌"<<"호주"<<"뉴질랜드"<<"서유럽"<<"동유럽"<<"지중해"<<"러시아"<<"북유럽"<<"발틱"<<"아프리카"<<"중동");
    ui->via_combox->addItem("Yes");
    ui->via_combox->addItem("No");
    ui->trav_combo->addItem("Yes");
    ui->trav_combo->addItem("No");
    //ui->PID_LCD->intValue() =
}

addPackage::~addPackage()
{
    delete ui;
}



void addPackage::on_name_button_clicked()
{
    name = ui->name_line->text();
    ui->name_button->setEnabled(false);
    qDebug() << name;
}

void addPackage::on_loc_button_clicked()
{
    ui->loc_button->setEnabled(false);
    location = ui->loc_combo->currentText();
}



void addPackage::on_tag_button_2_clicked()
{
    ui->tag_button_2->setEnabled(false);
    tag = ui->tag_line->text();
}

void addPackage::on_price_button_2_clicked()
{
    ui->price_button_2->setEnabled(false);
    price = ui->price_line->text().toInt();
}

void addPackage::on_via_button_2_clicked()
{
    via = ui->via_combox->currentIndex();
}

void addPackage::on_date_button_clicked()
{
    //calendarwidget , dateeidt
    QString ddate = (ui->dateEdit->date()).toString();
    QStringList ddate_tmp = ddate.split("-");
    QString ddate2 = ddate_tmp.join("");
    date =ddate2.toInt();
}

void addPackage::on_start_button_clicked()
{
    //timeEdit
    QString ttime = (ui->timeEdit->time()).toString();
    QStringList time_tmp = ttime.split(":");
    QString timesave = time_tmp.join("");
    time = timesave.toInt();
}

void addPackage::on_trav_button_clicked()
{
    free = ui->trav_combo->currentIndex();
}


void addPackage::on_how_long_button_clicked()
{
    howlong  = ui->how_long_line->text().toInt();
}

void addPackage::on_min_button_clicked()
{
    min =  ui->min_spin->value();
}

void addPackage::on_max_button_clicked()
{
    max = ui->max_spinbox->value();
}
