#include "agencymain.h"
#include "ui_agencymain.h"
#include "login.h"
#include "addpackage.h"
#include "agencyinfo.h"


AgencyMain::AgencyMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgencyMain)
{
    ui->setupUi(this);
}

AgencyMain::~AgencyMain()
{
    delete ui;
}

void AgencyMain::on_pushButton_clicked()
{
    //회원정보수정
    hide();
    AgencyInfo ai;
    ai.setModal(true);
    ai.exec();
}

void AgencyMain::on_pushButton_2_clicked()
{
    //패키지추가
    hide();
    addPackage ap;
    ap.setModal(true);
    ap.exec();
}

void AgencyMain::on_pushButton_3_clicked()
{
    //패키지관리
    //써치 완성되면 가져오기
}

void AgencyMain::on_pushButton_4_clicked()
{
    //로그아웃
    hide();
    Login l;
    l.setModal(true);
    l.exec();
}
