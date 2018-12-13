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
#include <vector>
#include <QTextCodec>
#include <QDebug>
#include <QString>
#include <QVector>
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
    int condition[100] = { 0, };
    static QString result[100];
    QVector<QString> qv;

private slots:

     void on_priceslider_valueChanged(int value);

    void on_searchbut_clicked();


    void on_priceslider_2_valueChanged(int value);

private:
    Ui::searchpackage *ui;
};

#endif // SEARCHPACKAGE_H
