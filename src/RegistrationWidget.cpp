#include "../include/RegistrationWidget.h"

RegistrationWidget::RegistrationWidget(QWidget *parent) : QWidget(parent)
{
    //  -   Создание layout и его компонентов   -   -
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameField       = new QLineEdit(this);                                      // Поля
    passField           = new QLineEdit(this);
    passConfirmField    = new QLineEdit(this);
    
    regButton           = new QPushButton(tr("Регистрация"), this);                 // Кнопки
    regViaDiscordButton = new QPushButton(tr("Регистрация через Discord"), this);
    regViaHoYoLabButton = new QPushButton(tr("Регистрация через HoYoLab"), this);
    loginButton         = new QPushButton(tr("Уже есть аккаунт? Войти"), this);

    line1               = new QFrame();                                             // Разделители
    line2               = new QFrame();

    //  -   -   -   Настройки компонент -   -   -
    usernameField->setMaximumSize(200, 40);                                         // Поля
    usernameField->setPlaceholderText(tr("Логин"));
    
    passField->setMaximumSize(200, 40);
    passField->setPlaceholderText(tr("Пароль"));
    passField->setEchoMode(QLineEdit::Password);

    passConfirmField->setMaximumSize(200, 40);
    passConfirmField->setPlaceholderText(tr("Повторите пароль"));
    passConfirmField->setEchoMode(QLineEdit::Password);

    regButton->setMaximumSize(200, 40);                                             // Кнопки
    regViaDiscordButton->setMaximumSize(200, 40);
    regViaHoYoLabButton->setMaximumSize(200, 40);
    loginButton->setMaximumSize(200, 40);
    
    line1->setMaximumSize(200, 40);                                                 // Разделители
    line1->setFrameShape(QFrame::HLine);
    line1->setFrameShadow(QFrame::Sunken);

    line2->setMaximumSize(200, 40);
    line2->setFrameShape(QFrame::HLine);
    line2->setFrameShadow(QFrame::Sunken);

    //  -   -   Компановка на layout    -   -
    layout->addWidget(usernameField);
    layout->addWidget(passField);
    layout->addWidget(passConfirmField);

    layout->addWidget(regButton);
    layout->addWidget(line1);

    layout->addWidget(regViaDiscordButton);
    layout->addWidget(regViaHoYoLabButton);

    layout->addWidget(line2);
    layout->addWidget(loginButton);

    layout->setAlignment(Qt::AlignCenter);

    // Сязываем события
    // reg
    // regD
    // regH
    connect(loginButton, &QPushButton::clicked, this, &RegistrationWidget::switchToLogin);
}

void RegistrationWidget::retranslateUi()
{
    usernameField->setPlaceholderText(tr("Логин"));
    passField->setPlaceholderText(tr("Пароль"));
    passConfirmField->setPlaceholderText(tr("Пароль"));
    
    regButton->setText(tr("Регистрация"));
    regViaDiscordButton->setText(tr("Регистрация через Discord"));
    regViaHoYoLabButton->setText(tr("Регистрация через HoYoLab"));
    loginButton->setText(tr("Уже есть аккаунт? Войти"));
}
