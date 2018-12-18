#include "searchresult.h"
#include "ui_searchresult.h"
#include "searchpackage.h"

searchresult::searchresult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchresult)
{
    ui->setupUi(this);
    for(int k=0; k<3; k++)
    ui->tabWidget->widget(k)->setLayout(new QVBoxLayout);
    int cot=0;
    qDebug() << QString("find result");
    for(int i=0; i<100;i++)
    {
        if(!spack.result[i].isNull())
        {
        cot++;
        }
    }
    qDebug() << cot;
    int l=0;

    int c=0;
    int k=0;

    for(int i=0; i<100; i++)
    {


        if(!spack.result[i].isNull())
        {
          searchresult::label_array[k] = new QLabel(QString::fromUtf8("상품 %1").arg(c+1));
          label_array[k]->setText(spack.result[i]);
          label_array[k]->setWordWrap(true);
        ui->tabWidget->widget(l)->layout()->addWidget(searchresult::label_array[k]);
        l++;
        k++;
        }

        c++;
   }

}

searchresult::~searchresult()
{
    delete ui;
}

void searchresult::on_buy_clicked()
{

}

void searchresult::on_back_b_clicked()
{
    close();
    searchpackage sp;
    sp.setModal(true);
    sp.exec();
}
