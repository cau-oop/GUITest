#include "searchresult.h"
#include "ui_searchresult.h"

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
    int k=0;

    int c=0;

    for(int i=0; i<cot; i++)
    {
        searchresult::label_array[i] = new QLabel(QString::fromUtf8("상품 %1").arg(c+1));
        label_array[i]->setText(spack.result[i]);
        label_array[i]->setWordWrap(true);
        ui->tabWidget->widget(i)->layout()->addWidget(searchresult::label_array[i]);
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
