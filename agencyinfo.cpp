#include "agencyinfo.h"
#include "ui_agencyinfo.h"
#include "passwordcheck.h"
#include "agencymain.h"
AgencyInfo::AgencyInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgencyInfo)
{
    ui->setupUi(this);
}

AgencyInfo::~AgencyInfo()
{
    delete ui;
}

void AgencyInfo::on_pushButton_clicked()
{
    //비밀번호 확인창으로 이동
    hide();
    PasswordCheck pass;
    pass.setModal(true);
    pass.exec();
}

void AgencyInfo::on_pushButton_2_clicked()
{   //뒤로가기
    hide();
    AgencyMain am;
    am.setModal(true);
    am.exec();
}
