import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    anchors.fill: parent

    ItemDelegate {
        text: qsTr("Список людей")
        width: parent.width
        onClicked: {
            stackView.push("ShowPeoples.qml")
            drawer.close()
        }
    }
    ItemDelegate {
        text: qsTr("Добавить человека")
        width: parent.width
        onClicked: {
            stackView.push("AddPeople.qml")
            drawer.close()
        }
    }
}
