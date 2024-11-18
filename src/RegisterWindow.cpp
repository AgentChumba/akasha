#include "../include/RegisterWindow.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

RegisterWindow::RegisterWindow(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void RegisterWindow::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Создаём заголовок
    QLabel *titleLabel = new QLabel("Register", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    // Поля ввода
    QLineEdit *usernameField = new QLineEdit(this);
    usernameField->setPlaceholderText("Username");
    usernameField->setMinimumHeight(40);

    QLineEdit *passwordField = new QLineEdit(this);
    passwordField->setPlaceholderText("Password");
    passwordField->setEchoMode(QLineEdit::Password);
    passwordField->setMinimumHeight(40);

    QLineEdit *confirmPasswordField = new QLineEdit(this);
    confirmPasswordField->setPlaceholderText("Confirm Password");
    confirmPasswordField->setEchoMode(QLineEdit::Password);
    confirmPasswordField->setMinimumHeight(40);

    QPushButton *registerButton = new QPushButton("Register", this);
    registerButton->setMinimumHeight(40);

    // Отделительная линия
    QFrame *separator = new QFrame(this);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);

    // Кнопки сторонних сервисов
    QPushButton *discordButton = new QPushButton("Register via Discord", this);
    QPushButton *hoyoButton = new QPushButton("Login via HoYoLab", this);

    layout->addWidget(titleLabel);
    layout->addSpacing(20);
    layout->addWidget(usernameField);
    layout->addWidget(passwordField);
    layout->addWidget(confirmPasswordField);
    layout->addWidget(registerButton);
    layout->addWidget(separator);
    layout->addWidget(discordButton);
    layout->addWidget(hoyoButton);

    layout->addStretch(); // Добавляем пространство для гибкости

    setLayout(layout);

    // Логика кнопок
    connect(registerButton, &QPushButton::clicked, [this, usernameField, passwordField, confirmPasswordField]() {
        if (usernameField->text().isEmpty() || passwordField->text().isEmpty() || confirmPasswordField->text().isEmpty()) {
            qDebug("Fields cannot be empty!");
        } else if (passwordField->text() != confirmPasswordField->text()) {
            qDebug("Passwords do not match!");
        } else {
            qDebug("Registration Successful");
        }
    });

    connect(discordButton, &QPushButton::clicked, []() {
        qDebug("Register via Discord selected.");
    });

    connect(hoyoButton, &QPushButton::clicked, []() {
        qDebug("Login via HoYoLab selected.");
    });
}
