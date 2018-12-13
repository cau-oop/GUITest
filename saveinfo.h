#ifndef SAVEINFO_H
#define SAVEINFO_H

#include <QDialog>

namespace Ui {
class SaveInfo;
}

class SaveInfo : public QDialog
{
    Q_OBJECT

public:
    explicit SaveInfo(QWidget *parent = nullptr);
    ~SaveInfo();

private:
    Ui::SaveInfo *ui;
};

#endif // SAVEINFO_H
