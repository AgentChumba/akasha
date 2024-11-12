#include "../include/loginWindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(800, 600);
    setWindowTitle("Приветственное окно");

    QLabel *label = new QLabel("Добро пожаловать в наше приложение!", this);
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    
    setLayout(layout);
}

LoginWindow::~LoginWindow() {}
