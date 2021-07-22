import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import MyMisc 1.0

ApplicationWindow {
    id: applicationWindow
    minimumWidth: 960
    minimumHeight: 480
    visible: true
    title: qsTr("Scroll")

    header: Header{}

    MySQLite {
        id: sql
        file: "db.sqlite"

        onConnected: {
            sql.populateComboBox(sexModel, "sex", "id", "txt");
            sql.populateComboBox(nationsModel, "nations", "id", "nation");
            sql.populatePeopleModel(peopleModel)
        }
    }

    Drawer {
        id: drawer
        width: parent.width * 0.66
        height: parent.height

        DrawerColumn {}
    }

    StackView {
        id: stackView
        initialItem: "Home.qml"
        anchors.fill: parent
    }


    ComboBoxModel { id: sexModel }
    ComboBoxModel { id: nationsModel }
    PeopleModel { id: peopleModel }
    PeopleModel { id: newPeopleModel }
    Months { id: months }
    Config { id: config }

    //    ShowPeoples {
    //        anchors.fill: parent
    //    }

    //    AddPeople {
    //        anchors.verticalCenter: parent.verticalCenter
    //        anchors.horizontalCenter: parent.horizontalCenter
    //        anchors.margins: 20
    //    }


}
