import QtQuick

Row{

    required property int address
    required property string content

    Rectangle{
        height : 20
        width : parent.parent.width/4
        Text{
            anchors.verticalCenter : parent.verticalCenter
            text: address
            font.pixelSize : 12

        }
    }

    Rectangle{
        height : 20
        width : parent.parent.width * 3 / 4
        Text{
            anchors.verticalCenter : parent.verticalCenter
            text: content
            font.pixelSize : 12
        }
    }

}
