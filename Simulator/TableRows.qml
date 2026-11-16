import QtQuick
import QtQuick.Layouts

RowLayout {
    id: main
    required property int address
    required property string content
    property bool isfocused: false

    spacing: 0

    Rectangle {
        height: 20
        Layout.fillWidth: true
        Layout.preferredWidth: 1
        color: main.isfocused ? "green" : "white"
        border.color: "black"
        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
            color: main.isfocused ? "white" : "black"
            text: main.address
            font.pixelSize: 12
        }
    }

    Rectangle {
        height: 20
        Layout.fillWidth: true
        Layout.preferredWidth: 3
        color: main.isfocused ? "green" : "white"
        border.color: "black"

        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
            color: main.isfocused ? "white" : "black"
            text: main.content
            font.pixelSize: 12
        }
    }
}