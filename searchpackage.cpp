#include "searchpackage.h"
#include "ui_searchpackage.h"
#include "searchresult.h"
#include "guestmain.h"

QString searchpackage::result[100];
searchpackage::searchpackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchpackage)
{
    ui->setupUi(this);
    ui->via_combox->addItem("Yes");
    ui->via_combox->addItem("No");
    ui->trav_combox->addItem("Yes");
    ui->trav_combox->addItem("No");
    QPixmap pix("C:/Image/search.jpg");
    ui->label_9->setPixmap(pix.scaled(450,150, Qt::KeepAspectRatio));

}

searchpackage::~searchpackage()
{
    delete ui;
}


void searchpackage::on_priceslider_valueChanged(int value)
{
    ui->pricelabel->setText(QString("%1").arg(value));

}
void searchpackage::on_priceslider_2_valueChanged(int value)
{
    ui->pricelabel_2->setText(QString("%1").arg(value));
}

void searchpackage::on_searchbut_clicked()
{

            QFile spack("C:/GUITest/packagelist.txt");
            if(!spack.open(QIODevice::ReadOnly|QFile::Text))
            {
                if(!spack.exists())
                {
                    qDebug()<<QString("notfound");
                }
            }
            QTextStream OF(&spack);
            while(!OF.atEnd())
            {
                qv.push_back(OF.readLine());
            }
            for (int i = 0; i < qv.size(); i++)
            {
                char *str_buff = new char[1000];
                char *str_buff2 = new char[1000];
                char *str_buff3 = new char[1000];
                size_t findloc = 1, findmin = 1, findmax = 1, finddate = 1, findvia = 1, findfree = 1, findppl = 1, findtag=1, tagtrue =1;
                int pricetrue = 0, ppltrue = 0;
                int str_cnt = 0;
                char *tok = NULL;
                char *tok2 = NULL;
                char *tok3 = NULL;
                char *tok4 = NULL;
                char *tok5 = NULL;
                QString str_arr[1000];
                QString str_arr2[100];

if(ui->asklocation->isChecked())
{
        comparedata[0] = ui->ansloc->text();
        qDebug()<<comparedata[0];
        findloc = qv[i].contains(comparedata[0]);
}
if(ui->askminp->isChecked() || ui->askmaxp->isChecked())
{
    qDebug()<<QString("option2");
    comparedata[1] =QString::fromUtf8( "가격 >> ");
    comparedata[2] =QString::fromUtf8( "가격 >> ");
    if(ui->askminp->isChecked())
        searchmin = ui->priceslider->value();
    if(ui->askmaxp->isChecked())
        searchmax = ui->priceslider_2->value();
    findmin = qv[i].contains(comparedata[1]);
    findmax = qv[i].contains(comparedata[2]);

    if ((findmin != size_t(-1)) || (findmax != size_t(-1)))
    {
        strcpy(str_buff, qv[i].toStdString().c_str());
        tok = strtok(str_buff, "||");
        while (tok != nullptr)
        {
            str_arr[str_cnt++] = QString(tok);
            tok = strtok(nullptr, "||");
        }

        char *comp = new char[1000];
        strcpy(comp, str_arr[4].toStdString().c_str());
        tok2 = strtok(comp, ">>");
        str_arr2[0] = QString(tok2);
        tok2 = strtok(nullptr, ">>"); //가격 저장
        int convertstr = atoi(tok2);
        if (ui->askminp->isChecked())
        {
            if (ui->askmaxp->isChecked())
            {
                if (convertstr >= searchmin && convertstr <= searchmax)
                {
                    pricetrue = 1;
                }
            }
            else
            {
                if (convertstr >= searchmin)
                {
                    pricetrue = 1;
                }
            }

        }
        else if (ui->askmaxp->isChecked())
        {
            if (convertstr <= searchmax)
            {
                pricetrue = 1;
            }
        }
        free(comp);
    }
}

if(ui->askdate->isChecked())
{
    qDebug()<<QString("option4");

    QString adate = (ui->dateEdit->date()).toString("yyyyMMdd");
    comparedata[3] = QString::fromUtf8("출발일 >>") +adate;
    finddate = qv[i].contains(comparedata[3]);
}
if(ui->askvia->isChecked())
{
    qDebug()<<QString("option5");

    QString viatmp = QString::number(ui->via_combox->currentIndex());
    comparedata[4] =QString::fromUtf8( "경유 >>")+ viatmp;
    findvia = qv[i].contains(comparedata[4]);
}
if(ui->askfree->isChecked())
{
    qDebug()<<QString("option6");

    QString freetmp = QString::number(ui->trav_combox->currentIndex());
    comparedata[5] =QString::fromUtf8( "자유여행 >>")+freetmp;
    findfree = qv[i].contains(comparedata[5]);
}
if(ui->askppl->isChecked())
{
    qDebug()<<QString("option7");

    comparedata[6] = QString::fromUtf8("인원 >>");
    searchppl = ui->adultspin->value() + ui->childspin->value() + ui->under->value();
    tok = NULL;
                    findppl = qv[i].contains(comparedata[6]);
                    if (findppl != size_t(-1))
                    {
                        strcpy(str_buff2, qv[i].toStdString().c_str());
                        str_cnt = 0;
                        tok = strtok(str_buff2, "||");
                        while (tok != nullptr)
                        {
                            str_arr[str_cnt++] = QString(tok);
                            tok = strtok(nullptr, "||");
                        }

                        char *comp2 = new char[1000];
                        strcpy(comp2, str_arr[10].toStdString().c_str());
                        tok3 = strtok(comp2, ">>");
                        str_arr2[0] = QString(tok3);
                        tok3 = strtok(nullptr, ">>"); //최소인원 저장
                        int convertpplmin = atoi(tok3); //int 변환

                        strcpy(comp2, str_arr[11].toStdString().c_str());
                        tok4 = strtok(comp2, ">>");
                        str_arr2[0] = QString(tok4);
                        tok4 = strtok(nullptr, ">>"); //최대인원 저장
                        int convertpplmax = atoi(tok4); //int 변환

                        if (convertpplmin <= searchppl && convertpplmax >= searchppl)
                        {
                            ppltrue = 1;
                        }
                        free(comp2);
                        }
}
if(ui->asktag->isChecked())
{
    qDebug()<<QString("option8");

    comparedata[7] = QString::fromUtf8("태그(띄어쓰기 없이) >>");
    tagtrue = qv[i].contains(comparedata[7]);
    if(tagtrue != size_t(-1))
    {
        strcpy(str_buff3, qv[i].toStdString().c_str());
        str_cnt=0;
        tok = strtok(str_buff3, "||");
        while(tok !=nullptr)
        {
               str_arr[str_cnt++] = QString(tok);
               tok = strtok(nullptr, "||");
        }
        char *comp3 = new char[1000];
        strcpy(comp3, str_arr[3].toStdString().c_str());
        tok5 = strtok(comp3, ">>");
        str_arr2[0] = QString(tok5);
        tok5 = strtok(nullptr, ">>");
        QString tagfinder = tok5;
        findtag = tagfinder.contains(ui->tagline->text());
        free(comp3);
    }
}
if ((findloc != false) && (findmin != false) && (findmax != false) && (finddate != false) && (findvia != false) && (findfree != false) && (findppl != false) && (findtag != false))
            {

                if (ui->askminp->isChecked() || ui->askmaxp->isChecked())
                {
                    if (ui->askppl->isChecked())
                    {
                        if (ppltrue == 1 && pricetrue == 1)
                        {
                            qDebug() << QString("found");
                            result[i] = QString::fromUtf8("상품 : ") + qv[i];
                            qDebug() << result[i];



                        }
                    }
                    else
                    {
                        if (pricetrue == 1)
                        {
                            qDebug() << QString("found");
                            result[i] = QString::fromUtf8("상품 : ") + qv[i];
                            qDebug() << result[i];


                        }

                    }
                }
                else if (ui->askppl->isChecked())
                {
                    if (ppltrue == 1)
                    {
                        qDebug() << QString("found");
                        result[i] = QString::fromUtf8("상품 : ") + qv[i];
                        qDebug() << result[i];


                    }

                }
                else
                {
                    qDebug() << QString("found");
                    result[i] = QString::fromUtf8("상품 : ") + qv[i];
                    qDebug() << result[i];


                }

            }


            free(str_buff);
            free(str_buff2);
        }


            hide();

            searchresult sresult;
            sresult.setModal(true);
            sresult.exec();
}


void searchpackage::on_pushButton_2_clicked()
{
    close();
    GuestMain gm;
    gm.setModal(true);
    gm.exec();
}
