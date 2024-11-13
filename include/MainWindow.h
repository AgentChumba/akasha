#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "LoginWidget.h"
#include "RegistrationWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QStackedWidget *stackedWidget;
    LoginWidget *loginWidget;
    RegistrationWidget *registrationWidget;

private slots:
    void showLogin();
    void showRegistration();
};

#endif // MAINWINDOW_H
