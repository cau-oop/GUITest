#ifndef GUIDEMAIN_H
#define GUIDEMAIN_H

#include <QDialog>

namespace Ui {
class GuideMain;
}

class GuideMain : public QDialog
{
    Q_OBJECT

public:
    explicit GuideMain(QWidget *parent = nullptr);
    ~GuideMain();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::GuideMain *ui;
};

#endif // GUIDEMAIN_H
