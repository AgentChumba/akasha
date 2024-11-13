#ifndef REGISTRATIONWIDGET_H
#define REGISTRATIONWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class RegistrationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RegistrationWidget(QWidget *parent = nullptr);

signals:
    void switchToLogin();

private:
    QPushButton *registerButton;
    QPushButton *switchToLoginButton;
    QLineEdit *usernameField;
    QLineEdit *passwordField;
};

#endif // REGISTRATIONWIDGET_H
