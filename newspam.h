#ifndef NEWSPAM_H
#define NEWSPAM_H

#include <QDialog>

namespace Ui {
class NewSpam;
}

class NewSpam : public QDialog
{
    Q_OBJECT

public:
    explicit NewSpam(QWidget *parent = nullptr);
    ~NewSpam();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewSpam *ui;
};

#endif // NEWSPAM_H
