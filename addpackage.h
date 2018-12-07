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

private:
    Ui::addPackage *ui;
};

#endif // ADDPACKAGE_H
