#ifndef PASSWORDCHECK_H
#define PASSWORDCHECK_H

#include <QDialog>

namespace Ui {
class PasswordCheck;
}

class PasswordCheck : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordCheck(QWidget *parent = nullptr);
    ~PasswordCheck();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PasswordCheck *ui;
};

#endif // PASSWORDCHECK_H
