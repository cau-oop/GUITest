#include "packagereview.h"
#include "ui_packagereview.h"
#include "guestmypage.h"
#include "QFile"
#include "QTextStream"
extern QString UserID;
PackageReview::PackageReview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PackageReview)
{
    ui->setupUi(this);
    ui->label_2->setText(UserID);
}

PackageReview::~PackageReview()
{
    delete ui;
}

void PackageReview::on_pushButton_clicked()
{
    QString rev = ui->lineEdit->text();
    QString packnum = ui->lineEdit_2->text();
    QFile *file = new QFile;
    QString filename = "C:\\GUITest\\"+packnum+".review.txt";
      file->setFileName(filename);
      file->open(QIODevice::Append|QIODevice::Text);
    QTextStream write(file);
    write<<""<<endl;
    write<<rev<<"--"<<UserID;

      file->close();
      hide();
      GuestMyPage gmp;
      gmp.setModal(true);
      gmp.exec();
}
