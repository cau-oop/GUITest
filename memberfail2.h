#ifndef MEMBERFAIL2_H
#define MEMBERFAIL2_H

#include <QDialog>

namespace Ui {
class MemberFail2;
}

class MemberFail2 : public QDialog
{
    Q_OBJECT

public:
    explicit MemberFail2(QWidget *parent = nullptr);
    ~MemberFail2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MemberFail2 *ui;
};

#endif // MEMBERFAIL2_H
