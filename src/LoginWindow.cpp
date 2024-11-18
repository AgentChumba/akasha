#include "../include/LoginWindow.h"
#include "../include/MainWindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
    setupUI();
}

LoginWindow::~LoginWindow() {}

void LoginWindow::setupUI() {
    
    // Layouts
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    QWidget *titleButtons = new QWidget(this);
    QHBoxLayout *tButtonsLayout = new QHBoxLayout(titleButtons);

    QWidget *loginForm = new QWidget(this);
    QVBoxLayout *loginLayout = new QVBoxLayout(loginForm);

    QWidget *loginComponents = new QWidget(this);
    QVBoxLayout *componentsLayout = new QVBoxLayout(loginComponents);

    // Setting Pannel
    settingsPanel = new QWidget(this);
    settingsPanel->setMinimumWidth(280);
    settingsPanel->setStyleSheet("background-color: #333;");
    settingsPanel->hide();

    // Title
    QLabel *titleLabel = new QLabel(tr("Login"), this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    titleLabel->setMinimumSize(100, 20);
    titleLabel->setMaximumSize(200, 40);

    // Fields
    QLineEdit *loginField = new QLineEdit(this);
    loginField->setPlaceholderText(tr("Username"));
    titleLabel->setMinimumSize(100, 20);
    loginField->setMaximumSize(200, 40);

    QLineEdit *passwordField = new QLineEdit(this);
    passwordField->setPlaceholderText(tr("Password"));
    passwordField->setEchoMode(QLineEdit::Password);
    titleLabel->setMinimumSize(100, 20);
    passwordField->setMaximumSize(200, 40);

    //  CheckBox
    QCheckBox *rememberMe = new QCheckBox(tr("Remember Me"), this);
    titleLabel->setMinimumSize(100, 20);
    rememberMe->setMaximumSize(200, 40);

    // Buttons
    QPushButton *settingsButton = new QPushButton(this);
    settingsButton->setIcon(QIcon(":/res/settings.png"));
    titleLabel->setMinimumSize(100, 20);
    settingsButton->setIconSize(QSize(30, 30));

    QPushButton *shutdownButton = new QPushButton(this);
    shutdownButton->setIcon(QIcon(":/res/settings.png"));
    titleLabel->setMinimumSize(100, 20);
    shutdownButton->setIconSize(QSize(30, 30));

    QPushButton *loginButton = new QPushButton(tr("Login"), this);
    titleLabel->setMinimumSize(100, 20);
    loginButton->setMaximumSize(200, 40);

    QPushButton *recoverButton = new QPushButton(tr("Recover Account"), this);
    titleLabel->setMinimumSize(100, 20);
    recoverButton->setMaximumSize(200, 40);

    QPushButton *discordButton = new QPushButton(tr("Login via Discord"), this);
    titleLabel->setMinimumSize(100, 20);
    discordButton->setMaximumSize(200, 40);
    
    QPushButton *hoyoButton = new QPushButton(tr("Login via HoYoLab"), this);
    titleLabel->setMinimumSize(100, 20);
    hoyoButton->setMaximumSize(200, 40);
    
    QPushButton *guestButton = new QPushButton(tr("Continue as Guest"), this);
    titleLabel->setMinimumSize(100, 20);
    guestButton->setMaximumSize(200, 40);

    // Separator
    QFrame *separator = new QFrame(this);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);

    // Layout configuring
    componentsLayout->addStretch();
    componentsLayout->addWidget(titleLabel);
    componentsLayout->addSpacing(20);
    componentsLayout->addWidget(loginField);
    componentsLayout->addWidget(passwordField);
    componentsLayout->addWidget(rememberMe);
    componentsLayout->addWidget(loginButton);
    componentsLayout->addWidget(recoverButton);
    componentsLayout->addWidget(separator);
    componentsLayout->addWidget(discordButton);
    componentsLayout->addWidget(hoyoButton);
    componentsLayout->addWidget(guestButton);
    componentsLayout->addStretch(); // Добавляем пространство для гибкости

    componentsLayout->setAlignment(Qt::AlignCenter);

    tButtonsLayout->addWidget(settingsButton, 0, Qt::AlignLeft | Qt::AlignTop);
    tButtonsLayout->addWidget(shutdownButton, 0, Qt::AlignRight | Qt::AlignTop);

    loginLayout->addWidget(titleButtons);
    loginLayout->addWidget(loginComponents);
    
    mainLayout->addWidget(settingsPanel);
    mainLayout->addWidget(loginForm);

    setLayout(mainLayout);

    // Логика кнопок
    connect(loginButton, &QPushButton::clicked, [this, loginField, passwordField]() {
        if (!loginField->text().isEmpty() && !passwordField->text().isEmpty()) {
            qDebug("Login Successful");
        } else {
            qDebug("Fields cannot be empty!");
        }
    });

    connect(discordButton, &QPushButton::clicked, []() {
        qDebug("Login via Discord selected.");
    });

    connect(hoyoButton, &QPushButton::clicked, []() {
        qDebug("Login via HoYoLab selected.");
    });

    connect(guestButton, &QPushButton::clicked, []() {
        qDebug("Guest login selected.");
    });

    connect(settingsButton, &QPushButton::clicked, this, &LoginWindow::toggleSettingsPanel);
}

void LoginWindow::toggleSettingsPanel() {
    if (settingsPanel->isVisible()) {
        settingsPanel->hide();
    } else {
        settingsPanel->show();
    }
}