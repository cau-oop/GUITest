#include "addpackage.h"
#include "ui_addpackage.h"
#include "agencymain.h"


addPackage::addPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPackage)
{

    ui->setupUi(this);
    ui->packagename->setVisible(false);
    ui->location->setVisible(false);
    ui->tag->setVisible(false);
    ui->price->setVisible(false);
    ui->via->setVisible(false);
    ui->trav_start_date->setVisible(false);
    ui->trav_start_hour->setVisible(false);
    ui->free_trav->setVisible(false);
    ui->how_long_trav->setVisible(false);
    ui->minppl->setVisible(false);
    ui->maxppl->setVisible(false);
    ui->finish->setVisible(false);
    ui->loc_combo->addItems(QStringList()<<"대한민국" << "중국" << "일본" << "태국" << "필리핀" << "베트남" << "말레이시아" << "라오스" << "미얀마" << "싱가포르" << "서남아" << "대만" << "홍콩" << "괌" << "호주" << "뉴질랜드" << "서유럽" << "동유럽" << "지중해" << "러시아" << "북유럽" << "발틱" << "아프리카" << "중동");
    ui->via_combox->addItem("Yes");
    ui->via_combox->addItem("No");
    ui->trav_combo->addItem("Yes");
    ui->trav_combo->addItem("No");
    ReadFile();
    ui->PID_LCD->display(PID);

 }

void addPackage::on_name_button_clicked()
{
    Pname[PID] = ui->name_line->text();
    clicked[0] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}



void addPackage::on_loc_button_clicked()
{

    location[PID] = ui->loc_combo->currentText();
    clicked[1] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

void addPackage::on_tag_button_2_clicked()
{

    tag[PID] = ui->tag_line->text();
    clicked[2] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

void addPackage::on_price_button_2_clicked()
{
    price[PID] = ui->price_line->text().toInt();
    clicked[3] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

void addPackage::on_via_button_2_clicked()
{
    via[PID] = ui->via_combox->currentIndex();
    clicked[4] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

void addPackage::on_date_button_clicked()
{
    //calendarwidget , dateeidt
    QString ddate = (ui->dateEdit->date()).toString("yyyyMMdd");
    trav_start_date[PID] =ddate.toInt();
    clicked[5] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

void addPackage::on_start_button_clicked()
{
    //timeEdit
    QString ttime = (ui->timeEdit->time()).toString("hh:mm");
    QStringList time_tmp = ttime.split(":");
    QString timesave = time_tmp.join("");
    trav_start_hour[PID] = timesave.toInt();
    clicked[6] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

void addPackage::on_trav_button_clicked()
{
    free_trav[PID] = ui->trav_combo->currentIndex();
    clicked[7] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}


void addPackage::on_how_long_button_clicked()
{
    how_long_trav[PID]  = ui->how_long_line->text().toInt();
    clicked[8] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

void addPackage::on_min_button_clicked()
{
    minppl[PID] =  ui->min_spin->value();
    clicked[9] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

void addPackage::on_max_button_clicked()
{
    maxppl[PID] = ui->max_spinbox->value();
    clicked[10] = 1;
    if((clicked[0]==1)&&(clicked[1]==1)&&(clicked[2]==1)&&(clicked[3]==1)&&(clicked[4]==1)&&(clicked[5]==1)&&(clicked[6]==1)&&(clicked[7]==1)&&(clicked[8]==1)&&(clicked[9]==1)&&(clicked[10]==1))
         ui->finish->setVisible(true);
}

addPackage::~addPackage()
{
    delete ui;
}



void addPackage::ReadFile()
{
    QFile file("C:/GUITest/packagelist.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream OpenFile(&file);
    QString ConfigText;
    QString search;
    QString tmp;
while(!OpenFile.atEnd())
{
    tmp = QString::number(PID);
    search = "PID >>" + tmp;
    ConfigText=OpenFile.readLine();
    if((ConfigText.contains(search)))
       {
           PID++;
       }
}

}

void addPackage::on_finish_clicked()
{
    QTextCodec *codec = QTextCodec::codecForLocale();
       QString str, str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str11, str12;
       QFile file("C:/GUITest/packagelist.txt");
       file.open(QFile::Append | QFile::Text);
       QTextStream os(&file);
       str ="PID >>";
       str1 = " || 패키지 >>";
       str2 =" || 지역 >>";
       str3 =" || 태그(띄어쓰기 없이) >>";
       str4 = " || 가격 >> ";
       str5 = " || 경유 >>";
       str6 =  " || 출발일 >>";
       str7 = " || 출발시간 >>";
       str8 = " || 여행기간 >>";
       str9 =  " || 자유여행 >>";
       str10 = " || 최소인원 >> ";
       str11 = " || 최대인원 >> ";
       str = codec->toUnicode(str.toLocal8Bit());
       str1 = codec->toUnicode(str1.toLocal8Bit());
       str2 = codec->toUnicode(str2.toLocal8Bit());
       str3 = codec->toUnicode(str3.toLocal8Bit());
       str4 = codec->toUnicode(str4.toLocal8Bit());
       str5 = codec->toUnicode(str5.toLocal8Bit());
       str6 = codec->toUnicode(str6.toLocal8Bit());
       str7 = codec->toUnicode(str7.toLocal8Bit());
       str8 = codec->toUnicode(str8.toLocal8Bit());
       str9 = codec->toUnicode(str9.toLocal8Bit());
       str10 = codec->toUnicode(str10.toLocal8Bit());
       str11 = codec->toUnicode(str11.toLocal8Bit());
       os<<""<<endl;
       os << str << PID;
       os << str1 << Pname[PID];
       os << str2 << location[PID];
       os << str3 << tag[PID];
       os << str4 << price[PID];
       os << str5  << via[PID];
       os << str6 << trav_start_date[PID];
       os << str7 << trav_start_hour[PID];
       os << str8 << how_long_trav[PID];
       os << str9 << free_trav[PID];
       os << str10 << minppl[PID];
       os << str11 << maxppl[PID];
    QString pidtmp;
    pidtmp = QString::number(PID);
    QString rankfile = "C:/GUITest/"+pidtmp+".rank.txt";
    QFile addfile(rankfile);
    addfile.open(QIODevice::WriteOnly);
    QTextStream rank(&addfile);
    rank << "0,0";
    QString reviewfile = "C:/GUITest/"+pidtmp+".review.txt";
    QFile addfile2(reviewfile);
    addfile2.open(QIODevice::WriteOnly);
    QTextStream review(&addfile2);
    str12 = "리뷰목록";
    str12= codec->toUnicode((str12.toLocal8Bit()));
    review << str12 <<endl;
    hide();
    AgencyMain am;
    am.setModal(true);
    am.exec();
}


