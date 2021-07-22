import QtQuick 2.12
import QtQuick.Controls 2.12

ItemDelegate {
    property var combobox
    width: combobox.width
    Text {
        anchors.centerIn: parent
        color: testDate() ? "black" : "grey"

        text: num
    }
    highlighted: combobox.currentIndex
    enabled: testDate()

    function testDate() {
        if (minDateYear > num) return false;

        return true;
    }
}
