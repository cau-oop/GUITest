#ifndef GENERALMEMBER_H
#define GENERALMEMBER_H

#include <QDialog>

namespace Ui {
class GeneralMember;
}

class GeneralMember : public QDialog
{
    Q_OBJECT

public:
    explicit GeneralMember(QWidget *parent = nullptr);
    ~GeneralMember();

    static int addUserInfo(char * input_ID, const char * input_PWD, const bool input_isPremium, const char * input_name, const char * input_gender,
            const char * input_birth, const char * input_phoneNumber, const char * input_advertiseAcceptOrNot,
            const char * input_interestCountry, const char * input_interestRegion);

private slots:
    void on_pushButton_clicked();

private:
    Ui::GeneralMember *ui;
};

#endif // GENERALMEMBER_H
