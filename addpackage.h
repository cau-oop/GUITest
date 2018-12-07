#ifndef ADDPACKAGE_H
#define ADDPACKAGE_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class addPackage;
}

class addPackage : public QDialog
{
    Q_OBJECT

public:
    explicit addPackage(QWidget *parent = nullptr);
    ~addPackage();
    QString name, location, tag, via;
    int price, vian;

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_name_button_clicked();

    void on_loc_button_clicked();

    void on_loc_combo_currentIndexChanged(int index);

    void on_tag_button_2_clicked();

    void on_price_button_2_clicked();

    void on_via_button_2_clicked();

    void on_date_button_clicked();

private:
    Ui::addPackage *ui;
};

#endif // ADDPACKAGE_H
