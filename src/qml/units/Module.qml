import QtQuick 2.5
import OsgBridge 1.0 as Osg
import "../../js/world.js" as World

UnitBase {
    objectName: "module"
    title: "Module"
    color: "lightgreen"
    onEdit: World.editModule(unitId, name)
}