#ifndef NEWPHONE_H
#define NEWPHONE_H

#include <QDialog>

namespace Ui {
class NewPhone;
}

class NewPhone : public QDialog
{
    Q_OBJECT

public:
    explicit NewPhone(QWidget *parent = nullptr);
    ~NewPhone();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewPhone *ui;
};

#endif // NEWPHONE_H
