import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Test2 1.0

RowLayout {
    property alias result: comboBoxDayModel.result
    property alias label: title.text
    property bool active: false

    signal mySignalSelectDay()

    readonly property alias cb: comboBoxDayModel

    function arYear () {
        var ret = []
        for (var i = config.startYear; i <= new Date().getFullYear(); i++) {
            ret.push(i);
        }

        return ret;
    }

    ComboBoxDayModel {
        id: comboBoxDayModel
        year: year.currentIndex + config.startYear
        month: month.currentIndex + 1
        day: day.currentIndex ? day.currentIndex + 1 : 1
        active: chActive.checked

        onResultChanged: mySignalSelectDay()
    }

    CheckBox {
        id: chActive
        enabled: parent.active
        checked: !parent.active
    }


    Label {
        id: title
        Layout.minimumWidth: 120
        Layout.maximumWidth: 120
    }

    Row {
        ComboBox {
            enabled: comboBoxDayModel.active

            id: year
            model: arYear();
            currentIndex: config.startIndexYear
            onCurrentIndexChanged: day.currentIndex = 0
        }
        ComboBox {
            enabled: comboBoxDayModel.active

            id: month
            model: months
            textRole: "txt"
//            valueRole: "num"
            currentIndex: 1
            onCurrentIndexChanged: day.currentIndex = 0
        }
        ComboBox {
            enabled: comboBoxDayModel.active

            id: day
            model: comboBoxDayModel
            textRole: "num"
//            valueRole: "txt"
            onCountChanged: currentIndex = comboBoxDayModel.updateDay(currentIndex + 1) - 1;
        }

    }

}
