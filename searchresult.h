#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QDialog>
#include <QLabel>
#include <QtWidgets>
#include "addpackage.h"
#include "searchpackage.h"


namespace Ui {
class searchresult;
}

class searchresult : public QDialog
{
    Q_OBJECT

public:
    explicit searchresult(QWidget *parent = nullptr);
    ~searchresult();
    QStringList savefile;
    searchpackage spack;
    void fillArray();
    addPackage aP;
    QLabel *label_array[15];

private slots:
    void on_buy_clicked();

private:
    Ui::searchresult *ui;
};

#endif // SEARCHRESULT_H
