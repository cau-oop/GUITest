#ifndef ADDPACKAGE_H
#define ADDPACKAGE_H

#include <QDialog>

namespace Ui {
class addPackage;
}

class addPackage : public QDialog
{
    Q_OBJECT

public:
    explicit addPackage(QWidget *parent = nullptr);
    ~addPackage();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::addPackage *ui;
};

#endif // ADDPACKAGE_H
