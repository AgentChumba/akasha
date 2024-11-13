#include "../include/LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameField = new QLineEdit(this);
    usernameField->setPlaceholderText("login");
    layout->addWidget(usernameField);

    passwordField = new QLineEdit(this);
    passwordField->setPlaceholderText("password");
    passwordField->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordField);

    loginButton = new QPushButton("Войти", this);
    layout->addWidget(loginButton);

    switchToRegButton = new QPushButton("Нет аккаунта? Зарегистрироваться", this);
    layout->addWidget(switchToRegButton);

    connect(switchToRegButton, &QPushButton::clicked, this, &LoginWidget::switchToRegistration);
}
