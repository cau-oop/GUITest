#include "makenew.h"
#include "ui_makenew.h"
#include "login.h"
#include "generalmember.h"
#include "agencymember.h"
#include "guidemember.h"
//회원가입
MakeNew::MakeNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MakeNew)
{
    ui->setupUi(this);
}

MakeNew::~MakeNew()
{
    delete ui;
}
void MakeNew::on_pushButton_4_clicked()
{
    hide();
    Login log;
    log.setModal(true);
    log.exec();
}

void MakeNew::on_pushButton_clicked()
{
    hide();
    GeneralMember gm;
    gm.setModal(true);
    gm.exec();

}

void MakeNew::on_pushButton_2_clicked()
{
    hide();
    AgencyMember am;
    am.setModal(true);
    am.exec();
}

void MakeNew::on_pushButton_3_clicked()
{
    hide();
    GuideMember gm;
    gm.setModal(true);
    gm.exec();
}
