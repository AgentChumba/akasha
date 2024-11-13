#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = nullptr);

signals:
    void switchToRegistration();

private:
    QPushButton *loginButton;
    QPushButton *switchToRegButton;
    QLineEdit *usernameField;
    QLineEdit *passwordField;
};

#endif // LOGINWIDGET_H
