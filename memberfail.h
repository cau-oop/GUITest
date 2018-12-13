#ifndef MEMBERFAIL_H
#define MEMBERFAIL_H

#include <QDialog>

namespace Ui {
class MemberFail;
}

class MemberFail : public QDialog
{
    Q_OBJECT

public:
    explicit MemberFail(QWidget *parent = nullptr);
    ~MemberFail();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MemberFail *ui;
};

#endif // MEMBERFAIL_H
