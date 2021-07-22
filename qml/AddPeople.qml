import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2

import MyMisc 1.0

import Test2 1.0
// https://evileg.com/ru/post/178/

Page {
    padding: 10

    title: "Добавить человека"
    GridLayout {
        anchors.centerIn: parent

        NewPeopleModel {
            id: newPeople
            name: fio.text
            birthday: bd.result
            deathday: dd.result
            sex: sexModel.valueToId(sex.currentText)
            weight: weight.value
            nation: nationsModel.valueToId(nation.currentText)
            age: age.value
            growth: growth.value
        }

        columns: 3
        rows: 5

        // FIO
        RowLayout {
            Layout.column: 0
            Layout.row: 0
            Layout.columnSpan: 3

            anchors.margins: 1

            Label {
                text: "Введите ФИО:"
            }

            TextField {
                Layout.fillWidth: true

                placeholderText: "Введите имя с боьшой буквы и на русском"
                id: fio
                validator: RegExpValidator {
                    regExp: /^[А-Я]{1}[а-я]*[.]?\s[А-Я]{1}[а-я]*[.]?\s[А-Я]{1}[а-я]*[.]?/
                }
                onAccepted: Qt.inputMethod.hide()
            }
        }


        RowLayout {
            Layout.column: 1
            Layout.row: 1
            Layout.columnSpan: 3
            Layout.fillWidth: true

        // sex
        RowLayout {
            Layout.column: 1
            Layout.row: 1
            Layout.fillWidth: true

            anchors.margins: 100

            Label {
                text: "Укажите пол:"
            }


            ComboBox {
                id: sex
                model: sexModel
                onCountChanged: currentIndex = model.updateIndex(currentIndex + 1) - 1
                textRole: "value"
//                valueRole: "id"
            }
        }

        // nation
        RowLayout {
            Layout.column: 2
            Layout.row: 1
            Layout.fillWidth: true

            anchors.margins: 100

            Label {
                text: "Национаьность:"
            }

            ComboBox {
                id: nation
                model: nationsModel
                textRole: "value"
//                valueRole: "id"
                onCountChanged: currentIndex = model.updateIndex(currentIndex + 1) - 1
            }
        }
        }

        // weight
        RowLayout {
            Layout.column: 0
            Layout.row: 2

            anchors.margins: 100

            Label {
                text: "вес:"
            }

            Slider {
                id: weight
                from: 1
                value: 60
                to: 120
                stepSize: 1.0
            }
            Text {
                text: weight.value
            }
        }

        //age
        RowLayout {
            Layout.column: 1
            Layout.row: 2

            anchors.margins: 100

            Label {
                text: "возраст:"
            }

            Slider {
                id: age
                from: 2
                value: 40
                to: 120
                stepSize: 1.0
            }
            Text {
                text: age.value
            }
        }

        //growth
        RowLayout {
            Layout.column: 2
            Layout.row: 2

            anchors.margins: 100

            Label {
                text: "рост:"
            }

            Slider {
                id: growth
                from: 1
                value: 170
                to: 240
                stepSize: 1.0
            }
            Text {
                text: growth.value
            }
        }

        // bithday
        SelectDay {
            id: bd
            label: "день рождения:"
            Layout.row: 3
            Layout.column: 0
            Layout.columnSpan: 2
            Layout.fillWidth: true


            onMySignalSelectDay: dd.updateDate()
        }

        // deathday
        SelectDay2 {
            id: dd
            label: "день смерти:"
            active: true
            Layout.row: 4
            Layout.column: 0
            Layout.columnSpan: 2
            Layout.fillWidth: true


            minDateYear: bd.cb.year
            minDateMonth: bd.cb.month
            minDateDay: bd.cb.day
        }

        // write button
        Button {
            Layout.row: 3
            Layout.column: 2
            Layout.rowSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true

            enabled: fio.text.length > 2

            text: "добавить запись"
            onClicked: {
                peopleModel.addNewPeople(newPeople.name, newPeople.sex, newPeople.weight, newPeople.nation, newPeople.birthday, newPeople.deathday, newPeople.age, newPeople.growth)
                newPeopleModel.addNewPeople(newPeople.name, newPeople.sex, newPeople.weight, newPeople.nation, newPeople.birthday, newPeople.deathday, newPeople.age, newPeople.growth)
                stackView.pop()
            }

        }

    }

}
