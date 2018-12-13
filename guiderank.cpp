#include "guiderank.h"
#include "ui_guiderank.h"
#include "guestmypage.h"
//가이드 평가
GuideRank::GuideRank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuideRank)
{
    ui->setupUi(this);
}

GuideRank::~GuideRank()
{
    delete ui;
}

void GuideRank::on_pushButton_clicked()
{
    //평가완료
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

}

void GuideRank::on_pushButton_2_clicked()
{
    hide();
    GuestMyPage gmp;
    gmp.setModal(true);
    gmp.exec();
}
