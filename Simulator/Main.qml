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
    color:"white"

    Row{
        id: mainRow
        width : parent.width
        Column{
            width: parent.width / 2
            Text{
                anchors.left : parent.left
                text: "RAM"
                font.pixelSize : 15
                font.bold : true
            }

            Row{
                Rectangle{
                    height : 20
                    width : parent.parent.width/4
                    Text{
                        anchors.verticalCenter : parent.verticalCenter
                        text: "Address"
                        font.pixelSize : 14

                    }
                }

                Rectangle{
                    height : 20
                    width : parent.parent.width * 3 / 4
                    Text{
                        anchors.verticalCenter : parent.verticalCenter
                        text: "Value"
                        font.pixelSize : 14
                    }
                }

            }

            Repeater{
                model : NumberStore.registers
                delegate:
                    TableRows{
                        required property var modelData
                        address : modelData.address
                        content : modelData.value

                        Component.onCompleted: {
                            console.log("Row item:", modelData, "keys:", Object.keys(modelData), "addr:", modelData.address, "val:", modelData.value)
                        }
                    }

            }
        }

        Column{
            width: parent.width / 2
            Text{
                anchors.left : parent.left
                text: "CPU"
                font.pixelSize : 15
                font.bold : true
            }
        }

    }




}
