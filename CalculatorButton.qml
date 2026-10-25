import QtQuick
import QtQuick.Controls.Basic

Button {
    id: control
    property string variant: "number"
    property color buttonColor: variant === "number" ? "#1B2B34" : (variant === "equals" ? "#45D6B0" : "#30434C")
    property color pressedColor: variant === "number" ? "#30434C" : (variant === "equals" ? "#32B994" : "#405762")
    property color textColor: variant === "equals" ? "#10231E" : "#F3F7F8"
    font.pixelSize: 16

    background: Rectangle {
        color: control.down ? control.pressedColor : control.buttonColor
        radius: 10
    }

     contentItem: Text {
        text: control.text
        color: control.textColor
        font: control.font
        horizontalAlignment :Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
     }

}
