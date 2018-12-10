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
    ui->PID_LCD->display(PID);
 }

addPackage::~addPackage()
{
    delete ui;
}



void addPackage::on_name_button_clicked()
{
    Pname[PID] = ui->name_line->text();
    ui->name_button->setEnabled(false);
}

void addPackage::on_loc_button_clicked()
{
    ui->loc_button->setEnabled(false);
    location[PID] = ui->loc_combo->currentText();
}



void addPackage::on_tag_button_2_clicked()
{
    ui->tag_button_2->setEnabled(false);
    tag[PID] = ui->tag_line->text();
}

void addPackage::on_price_button_2_clicked()
{
    ui->price_button_2->setEnabled(false);
    price[PID] = ui->price_line->text().toInt();
}

void addPackage::on_via_button_2_clicked()
{
    via[PID] = ui->via_combox->currentIndex();
}

void addPackage::on_date_button_clicked()
{
    //calendarwidget , dateeidt
    QString ddate = (ui->dateEdit->date()).toString();
    QStringList ddate_tmp = ddate.split("-");
    QString ddate2 = ddate_tmp.join("");
    trav_start_date[PID] =ddate2.toInt();
}

void addPackage::on_start_button_clicked()
{
    //timeEdit
    QString ttime = (ui->timeEdit->time()).toString();
    QStringList time_tmp = ttime.split(":");
    QString timesave = time_tmp.join("");
    trav_start_hour[PID] = timesave.toInt();
}

void addPackage::on_trav_button_clicked()
{
    free_trav[PID] = ui->trav_combo->currentIndex();
}


void addPackage::on_how_long_button_clicked()
{
    how_long_trav[PID]  = ui->how_long_line->text().toInt();
}

void addPackage::on_min_button_clicked()
{
    minppl[PID] =  ui->min_spin->value();
}

void addPackage::on_max_button_clicked()
{
    maxppl[PID] = ui->max_spinbox->value();
}

void addPackage::ReadFile()
{
    QFile file("packagelist.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream OpenFile(&file);
    QString ConfigText;
    QString search;
    QString tmp;
while(!OpenFile.atEnd())
{
    tmp = QString::number(PID);
    search = "PID >>" + tmp;
    ConfigText=OpenFile.readLine();
    if((ConfigText == search))
    {
        PID++;
    }
}

}

void addPackage::WriteFile()
{
    QFile file("packagelist.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream os(&file);
    os << "PID >>" << PID;
    os << " || 패키지 >>" << Pname[PID];
    os << " || 지역 >>" << location[PID];
    os << " || 태그(띄어쓰기 없이) >>" << tag[PID];
    os << " || 가격 >> " << price[PID];
    os << " || 경유 >>" << via[PID];
    os << " || 출발일 >>" << trav_start_date[PID];
    os << " || 출발시간 >>" << trav_start_hour[PID];
    os << " || 여행기간 >>" << how_long_trav[PID];
    os << " || 자유여행 >>" << free_trav[PID];
    os << " || 최소인원 >> " << minppl[PID];
    os << " || 최대인원 >> " << maxppl[PID] << endl;
}

void addPackage::addRankReview()
{
QString pidtmp;
pidtmp = QString::number(PID);
QString rankfile = pidtmp+".rank.txt";
QFile file(rankfile);
file.open(QIODevice::WriteOnly);
QTextStream rank(&file);
rank << "0 0";
QString reviewfile = pidtmp+".review.txt";
QFile file2(reviewfile);
file2.open(QIODevice::WriteOnly);
QTextStream review(&file2);
review << "리뷰목" <<endl;

}

