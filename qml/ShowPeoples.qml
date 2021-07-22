import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import MyMisc 1.0

Page {
    property PeopleModel curPeopleModel: peopleModel
    padding: 10

    title: "Список людей"
    ColumnLayout {
        anchors.fill: parent
        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ListView {
                id: listView
                width: parent.width
                model: curPeopleModel

                delegate: UserDelegate{
                    height: 60
                    width: listView.width
                }
            }
        }
    }
}
