#ifndef GUESTMYPAGE_H
#define GUESTMYPAGE_H

#include <QDialog>

namespace Ui {
class GuestMyPage;
}

class GuestMyPage : public QDialog
{
    Q_OBJECT

public:
    explicit GuestMyPage(QWidget *parent = nullptr);
    ~GuestMyPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::GuestMyPage *ui;
};

#endif // GUESTMYPAGE_H
