#ifndef ADDPACKAGE_H
#define ADDPACKAGE_H

#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>

namespace Ui {
class addPackage;
}

class addPackage : public QDialog
{
    Q_OBJECT

public:
    explicit addPackage(QWidget *parent = nullptr);
    ~addPackage();
        int PID=0;
        QString Pname[100]; //패키지 이름
        QString location[100]; //지역
        QString tag[100]; //해시태그
        int price[100];
        int via[100];

        int trav_start_date[100];
        int trav_start_hour[100];

        int how_long_trav[100];
        int free_trav[100];
        int minppl[100];
        int maxppl[100];
        void ReadFile();
        int clicked[12] = {0,};

private slots:

    void on_name_button_clicked();

    void on_loc_button_clicked();

    void on_tag_button_2_clicked();

    void on_price_button_2_clicked();

    void on_via_button_2_clicked();

    void on_date_button_clicked();

    void on_start_button_clicked();

    void on_trav_button_clicked();

    void on_how_long_button_clicked();

    void on_min_button_clicked();

    void on_max_button_clicked();

    void on_finish_clicked();

private:
    Ui::addPackage *ui;
};

#endif // ADDPACKAGE_H
