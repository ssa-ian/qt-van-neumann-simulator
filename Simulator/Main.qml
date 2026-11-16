import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import Simulator

ApplicationWindow {
    id: window
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("Hello World")
    color: "white"

    RowLayout {
        id: mainRow
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom : buttons.top
        anchors.margins: 20
        spacing: 20

        ColumnLayout {
            id: ramColumn
            Layout.fillWidth: true
            Layout.preferredWidth: mainRow.width * 0.5
            Layout.alignment: Qt.AlignTop
            spacing: 0

            Text {
                text: "RAM"
                font.pixelSize: 15
                font.bold: true
                Layout.bottomMargin: 4
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 0

                Rectangle {
                    id: addressRect
                    border.color: "black"
                    height: 20
                    Layout.fillWidth: true
                    Layout.preferredWidth: 1

                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        text: "Address"
                        font.pixelSize: 14
                        font.bold: true
                    }
                }

                Rectangle {
                    id: valueRect
                    border.color: "black"
                    height: 20
                    Layout.fillWidth: true
                    Layout.preferredWidth: 3

                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        text: "Value"
                        font.pixelSize: 14
                        font.bold: true
                    }
                }
            }

            Repeater {
                model: NumberStore.registers
                delegate: TableRows {
                    required property var modelData
                    Layout.fillWidth: true
                    isfocused: modelData.isfocused
                    address: modelData.address
                    content: modelData.value
                }
            }
        }
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: mainRow.width * 0.6

            Text {
                text: "CPU"
                font.pixelSize: 15
                font.bold: true
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredHeight: 2
                border.color: "black"
                border.width: 3

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 15
                    spacing: 10

                    RowLayout {
                        Layout.fillWidth: true
                        Text {
                            text: "Program Counter:"
                            font.pixelSize: 14
                            font.bold: true
                        }
                        Text {
                            text: NumberStore.pcounter
                            font.pixelSize: 14
                        }
                    }

                    RowLayout {
                        Layout.fillWidth: true
                        Text {
                            text: "Instruction Register:"
                            font.pixelSize: 14
                            font.bold: true
                        }
                        Text {
                            text: NumberStore.iregister
                            color : NumberStore.decode ? "red" : "black"
                            font.bold : NumberStore.decode ? true : false
                            font.pixelSize: 14
                        }
                    }

                    RowLayout {
                        Layout.fillWidth: true
                        Text {
                            text: "Accumulator:"
                            font.pixelSize: 14
                            font.bold: true
                        }
                        Text {
                            text: NumberStore.accumulator
                            font.pixelSize: 14
                        }
                    }
                }
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredHeight: 1
                border.color: "black"
                border.width: 3

        Row {
            anchors.centerIn: parent
            spacing: 5

            Text {
                text: "Fetch"
                font.pixelSize: 14
                font.bold: NumberStore.fetch
            }
            Text {
                text: "->"
                font.pixelSize: 14
            }
            Text {
                text: "Decode"
                font.pixelSize: 14
                font.bold: NumberStore.decode
            }
            Text {
                text: "->"
                font.pixelSize: 14
            }
            Text {
                text: "Execute"
                font.pixelSize: 14
                font.bold: NumberStore.execute
            }
        }
    }
}
    }

    Row{
        id: buttons
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin : 20
        anchors.bottomMargin : 20
        spacing : 10
        Button {
            id : resetButton
            width: 80
            height: 50

            onClicked : {
                NumberStore.reset()
            }

            contentItem : Text{
                text: "Reset"
                color : "black"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold : true
                font.pixelSize: 16
            }


            background: Rectangle {
                color: resetButton.pressed ? "#e0e0e0" : (resetButton.hovered ? "#f5f5f5" : "white")
                border.color: "black"
                border.width: 1
            }
        }
        Button {
            id : clockButton
            width: 50
            height: 50

            onClicked : {
                NumberStore.setfdecount()
            }

            contentItem : Text{
                text: "Next"
                color : "black"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold : true
                font.pixelSize: 16
            }


            background: Rectangle {
                color: clockButton.pressed ? "#e0e0e0" : (clockButton.hovered ? "#f5f5f5" : "white")
                border.color: "black"
                border.width: 1
            }
        }
        /*
        Button {
            id : plusButton
            width: 50
            height: 50



            contentItem : Text{
                text: "+"
                color : "black"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold : true
                font.pixelSize: 20
            }


            background: Rectangle {
                color: plusButton.pressed ? "#e0e0e0" : (plusButton.hovered ? "#f5f5f5" : "white")
                border.color: "black"
                border.width: 1
            }
        }
        Button {
            id : minusButton
            width: 50
            height: 50

            contentItem : Text{
                text: "-"
                color : "black"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold : true
                font.pixelSize: 20
            }


            background: Rectangle {
                color: minusButton.pressed ? "#e0e0e0" : (minusButton.hovered ? "#f5f5f5" : "white")
                border.color: "black"
                border.width: 1
            }
        }
        */
    }
}