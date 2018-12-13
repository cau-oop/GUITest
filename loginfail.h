#ifndef LOGINFAIL_H
#define LOGINFAIL_H

#include <QDialog>

namespace Ui {
class LoginFail;
}

class LoginFail : public QDialog
{
    Q_OBJECT

public:
    explicit LoginFail(QWidget *parent = nullptr);
    ~LoginFail();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginFail *ui;
};

#endif // LOGINFAIL_H
