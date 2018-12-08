#ifndef SEARCHPACKAGE_H
#define SEARCHPACKAGE_H

#include <QDialog>

namespace Ui {
class searchpackage;
}

class searchpackage : public QDialog
{
    Q_OBJECT

public:
    explicit searchpackage(QWidget *parent = nullptr);
    ~searchpackage();

private:
    Ui::searchpackage *ui;
};

#endif // SEARCHPACKAGE_H
