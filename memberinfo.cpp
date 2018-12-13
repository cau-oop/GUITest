    #include "memberinfo.h"
#include "ui_memberinfo.h"
#include "passwordcheck.h"
#include "newphone.h"
#include "newspam.h"
#include "guestmypage.h"
#include "QFile"
#include "QTextStream"
extern QString pw;
extern QString name;
extern QString isPremium;
extern QString gender;
extern QString birth;
extern QString tele;
extern QString spam;
extern QString country;
extern QString city;
extern QString UserID;
//여행자가 수정할 개인정보를 선택하는 창
memberInfo::memberInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberInfo)
{
    ui->setupUi(this);
}

memberInfo::~memberInfo()
{
    delete ui;
}

void memberInfo::on_pushButton_clicked()
{
    hide();
    PasswordCheck pass;
    pass.setModal(true);
    pass.exec();

}

void memberInfo::on_pushButton_2_clicked()
{
    hide();
    NewPhone np;
    np.setModal(true);
    np.exec();
}

void memberInfo::on_pushButton_3_clicked()
{
    hide();
    NewSpam ns;
    ns.setModal(true);
    ns.exec();
}

void memberInfo::on_pushButton_4_clicked()
{

}

void memberInfo::on_pushButton_5_clicked()
{

}

void memberInfo::on_pushButton_6_clicked()
{
    hide();
    GuestMyPage gmp;
    gmp.setModal(true);
    gmp.exec();
}

void memberInfo::on_pushButton_7_clicked()
{
    QFile *file = new QFile;
    QString filename = "C:\\build-Test-Desktop_Qt_5_11_3_MinGW_32bit-Debug\\beflylee.txt";
      file->setFileName(filename);
      file->open(QIODevice::WriteOnly);

    QTextStream write(file);
    write<<pw<<",";
    write<<isPremium<<",";
    write<<name<<",";
    write<<gender<<",";
    write<<birth<<",";
    write<<tele<<",";
    write<<spam<<",";
    write<<country<<",";
    write<<city;

      file->close();
}
