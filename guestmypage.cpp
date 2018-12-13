#include "guestmypage.h"
#include "ui_guestmypage.h"
#include "login.h"
#include "memberinfo.h"
#include "guestmain.h"
#include "guiderank.h"
#include "packrank.h"
#include "packagereview.h"
//여행자가 여러가지 작업을 수행할 수 있는 마이페이지
GuestMyPage::GuestMyPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuestMyPage)
{
    ui->setupUi(this);
}

GuestMyPage::~GuestMyPage()
{
    delete ui;
}

void GuestMyPage::on_pushButton_clicked()
{
    //회원정보수정
    hide();
    memberInfo memb;
    memb.setModal(true);
    memb.exec();
}

void GuestMyPage::on_pushButton_2_clicked()
{
    //패키지평가
    hide();
    PackRank pr;
    pr.setModal(true);
    pr.exec();
}

void GuestMyPage::on_pushButton_3_clicked()
{
    //가이드평가
    hide();
    GuideRank gr;
    gr.setModal(true);
    gr.exec();
}

void GuestMyPage::on_pushButton_4_clicked()
{
    //패키지리뷰
    hide();
    PackageReview pr;
    pr.setModal(true);
    pr.exec();
}

void GuestMyPage::on_pushButton_5_clicked()
{
    //로그아웃
    hide();
    Login log;
    log.setModal(true);
    log.exec();
}

void GuestMyPage::on_pushButton_6_clicked()
{
    hide();
    GuestMain gm;
    gm.setModal(true);
    gm.exec();
}
