#ifndef PAY_H
#define PAY_H

#include <QDialog>

namespace Ui {
class Pay;
}

class Pay : public QDialog
{
    Q_OBJECT

public:
    explicit Pay(QWidget *parent = nullptr);
    ~Pay();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Pay *ui;
};

#endif // PAY_H
