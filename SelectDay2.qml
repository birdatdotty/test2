import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Test2 1.0

RowLayout {
    property ListModel items: ListModel {}

    property int minDateYear: 1998
    property int minDateMonth: 3
    property int minDateDay: 8

    property alias result: comboBoxDayModel.result
    property alias label: title.text
    property bool active: true

    Component {
        id: someComponent
        ListModel {
        }
    }

    function updateDate() {
        if (cbYear.currentIndex > minDateYear - config.startYear) return;
        else cbYear.currentIndex = minDateYear - config.startYear;

        if (cbMonth.currentValue > minDateMonth) return;
        else cbMonth.currentIndex = minDateMonth - 1;

        if (cbDay.currentValue > minDateDay) return;
        else cbDay.currentIndex = minDateDay - 1;
    }

    function createModel(parent) {
        var newModel = someComponent.createObject(parent);
        return newModel;
    }
    function arYear () {
        for (var i = config.startYear; i <= new Date().getFullYear(); i++) {
            items.append({"txt": i, "num": i})
        }

        return items;
    }


    ComboBoxDayModel {
        id: comboBoxDayModel
        year: cbYear.currentIndex + config.startYear
        month: cbMonth.currentIndex + 1
        day: cbDay.currentIndex ? cbDay.currentIndex + 1 : 1
        active: chActive.checked
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

            id: cbYear
            model: arYear();
            currentIndex: config.startIndexYear

            textRole: "num"
//            valueRole: "num"

            delegate: ComboBoxDelegateYear{ combobox: cbYear }
        }
        ComboBox {
            enabled: comboBoxDayModel.active

            id: cbMonth
            model: months
            textRole: "txt"
//            valueRole: "num"
            currentIndex: 1

            delegate: ComboBoxDelegateMonth{ combobox: cbMonth }
        }

        ComboBox {
            enabled: comboBoxDayModel.active

            id: cbDay

            currentIndex: 0
            model: comboBoxDayModel

            textRole: "num"
//            valueRole: "txt"

            delegate: ComboBoxDelegateDay{ combobox: cbDay }
        }
    }
}
