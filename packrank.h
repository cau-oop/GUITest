#ifndef PACKRANK_H
#define PACKRANK_H

#include <QDialog>

namespace Ui {
class PackRank;
}

class PackRank : public QDialog
{
    Q_OBJECT

public:
    explicit PackRank(QWidget *parent = nullptr);
    ~PackRank();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PackRank *ui;
};

#endif // PACKRANK_H
