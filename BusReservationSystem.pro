QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Reservation.cpp \
    Seat.cpp \
    Transaction.cpp \
    busreservation.cpp \
    main.cpp \
    mainwindow.cpp \
    passenger.cpp

HEADERS += \
    Reservation.h \
    Seat.h \
    Transaction.h \
    busreservation.h \
    mainwindow.h \
    passenger.h

FORMS += \
    Reservation.ui \
    Seat.ui \
    Transaction.ui \
    mainwindow.ui \
    passenger.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
