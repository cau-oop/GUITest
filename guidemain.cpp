#include "guidemain.h"
#include "ui_guidemain.h"
#include "login.h"

GuideMain::GuideMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuideMain)
{
    ui->setupUi(this);
}

GuideMain::~GuideMain()
{
    delete ui;
}

void GuideMain::on_pushButton_clicked()
{
    //회원정보수정
}

void GuideMain::on_pushButton_2_clicked()
{
    //채팅
}

void GuideMain::on_pushButton_3_clicked()
{
    //로그아웃
    hide();
    Login log;
    log.setModal(true);
    log.exec();
}
