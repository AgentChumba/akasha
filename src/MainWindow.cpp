#include "../include/MainWindow.h"
#include "../include/LoginWindow.h"
#include "../include/RegisterWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentWidget(nullptr) {
    
    setWindowTitle("A.K.A.S.H.A.");
    setMinimumSize(800, 600);

    showLogin(); // Начинаем с экрана логина
}

MainWindow::~MainWindow() {
    if (currentWidget)
        delete currentWidget;
}

void MainWindow::showLogin() {
    if (currentWidget) {
        delete currentWidget;
    }

    currentWidget = new LoginWindow(this);
    setCentralWidget(currentWidget);
}

void MainWindow::showRegister() {
    if (currentWidget) {
        delete currentWidget;
    }

    currentWidget = new RegisterWindow(this);
    setCentralWidget(currentWidget);
}

void MainWindow::showPlaceholder() {
    if (currentWidget) {
        delete currentWidget;
    }

    QWidget *placeholder = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(placeholder);

    QLabel *label = new QLabel("Welcome to akasha!", placeholder);
    QPushButton *backButton = new QPushButton("Back to Login", placeholder);

    layout->addWidget(label);
    layout->addWidget(backButton);

    connect(backButton, &QPushButton::clicked, this, &MainWindow::showLogin);

    placeholder->setLayout(layout);
    setCentralWidget(placeholder);
}