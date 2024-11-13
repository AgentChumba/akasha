#include "../include/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Создание общего виджета и его частей
    stackedWidget       = new QStackedWidget(this);
    
    loginWidget         = new LoginWidget(this);
    registrationWidget  = new RegistrationWidget(this);
    homeWidget          = new HomeWidget(this);

    // Добавляем виджеты в общий пул
    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(registrationWidget);
    stackedWidget->addWidget(homeWidget);
    setCentralWidget(stackedWidget);

    // Выпадающее меню языка
    languageComboBox = new QComboBox(this);
    languageComboBox->addItem("English", "en");
    languageComboBox->addItem("Русский", "ru");

   // Создаём макет для размещения ComboBox
    QWidget *withCombo = new QWidget(this);
    QVBoxLayout *localeLayout = new QVBoxLayout(withCombo);
    localeLayout->addWidget(stackedWidget);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    bottomLayout->addWidget(languageComboBox);
    localeLayout->addLayout(bottomLayout);

    setCentralWidget(withCombo);

    // Связываем собыытия
    connect(loginWidget, &LoginWidget::switchToReg, this, &MainWindow::showRegistration);
    connect(registrationWidget, &RegistrationWidget::switchToLogin, this, &MainWindow::showLogin);
    connect(loginWidget, &LoginWidget::loginSuccessful, this, &MainWindow::showHome);
    connect(homeWidget, &HomeWidget::logoutRequested, this, &MainWindow::showLogin);

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

void MainWindow::showHome()
{
    stackedWidget->setCurrentWidget(homeWidget);
}

void MainWindow::switchLanguage(const QString &languageCode)
{
    QString qmFilePath = "../locales/akasha_" + languageCode + ".qm";

    if (translator.load(qmFilePath)) {
        qApp->installTranslator(&translator);
        currentLanguage = languageCode;

        // Переводим интерфейс
        loginWidget->retranslateUi();
        registrationWidget->retranslateUi();
        homeWidget->retranslateUi();
        languageComboBox->setItemText(languageComboBox->findData(languageCode), tr("Сменить язык"));
    } else {
        // Warning
    }
}
