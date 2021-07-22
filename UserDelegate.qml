import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ItemDelegate {

    RowLayout {
        anchors.fill: parent
        Text {
            Layout.minimumWidth: parent.width/2
            color: (sex === 2) ? "#947" : "#339"
            font.bold: true
            text: name
            horizontalAlignment: Text.AlignLeft
            styleColor: "#904072"
            Layout.fillWidth: true
        }

        Column {
            Layout.minimumWidth: parent.width/4
            Text { text: "вес: " + weight }
            Text { text: "возраст: " + age }
            Text { text: "рост: " + growth }
        }
        Column {
            Text {
                text: "национаьность: " + nationsModel.tr(nationality)
            }
            Layout.minimumWidth: parent.width/4
            Text {
                text: "родился: " + birthday
            }
            Text {
                text: death.length > 0 ? "умер: " + death : ""
            }
        }

    }
    MouseArea {
        anchors.fill: parent
    }
}
