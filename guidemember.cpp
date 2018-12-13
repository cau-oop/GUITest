#include "guidemember.h"
#include "ui_guidemember.h"
#include <io.h>
#include "memberfail.h"
#include "memberfail2.h"
#include "login.h"

GuideMember::GuideMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuideMember)
{
    ui->setupUi(this);
}

GuideMember::~GuideMember()
{
    delete ui;
}

void GuideMember::on_pushButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString pwd = ui->lineEdit_3->text();
    QString name = ui->lineEdit_4->text();
    QString agencyName = ui->lineEdit_6->text();
    QString tele = ui->lineEdit_7->text();
    QString license = ui->lineEdit_8->text();
    QString country = ui->lineEdit_9->text();

    QByteArray byteID = id.toLocal8Bit();
    char * ID = byteID.data();
    int success; // 0이면 실패. 1이면 성공.
    success = GuideMember::addUserInfo(ID, pwd.toStdString().c_str(), name.toStdString().c_str(), agencyName.toStdString().c_str(),
                tele.toStdString().c_str(), license.toStdString().c_str(), country.toStdString().c_str());

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
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_6->setText("");
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

int GuideMember::addUserInfo(char * input_ID, const char * input_PWD, const char * input_name, const char * input_phoneNumber,
        const char * input_LicenseNumber, const char * input_mainCountry, const char * input_mainRegion) {

        const char *fileName = strcat(input_ID, ".txt");
        FILE * writer_UserInfo;

        // 각 요소들을 한 줄에 한 요소가 오도록 저장.

        // 해당 ID 파일 존재하면 회원가입 불가.
        int exist = _access(fileName, 0); // 존재하면 exist : 0, 존재하지 않으면 exist : -1.

        if(exist == 0){
            return 0;
        }

        if(!strcmp(input_ID,"")||!strcmp(input_PWD,"")||!strcmp(input_name, "")||!strcmp(input_phoneNumber, "")||
                        !strcmp(input_LicenseNumber, "")||!strcmp(input_mainCountry, "")||!strcmp(input_mainRegion, ""))
        {
            return -1;
        }

        // pwd 저장.
        writer_UserInfo = fopen(fileName, "w");
        fputs(input_PWD, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // 사업자 이름 저장.
        fputs(input_name, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // phone number 저장.
        fputs(input_phoneNumber, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // 가이드 자격증 번호 저장.
        fputs(input_LicenseNumber, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // 전담 나라 저장.
        fputs(input_mainCountry, writer_UserInfo);
        fputs(",", writer_UserInfo);

        // 전담 도시(또는 유명 지역 이름 또는 유명 명소) 저장.
        fputs(input_mainRegion, writer_UserInfo);
        fclose(writer_UserInfo);
        return 1;
}
