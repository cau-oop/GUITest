#ifndef AGENCYMEMBER_H
#define AGENCYMEMBER_H

#include <QDialog>

namespace Ui {
class AgencyMember;
}

class AgencyMember : public QDialog
{
    Q_OBJECT

public:
    explicit AgencyMember(QWidget *parent = nullptr);
    ~AgencyMember();

    static int addUserInfo(char * input_ID, const char * input_PWD, const char * input_name, const char * input_agencyName,
                            const char * input_phoneNumber, const char * input_LicenseNumber, const char * input_mainCountry, const char * input_mainRegion);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AgencyMember *ui;
};

#endif // AGENCYMEMBER_H
