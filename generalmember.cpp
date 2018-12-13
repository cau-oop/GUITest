#include "generalmember.h"
#include "ui_generalmember.h"
#include "login.h"
#include <io.h>
#include "memberfail.h"
#include "login.h"
#include "memberfail2.h"

GeneralMember::GeneralMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneralMember)
{
    ui->setupUi(this);
}

GeneralMember::~GeneralMember()
{
    delete ui;
}

void GeneralMember::on_pushButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString pwd = ui->lineEdit_2->text();
    QString name = ui->lineEdit_3->text();
    QString gender = ui->lineEdit_4->text();
    QString birth = ui->lineEdit_5->text();
    QString tele = ui->lineEdit_6->text();
    QString advertise = ui->lineEdit_7->text();
    QString country = ui->lineEdit_8->text();
    QString region = ui->lineEdit_9->text();

    QByteArray byteID = id.toLocal8Bit();
    char * ID = byteID.data();
    int success; // 0이면 실패. 1이면 성공.
    success = GeneralMember::addUserInfo(ID, pwd.toStdString().c_str(), false, name.toStdString().c_str(), gender.toStdString().c_str(),
                birth.toStdString().c_str(), tele.toStdString().c_str(), advertise.toStdString().c_str(),
                country.toStdString().c_str(), region.toStdString().c_str());

    // 회원가입 실패 시. 0 : 해당 아이디 존재.
    // 회원가입 실패 시. 1 : 성공.
    // 회원가입 실패 시. -1 : 필수 입력 요소 입력 안했음.
    if(success == 0){
        MemberFail mf;
        mf.setModal(true);
        mf.exec();

        ui->lineEdit->setText("");
    }

    else if(success == -1){
        MemberFail2 mf2;
        mf2.setModal(true);
        mf2.exec();

        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");
        ui->lineEdit_9->setText("");
    }

    // 회원가입 성공시
    else if(success == 1){
        close();
        Login lg;
        lg.setModal(true);
        lg.exec();
    }
}

int GeneralMember::addUserInfo(char * input_ID, const char * input_PWD, const bool input_isPremium, const char * input_name, const char * input_gender,
        const char * input_birth, const char * input_phoneNumber, const char * input_advertiseAcceptOrNot,
        const char * input_interestCountry, const char * input_interestRegion) {

        const char *fileName = strcat(input_ID, ".txt");
        FILE * writer_UserInfo;

        // 해당 ID 파일 존재하면 회원가입 불가.
        int exist = _access(fileName, 0); // 존재하면 exist : 0, 존재하지 않으면 exist : -1.

        if(exist == 0){
            return 0;
        }

        if(!strcmp(input_ID,"")||!strcmp(input_PWD,"")||!strcmp(input_name, "")||!strcmp(input_gender, "")||!strcmp(input_birth, "")||
                        !strcmp(input_phoneNumber, "")||!strcmp(input_advertiseAcceptOrNot, "")||!strcmp(input_interestCountry, "")||
             !strcmp(input_interestRegion, ""))
        {
            return -1;
        }

        //각 요소들은 줄바꿈으로 저장.

        // pwd 저장.
        writer_UserInfo = fopen(fileName, "w");
        fputs(input_PWD, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // premium 회원인지 아닌지 저장.(true, false).
        fputs((input_isPremium ? "true" : "false"), writer_UserInfo);
        fputs(",", writer_UserInfo);

        // name 저장.
        fputs(input_name, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // legal gender 저장.
        fputs(input_gender, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // birth 저장.
        fputs(input_birth, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // phone number 저장.
        fputs(input_phoneNumber, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // 광고 수신 여부 저장.
        fputs(input_advertiseAcceptOrNot, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // 관심 나라 저장.
        fputs(input_interestCountry, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // 관심 도시(또는 유명 지역 또는 유명 명소) 저장.
        fputs(input_interestRegion, writer_UserInfo);
        fclose(writer_UserInfo);
        return 1;
}
