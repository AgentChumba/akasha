#include "../include/RegistrationWidget.h"

RegistrationWidget::RegistrationWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameField = new QLineEdit(this);
    usernameField->setPlaceholderText("login");
    layout->addWidget(usernameField);

    passwordField = new QLineEdit(this);
    passwordField->setPlaceholderText("password");
    passwordField->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordField);

    registerButton = new QPushButton("Регистрация", this);
    layout->addWidget(registerButton);

    switchToLoginButton = new QPushButton("Уже есть аккаунт? Войти", this);
    layout->addWidget(switchToLoginButton);

    connect(switchToLoginButton, &QPushButton::clicked, this, &RegistrationWidget::switchToLogin);
}
