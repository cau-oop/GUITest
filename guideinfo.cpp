#include "guideinfo.h"
#include "ui_guideinfo.h"
#include "passwordcheck.h"
#include "guidemain.h"

GuideInfo::GuideInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuideInfo)
{
    ui->setupUi(this);
}

GuideInfo::~GuideInfo()
{
    delete ui;
}

void GuideInfo::on_pushButton_clicked()
{
    //비밀번호 확인창으로 이동
    hide();
    PasswordCheck pass;
    pass.setModal(true);
    pass.exec();
}

void GuideInfo::on_pushButton_2_clicked()
{
    hide();
    GuideMain gm;
    gm.setModal(true);
    gm.exec();
}
