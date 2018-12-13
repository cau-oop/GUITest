#ifndef PACKAGEREVIEW_H
#define PACKAGEREVIEW_H

#include <QDialog>

namespace Ui {
class PackageReview;
}

class PackageReview : public QDialog
{
    Q_OBJECT

public:
    explicit PackageReview(QWidget *parent = nullptr);
    ~PackageReview();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PackageReview *ui;
};

#endif // PACKAGEREVIEW_H
