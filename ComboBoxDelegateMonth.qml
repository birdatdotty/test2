import QtQuick 2.12
import QtQuick.Controls 2.12

ItemDelegate {
    property var combobox
    width: combobox.width
    Text {
        anchors.centerIn: parent
        color: testDate() ? "black" : "grey"

        text: txt
    }
    highlighted: combobox.currentIndex
    enabled: testDate()
    onClicked: cbDay.currentIndex = 0

    function testDate() {
        if (minDateYear < comboBoxDayModel.year) return true;
        if (minDateMonth < num) return true;

        if (minDateYear == comboBoxDayModel.year)
            if (minDateMonth <= num) return true;

        return false;
    }
}
