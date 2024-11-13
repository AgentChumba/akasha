#include "../include/LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
    //  -   Создание layout и его компонентов   -   -
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameField       = new QLineEdit(this);
    passwordField       = new QLineEdit(this);
    rememberCheckBox    = new QCheckBox(tr("Запомнить аккаунт"), this);

    loginButton         = new QPushButton(tr("Войти"), this);
    loginLikeGuest      = new QPushButton(tr("Войти как гость"), this);
    loginViaDiscord     = new QPushButton(tr("Войти через Discord"), this);
    loginViaHoYoLab     = new QPushButton(tr("Войти через HoYoLab"), this);
    
    regButton           = new QPushButton(tr("Нет аккаунта? Зарегистрироваться"), this);
    
    line1               = new QFrame();
    line2               = new QFrame();
    
    //  -   -   -   Настройки компонент -   -   -
    usernameField->setMaximumSize(200, 40);             // Поля
    usernameField->setPlaceholderText(tr("Логин"));

    passwordField->setMaximumSize(200, 40);
    passwordField->setPlaceholderText(tr("Пароль"));
    passwordField->setEchoMode(QLineEdit::Password);
    
    loginButton->setMaximumSize(200, 40);               // Кнопки
    loginLikeGuest->setMaximumSize(200, 40);
    loginViaDiscord->setMaximumSize(200, 40);
    loginViaHoYoLab->setMaximumSize(200, 40);
    regButton->setMaximumSize(200, 40);

    line1->setMaximumSize(200, 40);                     // Разделители
    line1->setFrameShape(QFrame::HLine);
    line1->setFrameShadow(QFrame::Sunken);

    line2->setMaximumSize(200, 40);
    line2->setFrameShape(QFrame::HLine);
    line2->setFrameShadow(QFrame::Sunken);

    //  -   -   Компановка на layout    -   -
    layout->addWidget(usernameField);
    layout->addWidget(passwordField);
    layout->addWidget(rememberCheckBox);
    layout->addWidget(loginButton);
    
    layout->addWidget(line1);
    
    layout->addWidget(loginViaHoYoLab);
    layout->addWidget(loginViaDiscord);

    layout->addWidget(line2);

    layout->addWidget(loginLikeGuest);
    layout->addWidget(regButton);

    layout->setAlignment(Qt::AlignCenter);

    // Связываем события
    connect(loginButton, &QPushButton::clicked, this, &LoginWidget::attemptLogin);
    connect(regButton, &QPushButton::clicked, this, &LoginWidget::switchToReg);
}

//  -   -   -   
void LoginWidget::retranslateUi()
{
    usernameField->setPlaceholderText(tr("Логин"));
    passwordField->setPlaceholderText(tr("Пароль"));
    rememberCheckBox->setText(tr("Запомнить аккаунт"));
    loginButton->setText(tr("Войти"));
    loginLikeGuest->setText(tr("Войти как гость"));
    loginViaDiscord->setText(tr("Войти через Discord"));
    loginViaHoYoLab->setText(tr("Войти через HoYoLab"));
    regButton->setText(tr("Нет аккаунта? Зарегистрироваться"));
}

void LoginWidget::attemptLogin()
{
    QString username = usernameField->text();
    QString password = passwordField->text();

    if (!username.isEmpty() && !password.isEmpty()) {
        emit loginSuccessful();
    } else {
        // Показать сообщение об ошибке
    }
}
