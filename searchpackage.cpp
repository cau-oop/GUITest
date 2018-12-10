#include "searchpackage.h"
#include "ui_searchpackage.h"

searchpackage::searchpackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchpackage)
{
    ui->setupUi(this);
    ui->via_combox->addItem("Yes");
    ui->via_combox->addItem("No");
    ui->trav_combox->addItem("Yes");
    ui->trav_combox->addItem("No");
}

searchpackage::~searchpackage()
{
    delete ui;
}


void searchpackage::on_priceslider_valueChanged(int value)
{
    ui->pricelabel->setText(QString("%1").arg(value));

}
void fileRead(ifstream& spack, vector<string>& v)
    {
        string line;

        while (getline(spack, line))
            v.push_back(line);

    }

void searchpackage::on_searchbut_clicked()
{
    ifstream spack;
            spack.open("packagelist.txt");
            fileRead(spack, v);
            for (size_t i = 0; i < v.size(); i++)
            {
                char *str_buff = new char[1000];
                char *str_buff2 = new char[1000];
                char *str_buff3 = new char[1000];
                size_t findloc = 0, findmin = 0, findmax = 0, finddate = 0, findvia = 0, findfree = 0, findppl = 0, findtag=0, tagtrue =0;
                int pricetrue = 0, ppltrue = 0;
                int str_cnt = 0;
                char *tok = NULL;
                char *tok2 = NULL;
                char *tok3 = NULL;
                char *tok4 = NULL;
                char *tok5 = NULL;
                string str_arr[1000];
                string str_arr2[100];
    if(ui->asklocation->isChecked())
    {
        comparedata[0] = ui->ansloc->text();
        findloc = v[i].find(comparedata[0].toStdString());
    }
if(ui->askminp->isChecked() || ui->askmaxp->isChecked())
{
    comparedata[1] = "가격 >> ";
    comparedata[2] = "가격 >> ";
    if(ui->askminp->isChecked())
        searchmin = ui->pricelabel->text().toInt();
    if(ui->askmaxp->isChecked())
        searchmax = ui->pricelabel_2->text().toInt();
    findmin = v[i].find(comparedata[1].toStdString());
    findmax = v[i].find(comparedata[2].toStdString());

    if ((findmin != size_t(-1)) || (findmax != size_t(-1)))
    {
        strcpy(str_buff, v[i].c_str());
        tok = strtok(str_buff, "||");
        while (tok != nullptr)
        {
            str_arr[str_cnt++] = string(tok);
            tok = strtok(nullptr, "||");
        }

        char *comp = new char[1000];
        strcpy(comp, str_arr[4].c_str());
        tok2 = strtok(comp, ">>");
        str_arr2[0] = string(tok2);
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
    QString adate = (ui->dateEdit->date()).toString();
    QStringList adate_tmp = adate.split("-");
    QString adate2 = adate_tmp.join("");
    comparedata[3] = "출발일 >>" +adate2;
}
if(ui->askvia->isChecked())
{
    QString viatmp = QString::number(ui->via_combox->currentIndex());
    comparedata[4] = "경유 >>"+ viatmp;
}
if(ui->askfree->isChecked())
{
    QString freetmp = QString::number(ui->trav_combox->currentIndex());
    comparedata[5] = "자유여행 >>"+freetmp;

}
if(ui->askppl->isChecked())
{
    comparedata[6] = "인원 >>";
    searchppl = ui->adultspin->value() + ui->childspin->value() + ui->under->value();
    tok = NULL;
                    findppl = v[i].find(comparedata[6].toStdString());
                    if (findppl != size_t(-1))
                    {
                        strcpy(str_buff2, v[i].c_str());
                        str_cnt = 0;
                        tok = strtok(str_buff2, "||");
                        while (tok != nullptr)
                        {
                            str_arr[str_cnt++] = string(tok);
                            tok = strtok(nullptr, "||");
                        }

                        char *comp2 = new char[1000];
                        strcpy(comp2, str_arr[10].c_str());
                        tok3 = strtok(comp2, ">>");
                        str_arr2[0] = string(tok3);
                        tok3 = strtok(nullptr, ">>"); //최소인원 저장
                        int convertpplmin = atoi(tok3); //int 변환

                        strcpy(comp2, str_arr[11].c_str());
                        tok4 = strtok(comp2, ">>");
                        str_arr2[0] = string(tok4);
                        tok4 = strtok(nullptr, ">>"); //최대인원 저장
                        int convertpplmax = atoi(tok4); //int 변환

                        if (convertpplmin <= searchppl && convertpplmax >= searchppl)
                        {
                            ppltrue = 1;
                        }
                        free(comp2);
}
if(ui->asktag->isChecked())
{
    comparedata[7] = ui->tagline->text();
    findtag = v[i].find(comparedata[7].toStdString());
    if(findtag != size_t(-1))
    {
        strcpy(str_buff3, v[i].c_str());
        str_cnt=0;
        tok = strtok(str_buff3, "||");
        while(tok !=nullptr)
        {
               str_arr[str_cnt++] = string(tok);
               tok = strtok(nullptr, "||");
        }
        char *comp3 = new char[1000];
        strcpy(comp3, str_arr[3].c_str());
        tok5 = strtok(comp3, ">>");
        str_arr2[0] = string(tok5);
        tok5 = strtok(nullptr, ">>");
        string tagfinder = tok5;
        tagtrue = tagfinder.find(ui->tagline->text().toStdString());
        free(comp3);
    }
}
if ((findloc != size_t(-1)) && (findmin != size_t(-1)) && (findmax != size_t(-1)) && (finddate != size_t(-1)) && (findvia != size_t(-1)) && (findfree != size_t(-1)) && (findppl != size_t(-1)))
            {
                if (ui->askminp->isChecked() || ui->askmaxp->isChecked())
                {
                    if (ui->askppl->isChecked())
                    {
                        if (ppltrue == 1 && pricetrue == 1)
                        {
                            cout << "상품 : " << buypacknumber << "-> " << v[i] << endl;
                            findpackagecount++;
                            buypacknumber++;
                            condition[i] = 1;
                        }
                    }
                    else
                    {
                        if (pricetrue == 1)
                        {
                            cout << "상품 : " << buypacknumber << "-> " << v[i] << endl;
                            findpackagecount++;
                            buypacknumber++;
                            condition[i] = 1;
                        }

                    }
                }
                else if (ui->askppl->isChecked())
                {
                    if (ppltrue == 1)
                    {
                        cout << "상품 : " << buypacknumber << "-> " << v[i] << endl;
                        findpackagecount++;
                        buypacknumber++;
                        condition[i] = 1;

                    }

                }
                else
                {
                    cout << "상품 : " << buypacknumber << "-> " << v[i] << endl;
                    findpackagecount++;
                    buypacknumber++;
                    condition[i] = 1;

                }

            }


            free(str_buff);
            free(str_buff2);
        }

}

}



