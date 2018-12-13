#ifndef GUIDERANK_H
#define GUIDERANK_H

#include <QDialog>

namespace Ui {
class GuideRank;
}

class GuideRank : public QDialog
{
    Q_OBJECT

public:
    explicit GuideRank(QWidget *parent = nullptr);
    ~GuideRank();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GuideRank *ui;
};

#endif // GUIDERANK_H
