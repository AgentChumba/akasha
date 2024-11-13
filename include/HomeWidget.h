#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class HomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = nullptr);
    void retranslateUi();       // Метод для обновления текста элементов интерфейса после смены языка

signals:
    void logoutRequested();     // Сигнал для выхода из аккаунта

private:
    QLabel *welcomeLabel;           // Метка приветствия
    // QPushButton *profileButton;     // Кнопка перехода к профилю
    // QPushButton *tournamentButton;  // Кнопка просмотра турниров
    QPushButton *logoutButton;      // Кнопка выхода из аккаунта
};

#endif // HOMEWIDGET_H
