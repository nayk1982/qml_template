#===================================================================================================
#
# QML Template Project
#
#===================================================================================================

QT += quick quickcontrols2

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

# Sources and Headers ==============================================================================

INCLUDEPATH += \
    $${PWD}/include \
    $${PWD}/../../_include

SOURCES += \
    $${PWD}/../../_include/app_core.cpp \
    $${PWD}/../../_include/gui_app_core.cpp \
    $${PWD}/../../_include/filesys.cpp \
    $${PWD}/include/core.cpp \
    main.cpp

HEADERS += \
    $${PWD}/../../_include/app_core.h \
    $${PWD}/../../_include/gui_app_core.h \
    $${PWD}/../../_include/filesys.h \
    $${PWD}/../../_include/images_const.h \
    $${PWD}/include/core.h

# Resources files ==================================================================================

RESOURCES += \
    main.qrc \
    $${PWD}/qml/qml.qrc \
    $${PWD}/../../_qml/qml_resources.qrc

win32:RC_FILE = main.rc

# Additional import path used to resolve QML modules in Qt Creator's code model ====================

QML_IMPORT_PATH += \
    $${PWD}/qml/ \
    $${PWD}/../../_qml/

# Additional import path used to resolve QML modules just for Qt Quick Designer ====================

QML_DESIGNER_IMPORT_PATH += \
    $${PWD}/qml/ \
    $${PWD}/../../_qml/

# Output dir =======================================================================================

CONFIG(release, debug|release) {
    win32: DESTDIR = $${PWD}/../_distrib/win_$${QMAKE_HOST.arch}
    else: unix:!android: DESTDIR  = $${PWD}/../_distrib/linux_$${QMAKE_HOST.arch}
}

# Version and Build date ===========================================================================
win32: BUILD_DATE = '$(shell echo %DATE:~6,4%-%DATE:~3,2%-%DATE:~0,2%)'
else:  BUILD_DATE = '$(shell date +%Y-%m-%d)'
VERSION  = 1.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += APP_BUILD_DATE=\\\"$$BUILD_DATE\\\"

# translations =====================================================================================
#TRANSLATIONS += $${PWD}/translations/main_ru.ts
#main_tr.commands = lrelease $${PWD}/translations/main_ru.ts -qm $${PWD}/translations/main_ru.qm
#PRE_TARGETDEPS += main_tr
#QMAKE_EXTRA_TARGETS += main_tr
