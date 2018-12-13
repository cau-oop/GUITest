#ifndef LOGINFAIL2_H
#define LOGINFAIL2_H

#include <QDialog>

namespace Ui {
class LoginFail2;
}

class LoginFail2 : public QDialog
{
    Q_OBJECT

public:
    explicit LoginFail2(QWidget *parent = nullptr);
    ~LoginFail2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginFail2 *ui;
};

#endif // LOGINFAIL2_H
