#define _CRT_SECURE_NO_WARNINGS
#include "login.h"
#include "ui_login.h"
#include "guestmain.h"
#include "makenew.h"
#include <io.h>
#include <string.h>
#include "loginfail.h"
#include "loginfail2.h"
#include "QFile"
#include "QTextStream"
#include <QDebug>
#include "agencymain.h"
#include "guidemain.h"

#include "searchresult.h"
QString pw;
QString isPremium;
QString name ;
QString gender;
QString birth;
QString tele;
QString spam;
QString country;
QString city;
QString UserID;
QString agencyName;
QString license;
QString type;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    //abc 로그인
/*
    User us;
    us.GetInfo();
    QString str = QString::fromUtf8(us.password.c_str());
    ui->label_7->setText(str);
  hide();
*/
    QFile *file = new QFile;
     QString filename = "C:\\build-Test-Desktop_Qt_5_11_3_MinGW_32bit-Debug\\beflylee.txt";
      file->setFileName(filename);
      file->open(QIODevice::ReadOnly);
      QTextStream read(file);
      QString tm = read.readLine();
      QStringList tmpl = tm.split(",");

      pw = tmpl[0];
      isPremium = tmpl[1];
      name = tmpl[2];
      gender = tmpl[3];
      birth = tmpl[4];
      tele = tmpl[5];
      spam = tmpl[6];
      country = tmpl[7];
      city = tmpl[8];
      UserID = "beflylee";
         file->close();
         hide();
         GuestMain gm;
         gm.setModal(true);
         gm.exec();

}

void Login::on_pushButton_clicked()
{
    //여행자 로그인
        QString id = ui->lineEdit->text();
        QString pwd = ui->lineEdit_2->text();

        QByteArray bytePWD = pwd.toLocal8Bit();
        char * pwd_c = bytePWD.data();

        int success = this->checkIsUser(1, id, pwd_c);

        //아이디가 잘못되었으면
        if(success == 0){
            LoginFail lf;
            lf.setModal(true);
            lf.exec();

        }

        //비밀번호가 잘못되었으면
        else if(success == -1){
            LoginFail2 lf2;
            lf2.setModal(true);
            lf2.exec();

            ui->lineEdit_2->setText("");

        }

        //로그인 성공하면
        else{
           QFile *file1 = new QFile;
            QString filename = "C:\\build-Test-Desktop_Qt_5_11_3_MinGW_32bit-Debug\\"+id+".txt";
            file1->setFileName(filename);
            file1->open(QIODevice::ReadOnly);
            QTextStream read(file1);
            QString tm = read.readLine();
            QStringList tmpl = tm.split(",");
            pw = tmpl[0];
            isPremium = tmpl[1];
            name = tmpl[2];
            gender = tmpl[3];
            birth = tmpl[4];
            tele = tmpl[5];
            spam = tmpl[6];
            country = tmpl[7];
            city = tmpl[8];
            UserID = id;
            file1->close();
            type = "일반 회원";
            hide();
            GuestMain gm;
            gm.setModal(true);
            gm.exec();
      }
}

void Login::on_pushButton_3_clicked()
{
    //여행사 로그인
       QString id = ui->lineEdit->text();
       QString pwd = ui->lineEdit_2->text();

       QByteArray bytePWD = pwd.toLocal8Bit();
       char * pwd_c = bytePWD.data();

       int success;
       // 아이디가 잘못되었으면 0. 비밀번호가 잘못되었으면 -1. 모두 올바르면 1
       success = Login::checkIsUser(2, id, pwd_c);

       //아이디가 잘못되었으면
       if(success == 0){
           LoginFail lf;
           lf.setModal(true);
           lf.exec();

       }

       //비밀번호가 잘못되었으면
       else if(success == -1){
           LoginFail2 lf2;
           lf2.setModal(true);
           lf2.exec();

           ui->lineEdit_2->setText("");

       }

       //로그인 성공하면
       else if(success == 1){
           QFile *file = new QFile;
           QString filename = "C:\\build-Test-Desktop_Qt_5_11_3_MinGW_32bit-Debug\\"+id+".txt";
           file->setFileName(filename);
           file->open(QIODevice::ReadOnly);
           QTextStream read(file);
           QString tm = read.readLine();
           QStringList tmpl = tm.split(",");
           pw = tmpl[0];
           name = tmpl[1];
           agencyName = tmpl[2];
           tele = tmpl[3];
           license = tmpl[4];
           country = tmpl[5];
           city = tmpl[6];
           UserID = id;
           hide();
           AgencyMain am;
           am.setModal(true);
           am.exec();
       }
}

void Login::on_pushButton_4_clicked()
{
    //가이드 로그인
        QString id = ui->lineEdit->text();
        QString pwd = ui->lineEdit_2->text();

        QByteArray bytePWD = pwd.toLocal8Bit();
        char * pwd_c = bytePWD.data();

        int success;
        // 아이디가 잘못되었으면 0. 비밀번호가 잘못되었으면 -1. 모두 올바르면 1
        success = Login::checkIsUser(3, id, pwd_c);

        //아이디가 잘못되었으면
        if(success == 0){
            LoginFail lf;
            lf.setModal(true);
            lf.exec();

        }

        //비밀번호가 잘못되었으면
        else if(success == -1){
            LoginFail2 lf2;
            lf2.setModal(true);
            lf2.exec();

            ui->lineEdit_2->setText("");

        }

        //로그인 성공하면
        else{
            QFile *file = new QFile;
            QString filename = "C:\\build-Test-Desktop_Qt_5_11_3_MinGW_32bit-Debug\\"+id+".txt";
            file->setFileName(filename);
            file->open(QIODevice::ReadOnly);
            QTextStream read(file);
            QString tm = read.readLine();
            QStringList tmpl = tm.split(",");
            pw = tmpl[0];
            name = tmpl[1];
            tele = tmpl[2];
            license = tmpl[3];
            country = tmpl[4];
            city = tmpl[5];
            UserID = id;
            type = "가이드";
            hide();
            GuideMain gm;
            gm.setModal(true);
            gm.exec();
        }

}

void Login::on_pushButton_5_clicked()
{   //회원가입
    hide();
    MakeNew mn;
    mn.setModal(true);
    mn.exec();
}

void Login::on_pushButton_6_clicked()
{   //가이드로그인 치트
    hide();
    AgencyMain am;
    am.setModal(true);
    am.exec();

}
int Login::checkIsUser(int optionNum, QString input_ID, char * input_PWD) {
        char * user_PWD = (char*)malloc(sizeof(char)*51);
        QString fileName;
//        const char * fileName_c;
        int exist;
        FILE * reader_UserInfo;
        QString fileLocation = "C:\\build-Test-Desktop_Qt_5_11_3_MinGW_32bit-Debug\\";
        int i=0;
        char * temp;
//        QString input_ID_S(input_ID);

        switch (optionNum)
        {

        // 일반 회원으로 로그인 시
        case 1:
            fileLocation = fileLocation + input_ID;
            qDebug() << fileLocation;
            fileName = fileLocation + ".txt";
            qDebug() << fileName;
            break;

        // 1인 여행사로 로그인 시
        case 2:
            fileLocation = fileLocation + input_ID;
            fileName = fileLocation + ".txt";
            break;

        // 가이드로 로그인 시
        case 3:
            fileLocation = fileLocation + input_ID;
            fileName = fileLocation + ".txt";
            break;

        default:
            break;
        }

        QByteArray byteFile = fileName.toLocal8Bit();
        char * filename = byteFile.data();

        qDebug() << filename;
        exist = _access(filename, 0); // 존재하면 exist : 0, 존재하지 않으면 exist : -1.
        qDebug() << exist;
        // 해당 아이디 파일(input_ID.txt)이 존재하면
        if (exist==0) {
            reader_UserInfo = fopen(filename, "r");
            qDebug() << reader_UserInfo;
            fgets(user_PWD, 51, reader_UserInfo);
            qDebug() << QString(user_PWD);
            temp = strtok(user_PWD,",");
            i++;
            strcpy(user_PWD,temp);
            qDebug() << QString(user_PWD);
            while (temp != nullptr) {
                temp = strtok(nullptr, ",");
                i++;
            }
            user_PWD[strlen(user_PWD)]='\0';
            qDebug() << i;
            // 여행자 인지 확인
            if(i==9){
                if(optionNum != 1)
                    return 0;
            }

            if(i==8){
                if(optionNum != 2)
                    return 0;
            }

            if(i==7){
                if(optionNum != 3)
                    return 0;
            }

            fclose(reader_UserInfo);

            qDebug() << QString(user_PWD);
            qDebug() << QString(input_PWD);
            input_PWD[strlen(input_PWD)]='\0';
            // 파일로부터 읽어들인 user_PWD에서 띄어쓰기 문자 제거.
//            user_PWD[strlen(user_PWD) - 1] = '\0';

            if (QString(user_PWD)!=QString(input_PWD)) {
                qDebug() << "test";
                return -1;
            }

            else
                return 1;
        }

        // 해당 아이디 파일(input_ID.txt)이 존재하지 않으면
        else if(exist == -1) {
            printf("아이디가 잘못되었습니다.\n");
            return 0;
        }

}

void Login::on_pushButton_7_clicked()
{
    hide();
    searchresult sresult;
    sresult.setModal(true);
    sresult.exec();
}
