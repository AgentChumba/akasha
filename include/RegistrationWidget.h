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
    QLineEdit *usernameField;           // Поля
    QLineEdit *passField;
    QLineEdit *passConfirmField;
    
    QPushButton *regButton;             // Кнопка завершения регистрации
    QPushButton *regViaDiscordButton;   // Регистрация через Discord
    QPushButton *regViaHoYoLabButton;   // Регистрация через HoYoLab
    QPushButton *loginButton;           // Кнопка перехода на экран логина

    QFrame *line1;                  // Разделители
    QFrame *line2;
};

#endif // REGISTRATIONWIDGET_H
