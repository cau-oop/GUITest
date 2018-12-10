#ifndef SEARCHPACKAGE_H
#define SEARCHPACKAGE_H
#define _CRT_SECURE_NO_WARNINGS
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

namespace Ui {
class searchpackage;
}

class searchpackage : public QDialog
{
    Q_OBJECT

public:
    explicit searchpackage(QWidget *parent = nullptr);
    ~searchpackage();
    QString comparedata[8];
    vector<string> v;
    int searchmin, searchmax, searchppl;
    int findpackagecount = 0;
    int buypacknumber = 0; //상품번호
    int buynum; //입력받을 상품번호
    int condition[100] = { 0, };

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_priceslider_valueChanged(int value);

    void on_searchbut_clicked();


private:
    Ui::searchpackage *ui;
};

#endif // SEARCHPACKAGE_H
