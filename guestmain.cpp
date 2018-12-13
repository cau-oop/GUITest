#include "guestmain.h"
#include "ui_guestmain.h"
#include "guestmypage.h"
#include "searchpackage.h"
#include "objectclassfile.h"
#include "adtopay.h"
//여행자가 로그인하였을 때 나타나는 메인화면
GuestMain::GuestMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuestMain)
{


    ui->setupUi(this);
    User us;

    int cnt=0;
    char *buff = new char[1000];
    char *token = NULL;

    QString strarr[100];
    QString strarr2[100];

    QString str = QString::fromUtf8(us.password.c_str());
    ui->label_2->setText(str);
    QPixmap pix("C:/Image/world.png");
    ui->ad_pic->setPixmap(pix.scaled(80,80, Qt::KeepAspectRatio));
    QFile adfile("C:/GUITest/packagelist.txt");
    adfile.open(QIODevice::ReadOnly);
    QTextStream OpenFile(&adfile);
    while(!adfile.atEnd())
    {
        line = adfile.readLine();
        numLines++;
    }
    numLines--;
    randomxm = rand() % numLines;
    adfile.close();
    QFile printad("C:/GUITest/packagelist.txt");
    printad.open(QIODevice::ReadOnly);
    QTextStream read(&printad);
    while(!read.atEnd())
    {
        //QString Config = read.readLine();
        qDebug() << read.readLine();
        if(randomxm == findline)
        {

           strcpy(buff, read.readLine().toStdString().c_str());
           token = strtok(buff, "||");
           while(token != nullptr)
           {
               strarr[cnt++] = QString(token);
               token = strtok(nullptr, "||");
           }
           char*comp = new char[100];
           strcpy(comp, strarr[1].toStdString().c_str());
           QString tempor = comp;
           qDebug() <<QString(strarr[3]);
           QStringList tmp = strarr[3].split(">>");
           QStringList tmp1 = strarr[0].split(">>");
           QString pt = tmp1[1];
           QStringList tmpq = pt.split(" ");
           QString pn = tmpq[0];
           QFile *file = new QFile;
            QString filename = "C:\\GUITest\\"+pn+".rank.txt";
             file->setFileName(filename);
             file->open(QIODevice::ReadOnly);
           QTextStream rea(file);
           QString tmp2 = rea.readLine();
           QStringList tmpk = tmp2.split(",");
           QString point = tmpk[0];
           ui->adbut->setText(tempor+'\n'+tmp[1]+'\n'+" 평점 :"+point);
            file->close();
        }
        findline++;
        savead = read.readLine(randomxm);
    }

   printad.close();

}

GuestMain::~GuestMain()
{
    delete ui;
}
void GuestMain::setId()
{
}
void GuestMain::on_pushButton_clicked()
{
    hide();
    GuestMyPage gmp;
    gmp.setModal(true);
    gmp.exec();
}

void GuestMain::on_pushButton_2_clicked()
{
    hide();
    searchpackage sp;
    sp.setModal(true);
    sp.exec();
}

void GuestMain::on_adbut_clicked()
{
    hide();
    adtopay ap;
    ap.setModal(true);
    ap.exec();
}
