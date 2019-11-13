import QtQuick 2.13
import QtQuick.Controls 2.12
import StyledControls 1.0
import StyledDialogs 1.0
import Utils 1.0
import Core 1.0

ToolBar {
    id: root
    opacity: 0.85

    ToolButton {
        id: _toolButtonMenu
        anchors.right: parent.right
        icon.source: "images/menu_2.png"
        onClicked: _menu.open()
    }

    Menu {
        id: _menu
        x: root.width - width

        MenuItem {
            text: qsTr("About")
            icon.source: "images/info.png"
            onClicked: _dialogAbout.open()
        }

        MenuSeparator { }

        MenuItem {
            text: qsTr("Exit")
            icon.source: "images/shutdown.png"
            onClicked: Qt.quit()
        }
    }

    StyledAboutDialog {
        id: _dialogAbout
        visible: false
        applicationVersion: Core.applicationVersion
        applicationBuildDate: Core.applicationBuildDate
    }
}
