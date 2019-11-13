import QtQuick 2.13
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import StyledControls 1.0
import StyledDialogs 1.0
import Utils 1.0
import Core 1.0

ApplicationWindow {
    id: root
    visible: true

    HeaderToolBar {
        id: _headerToolBar
        width: parent.width
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Component.onCompleted: {
        if( Utils.isMobile ) {

        }
        else {
            Utils.centeredWindow(root, Utils.dp(1024), Utils.dp(768));
        }
    }
}
