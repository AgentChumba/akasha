#include "../include/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    stackedWidget = new QStackedWidget(this);
    loginWidget = new LoginWidget(this);
    registrationWidget = new RegistrationWidget(this);

    // Добавляем виджеты в QStackedWidget
    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(registrationWidget);
    setCentralWidget(stackedWidget);

    // Связываем переключения
    connect(loginWidget, &LoginWidget::switchToRegistration, this, &MainWindow::showRegistration);
    connect(registrationWidget, &RegistrationWidget::switchToLogin, this, &MainWindow::showLogin);

    // Начальное окно - логин
    showLogin();
}

void MainWindow::showLogin()
{
    stackedWidget->setCurrentWidget(loginWidget);
}

void MainWindow::showRegistration()
{
    stackedWidget->setCurrentWidget(registrationWidget);
}
