#include "packrank.h"
#include "ui_packrank.h"
#include "guestmypage.h"
#include "QFile"
#include "QTextStream"
//패키지 평가
PackRank::PackRank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PackRank)
{
    ui->setupUi(this);
}

PackRank::~PackRank()
{
    delete ui;
}

void PackRank::on_pushButton_clicked()
{
    double rankBefore, rankAfter;
    QString pn = ui->lineEdit->text();
    QFile *file = new QFile;
     QString filename = "C:\\GUITest\\"+pn+".rank.txt";
      file->setFileName(filename);
      file->open(QIODevice::ReadOnly);

    QTextStream read(file);
    QString tmp = read.readLine();
    QStringList tmpList = tmp.split(",");
    QString point = tmpList[0];
    double p = point.toDouble();
    QString num = tmpList[1];
    double n = num.toDouble();
    file->close();
    rankBefore = p * n;
    int i;
    if(ui->radioButton->isChecked())
    {
        i = 1;
        hide();
        GuestMyPage gmp;
        gmp.setModal(true);
        gmp.exec();
    }
    if(ui->radioButton_2->isChecked())
    {
        i = 2;
        hide();
        GuestMyPage gmp;
        gmp.setModal(true);
        gmp.exec();
    }
    if(ui->radioButton_3->isChecked())
    {
        i = 3;
        hide();
        GuestMyPage gmp;
        gmp.setModal(true);
        gmp.exec();
    }
    if(ui->radioButton_4->isChecked())
    {
        i = 4;
        hide();
        GuestMyPage gmp;
        gmp.setModal(true);
        gmp.exec();
    }
    if(ui->radioButton_5->isChecked())
    {
        i = 5;
        hide();
        GuestMyPage gmp;
        gmp.setModal(true);
        gmp.exec();
    }
    //평균 랭크 계산과정추가
    n++;
    rankAfter = rankBefore + i;
    p = rankAfter / n;
    QFile *file1 = new QFile;
      file1->setFileName(filename);
      file1->open(QIODevice::WriteOnly);

    QTextStream write(file1);
    point = point.setNum(p);
    QByteArray _point;
    _point.append(point);
    file1->write(_point);
    file1->write(",");
    num = num.setNum(n);
    QByteArray _num;
    _num.append(num);
    file1->write(_num);

file1->close();

}

void PackRank::on_pushButton_2_clicked()
{
    hide();
    GuestMyPage gmp;
    gmp.setModal(true);
    gmp.exec();
}
