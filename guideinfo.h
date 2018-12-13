#ifndef GUIDEINFO_H
#define GUIDEINFO_H

#include <QDialog>

namespace Ui {
class GuideInfo;
}

class GuideInfo : public QDialog
{
    Q_OBJECT

public:
    explicit GuideInfo(QWidget *parent = nullptr);
    ~GuideInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GuideInfo *ui;
};

#endif // GUIDEINFO_H
