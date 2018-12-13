#ifndef AGENCYINFO_H
#define AGENCYINFO_H

#include <QDialog>

namespace Ui {
class AgencyInfo;
}

class AgencyInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AgencyInfo(QWidget *parent = nullptr);
    ~AgencyInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AgencyInfo *ui;
};

#endif // AGENCYINFO_H
