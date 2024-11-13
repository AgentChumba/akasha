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

    void retranslateUi();               // Смена локали

signals:
    void switchToLogin();               // Для перехода к логину

private:
    //QLineEdit *usernameField;           // Поле для ввода имени пользователя
    //QLineEdit *passwordField;           // Поле для ввода пароля
    //QPushButton *registerButton;        // Кнопка для завершения регистрации
    QPushButton *loginButton;           // Кнопка для перехода на экран логина
};

#endif // REGISTRATIONWIDGET_H
