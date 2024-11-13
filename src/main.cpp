#include <QApplication>
#include "../include/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;                                     // Создаем объект переводчика
    QString locale = QLocale::system().name();                  // Получаем системный язык

    QString qmFilePath = "locales/akasha_" + locale + ".qm";    // Загружаем перевод    
    if (translator.load(qmFilePath)) {                          // из файла локали
        app.installTranslator(&translator);
    } else {
        // Warning поставить какой-то
        translator.load("locales/akasha_en.qm");
        app.installTranslator(&translator);
    }

    MainWindow mainWindow;                                      // Окно
    mainWindow.setFixedSize(800, 600);                          // шаманских
    mainWindow.show();                                          // утех

    return app.exec();
}
