#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QDialog>
#include <QLabel>
#include "searchpackage.h"
#include "addpackage.h"

extern int PID;

namespace Ui {
class searchresult;
}

class searchresult : public QDialog
{
    Q_OBJECT

public:
    explicit searchresult(QWidget *parent = nullptr);
    ~searchresult();

private:
    Ui::searchresult *ui;
};

#endif // SEARCHRESULT_H
