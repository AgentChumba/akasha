#include "../include/HomeWidget.h"

HomeWidget::HomeWidget(QWidget *parent) : QWidget(parent)
{
    //  -   Создание layout и его компонентов   -   -
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Тест заглушка
    welcomeLabel = new QLabel(tr("Добро пожаловать в приложение!"));
    
    // profileButton       = new QPushButton(tr("Профиль"));    
    // tournamentButton    = new QPushButton(tr("Турниры"));
    logoutButton        = new QPushButton(tr("Выход из аккаунта"));

    layout->addWidget(welcomeLabel);

    // layout->addWidget(tournamentButton);
    // layout->addWidget(profileButton);
    layout->addWidget(logoutButton);

    // Связыаем события
    connect(logoutButton, &QPushButton::clicked, this, &HomeWidget::logoutRequested);
}

void HomeWidget::retranslateUi()
{
    // profileButton->setText(tr("Профиль"));
    // tournamentButton->setText(tr("Турниры"));
    logoutButton->setText(tr("Выйти"));
}
