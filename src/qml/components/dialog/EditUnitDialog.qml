import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import "../../../js/command.js" as Command
import "../../../js/world.js" as World

DialogBase {
    id: root
    property var unit
    title: qsTr("Edit Unit")
    width: 400

    onAccepted: {
        World.editModule(unit.unitId, arg.text)
        unit.arg = arg.text
    }

    onVisibleChanged: commandState = Command.Ready

    GridLayout {
        width: parent.width
        columns: 2
        columnSpacing: 10
        rowSpacing: 10

        Label {
            text: qsTr("Title:")
        }

        Label {
            text: unit.title
        }

        Label {
            text: qsTr("Argument:")
        }

        TextField {
            id: arg
            text: unit.arg
            Layout.fillWidth: true
            Component.onCompleted: forceActiveFocus()
        }
    }
}

