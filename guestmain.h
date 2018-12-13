#ifndef GUESTMAIN_H
#define GUESTMAIN_H

#include <QDialog>
#include <QString>

namespace Ui {
class GuestMain;
}

class GuestMain : public QDialog
{
    Q_OBJECT

public:
    explicit GuestMain(QWidget *parent = nullptr);
    ~GuestMain();
    void setId();
    int randomxm;
    QString adline;
    int numLines =0;
    int findline =0;
    QString line;
    QString savead;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_adbut_clicked();

private:
    Ui::GuestMain *ui;
};

#endif // GUESTMAIN_H
