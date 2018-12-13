#ifndef AGENCYMAIN_H
#define AGENCYMAIN_H

#include <QDialog>

namespace Ui {
class AgencyMain;
}

class AgencyMain : public QDialog
{
    Q_OBJECT

public:
    explicit AgencyMain(QWidget *parent = nullptr);
    ~AgencyMain();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::AgencyMain *ui;
};

#endif // AGENCYMAIN_H
