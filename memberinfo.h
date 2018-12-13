#ifndef MEMBERINFO_H
#define MEMBERINFO_H

#include <QDialog>

namespace Ui {
class memberInfo;
}

class memberInfo : public QDialog
{
    Q_OBJECT

public:
    explicit memberInfo(QWidget *parent = nullptr);
    ~memberInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::memberInfo *ui;
};

#endif // MEMBERINFO_H
