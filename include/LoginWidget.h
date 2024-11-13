#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    void retranslateUi();           // Смена локали

signals:
    void switchToReg();             // Для перехода к регистрации
    void loginSuccessful();         // Успешный логин

private:
    QLineEdit *usernameField;       // Поля
    QLineEdit *passwordField;

    QCheckBox *rememberCheckBox;    // Галочка

    QPushButton *loginButton;       // "Войти"
    QPushButton *loginLikeGuest;    // "Войти как гость"
    QPushButton *loginViaDiscord;   // "Войти через Discord"
    QPushButton *loginViaHoYoLab;   // "Войти через HoYoLab"
    QPushButton *regButton;         // "Регистрация"

    QFrame *line1;                  // Разделители
    QFrame *line2;
        
private slots:
    void attemptLogin();            // Метод для попытки логина
};

#endif // LOGINWIDGET_H
