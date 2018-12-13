#include "newspam.h"
#include "ui_newspam.h"
#include "memberinfo.h"
//스팸수신여부 재설정
extern QString spam;
NewSpam::NewSpam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSpam)
{
    ui->setupUi(this);
}

NewSpam::~NewSpam()
{
    delete ui;
}

void NewSpam::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        spam = "Y";
        ui->label_2->setText("");
        hide();
        memberInfo memb;
        memb.setModal(true);
        memb.exec();
    }
    else if(ui->radioButton_2->isChecked())
    {
        spam = "N";
        ui->label_2->setText("");
        hide();
        memberInfo memb;
        memb.setModal(true);
        memb.exec();
    }
    else {
        ui->label_2->setText("항목을 선택해주세요.");
    }

}
