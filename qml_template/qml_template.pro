#===============================================================================
#
# QML Template Project
#
#===============================================================================

include( $${PWD}/../../_nayk/qml_app.pri )

# Sources and Headers ==========================================================

INCLUDEPATH += \
    $${PWD}/include \

SOURCES += \
    $${PWD}/include/core.cpp \
    main.cpp

HEADERS += \
    $${PWD}/include/core.h

# Resources files ==============================================================

RESOURCES += \
    main.qrc \
    $${PWD}/qml/qml.qrc

win32:RC_FILE = main.rc

# Additional import path used to resolve QML modules in Qt Creator's code model

QML_IMPORT_PATH += \
    $${PWD}/qml/

# Additional import path used to resolve QML modules just for Qt Quick Designer

QML_DESIGNER_IMPORT_PATH += \
    $${PWD}/qml/

# Output dir ===================================================================

CONFIG(release, debug|release) {
    win32: DESTDIR = $${PWD}/../_distrib/win_$${QMAKE_HOST.arch}
    else: unix:!android: DESTDIR  = $${PWD}/../_distrib/linux_$${QMAKE_HOST.arch}
}

# translations =================================================================
#TRANSLATIONS += $${PWD}/translations/main_ru.ts
#main_tr.commands = lrelease $${PWD}/translations/main_ru.ts -qm $${PWD}/translations/main_ru.qm
#PRE_TARGETDEPS += main_tr
#QMAKE_EXTRA_TARGETS += main_tr
