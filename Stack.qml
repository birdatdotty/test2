import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Drawer {
        id: drawer
        width: parent.width * 0.66
        height: parent.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    stackView.push("ShowPeoples.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    stackView.push("AddPeople.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "First.qml"
        anchors.fill: parent
    }

}
