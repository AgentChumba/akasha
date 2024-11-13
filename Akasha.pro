TEMPLATE = app
TARGET = Akasha

CONFIG += c++17

QT += widgets

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/RegistrationWidget.cpp \
    src/LoginWidget.cpp \
    src/HomeWidget.cpp

HEADERS += \
    include/MainWindow.h \
    include/RegistrationWidget.h \
    include/LoginWidget.h \
    include/HomeWidget.h

TRANSLATIONS += locales/akasha_ru.ts \
                locales/akasha_en.ts