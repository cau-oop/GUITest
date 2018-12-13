#ifndef GUIDEMEMBER_H
#define GUIDEMEMBER_H

#include <QDialog>

namespace Ui {
class GuideMember;
}

class GuideMember : public QDialog
{
    Q_OBJECT

public:
    explicit GuideMember(QWidget *parent = nullptr);
    ~GuideMember();

    static int addUserInfo(char * input_ID, const char * input_PWD, const char * input_name, const char * input_phoneNumber,
            const char * input_LicenseNumber, const char * input_mainCountry, const char * input_mainRegion);

private slots:
    void on_pushButton_clicked();

private:
    Ui::GuideMember *ui;
};

#endif // GUIDEMEMBER_H
