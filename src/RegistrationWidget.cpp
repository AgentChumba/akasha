#include "../include/RegistrationWidget.h"

RegistrationWidget::RegistrationWidget(QWidget *parent) : QWidget(parent)
{
    //  -   Создание layout и его компонентов   -   -
    QVBoxLayout *layout = new QVBoxLayout(this);

    // usernameField       = new QLineEdit(this);
    // passwordField       = new QLineEdit(this);
    
    // registerButton      = new QPushButton(this);
    loginButton = new QPushButton(tr("Уже есть аккаунт? Войти"), this);

    //  -   -   -   Настройки компонент -   -   -
    // passwordField->setEchoMode(QLineEdit::Password);

    //  -   -   Компановка на layout    -   -
    // layout->addWidget(usernameField);
    // layout->addWidget(passwordField);
    
    // layout->addWidget(registerButton);
    layout->addWidget(loginButton);

    // Сязываем события
    connect(loginButton, &QPushButton::clicked, this, &RegistrationWidget::switchToLogin);
}

void RegistrationWidget::retranslateUi()
{
    //usernameField->setPlaceholderText(tr("Логин"));
    //passwordField->setPlaceholderText(tr("Пароль"));
    //registerButton->setText(tr("Регистрация"));
    loginButton->setText(tr("Уже есть аккаунт? Войти"));
}
