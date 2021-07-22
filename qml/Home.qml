import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Page {
    padding: 10
    title: "Гавная"

    Column {
        Label {
            text: qsTr("Выберете нужный разде:")
        }

        Button {
            text: "Сисок людей"
            onClicked: {
                stackView.push("ShowPeoples.qml")
                drawer.close()
            }
        }
        Button {
            text: "Сисок новых людей"
            enabled: newPeopleModel.rowNewCount > 0
            onClicked: {
                stackView.push("SavePeoples.qml")
                drawer.close()
            }
        }

        Button {
            text: "Добавить человека"
            onClicked: {
                stackView.push("AddPeople.qml")
                drawer.close()
            }
        }
        Button {
            text: "Создать структуру SQL"
            onClicked: sql.createStruct()
        }
        Label {
            text: "newPeopleModel.rowNewCount: " + newPeopleModel.rowNewCount
        }
    }
}
