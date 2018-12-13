#ifndef ADTOPAY_H
#define ADTOPAY_H

#include <QDialog>

namespace Ui {
class adtopay;
}

class adtopay : public QDialog
{
    Q_OBJECT

public:
    explicit adtopay(QWidget *parent = nullptr);
    ~adtopay();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adtopay *ui;
};

#endif // ADTOPAY_H
