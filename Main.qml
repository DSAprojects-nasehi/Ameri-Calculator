import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic



ApplicationWindow {
    id: window
    width: 360
    height: 640
    minimumWidth: 320
    minimumHeight: 500
    visible: true
    title: qsTr("Ameri Calculator")
    color: "#101B22"

    Rectangle {
        id: display
        width: parent.width - 32
        height: 140
        radius: 16
        color: "#1B2B34"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 24
        Text {
            id: displayText
            text: controller.displayText
            color: "#F3F7F8"
            font.pixelSize: 48
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 16

        }
        Text {
            id: expressionText
            text: controller.expression
            color: "#91A5AE"
            font.pixelSize: 16
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.right: parent.right
            anchors.rightMargin: 20

        }
    }

    GridLayout{
        id: keypad
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 24
        columns	:4
        rowSpacing	:10
        columnSpacing:	10
        width:	parent.width - 32
        anchors.horizontalCenter:	parent.horizontalCenter
        anchors.top:	display.bottom
        anchors.topMargin:	20
        Repeater {
            model: [
                { label: "AC", buttonVariant: "control", action: "clear" },
                { label: "⌫", buttonVariant: "control", action: "backspace" },
                { label: "(", buttonVariant: "control", action: "input" },
                { label: ")", buttonVariant: "control", action: "input" },

                { label: "7", buttonVariant: "number", action: "input" },
                { label: "8", buttonVariant: "number", action: "input" },
                { label: "9", buttonVariant: "number", action: "input" },
                { label: "÷", buttonVariant: "operator", action: "input" },
                { label: "4", buttonVariant: "number", action: "input" },
                { label: "5", buttonVariant: "number", action: "input" },
                { label: "6", buttonVariant: "number", action: "input" },
                { label: "×", buttonVariant: "operator", action: "input" },

                { label: "1", buttonVariant: "number", action: "input" },
                { label: "2", buttonVariant: "number", action: "input" },
                { label: "3", buttonVariant: "number", action: "input" },
                { label: "−", buttonVariant: "operator", action: "input" },

                { label: "0", buttonVariant: "number", action: "input" },
                { label: ".", buttonVariant: "number", action: "input" },
                { label: "+", buttonVariant: "operator", action: "input" },
                { label: "=", buttonVariant: "equals", action: "calculate" }
            ]

            delegate: CalculatorButton {
                text: modelData.label
                variant: modelData.buttonVariant
                Layout.fillHeight: true

                Layout.fillWidth: true
                implicitHeight: 52

                onClicked: {
                    if (modelData.action === "clear") {
                        controller.clearExpression()
                    }
                    else if (modelData.action === "backspace") {
                        controller.backspace()
                    }
                    else if (modelData.action === "input") {
                        controller.appendInput(modelData.label)
                    }
                    else if (modelData.action === "calculate") {
                        controller.calculate()
                    }
                }

            }
        }

    }

}
