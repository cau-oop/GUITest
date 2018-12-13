#ifndef MAKENEW_H
#define MAKENEW_H

#include <QDialog>

namespace Ui {
class MakeNew;
}

class MakeNew : public QDialog
{
    Q_OBJECT

public:
    explicit MakeNew(QWidget *parent = nullptr);
    ~MakeNew();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MakeNew *ui;
};

#endif // MAKENEW_H
