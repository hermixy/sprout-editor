import QtQuick 2.5
import QtQuick.Controls 1.4
import Greenery 1.0
import OsgBridge 1.0 as Osg
import "sheets"
import "nodes"
import "../js/command.js" as Command
import "../js/utils.js" as Utils
import "../js/world.js" as World

Item {
    id: root
    property alias sproutDb: sproutDb
    property alias commandSheet: commandSheet
    property alias output: output
    property alias cons: cons
    property bool isCurrentTab: mainRoot.currentTab === root
    property string filePath
    property string commandState: Command.Ready
    property var currentNode

    Component.onDestruction: {
        sproutDb.close()
    }

    onCommandStateChanged: {
        if (commandState === Command.Ready) {
            forceActiveFocus()
        }
    }

    function reset() {
        camera.reset()
    }

    function cancel() {
        commandState = Command.Ready
    }

    function createWorld() {
        sproutDb.open(filePath)
        World.createWorld()
    }

    Component.onCompleted: {
        forceActiveFocus()
//        createWorld()
    }

    Keys.onPressed: {
        Command.run(event)
    }

    Keys.onEscapePressed: cancel()

    SproutDb {
        id: sproutDb
    }

    Console {
        id: cons
        onMessage: output.textEdit.append(message)
    }

    Osg.Viewer {
        id: viewer
        anchors.fill: parent
        camera.clearColor: "gray"
        sceneData: Osg.Geode {
            Osg.Text3D {
                id: osgText
//                text: textField.text
                text: "hello world!"
            }

            Osg.ShapeDrawable {
                color: "red"
                shape: Osg.Box {
                    halfLengths: Qt.vector3d(0.5, 0.5, 0.5)
                }
            }

            Osg.ShapeDrawable {
                color: "green"
                shape: Osg.Sphere {
                    radius: 0.7
                }
            }
        }
    }

    Column {

        TextField {
            id: textField
            text: "Hello"
        }

        Button {
            text: "Save scene"
            onClicked: viewer.saveScene("/home/krre/1/scene.osg")
        }
    }

    CommandSheet {
        id: commandSheet
        anchors.top: parent.top
        anchors.right: parent.right
    }

    Output {
        id: output
        width: parent.width
        anchors.bottom: parent.bottom
    }
}
