#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTranslator>
#include <QComboBox>
#include <QApplication>

#include "LoginWidget.h"
#include "RegistrationWidget.h"
#include "HomeWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QStackedWidget *stackedWidget;          // Виджет для переключения между экранами
    LoginWidget *loginWidget;               // Экран логина
    RegistrationWidget *registrationWidget; // Экран регистрации
    HomeWidget *homeWidget;                 // Домашний экран после успешного входа

    QComboBox *languageComboBox;            // Выпадающее меню языка
    QTranslator translator;                 // Переводчик для смены языка
    QString currentLanguage;                // Текущий код языка

private slots:
    void showLogin();                                   // Отображение экрана логина
    void showRegistration();                            // Отображение экрана регистрации
    void showHome();                                    // Отображение домашнего экрана
    void switchLanguage(const QString &languageCode);   // Переключение языка
};

#endif // MAINWINDOW_H
