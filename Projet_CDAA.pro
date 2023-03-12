QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AfficheContact.cpp \
    Contact.cpp \
    FormContact.cpp \
    FormInteraction.cpp \
    Interaction.cpp \
    ModifContact.cpp \
    RechercheContact.cpp \
    Tache.cpp \
    basedonnee.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AfficheContact.h \
    Contact.h \
    FormContact.h \
    FormInteraction.h \
    Interaction.h \
    ModifContact.h \
    RechercheContact.h \
    Tache.h \
    basedonnee.h \
    mainwindow.h

FORMS += \
    AfficheContact.ui \
    FormContact.ui \
    FormInteraction.ui \
    ModifContact.ui \
    RechercheContact.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
