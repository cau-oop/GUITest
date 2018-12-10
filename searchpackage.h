#ifndef SEARCHPACKAGE_H
#define SEARCHPACKAGE_H

#include <QDialog>

namespace Ui {
class searchpackage;
}

class searchpackage : public QDialog
{
    Q_OBJECT

public:
    explicit searchpackage(QWidget *parent = nullptr);
    ~searchpackage();
    QString comparedata[7];

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_priceslider_valueChanged(int value);

    void on_searchbut_clicked();

private:
    Ui::searchpackage *ui;
};

#endif // SEARCHPACKAGE_H
