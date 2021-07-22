import QtQuick 2.12
import QtQuick.Controls 2.12

ToolBar {
    contentHeight: toolButton.implicitHeight

    ToolButton {
        id: toolButton
        text: stackView.depth > 1 ? "\u25C0" : "\u2630"
        font.pixelSize: Qt.application.font.pixelSize * 1.6
        onClicked: {
            if (stackView.depth > 1) {
                stackView.pop()
            } else {
                drawer.open()
            }
        }
    }


    Label {
        text: stackView.currentItem.title
        anchors.centerIn: parent
    }
    Button {
        text: "сохранить"
        anchors.right: parent.right
        font.bold: true
        enabled: newPeopleModel.needSave
        onReleased: stackView.push("SavePeoples.qml")
    }

}
