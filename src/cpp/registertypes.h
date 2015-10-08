#pragma once
#include <QtQml>
#include <sprout/sproutdb.h>
#include "console.h"
#include "osgbridge/osgViewer/viewer.h"
#include "osgbridge/osg/object.h"
#include "osgbridge/osg/node.h"
#include "osgbridge/osg/group.h"
#include "osgbridge/osg/transform.h"

static void registerTypes() {
    // Greenery
    qmlRegisterType<Console>("Greenery", 1, 0, "Console");
    qmlRegisterType<SproutDb>("Greenery", 1, 0, "SproutDb");

    // OpenSceneGraph
    qmlRegisterType<Viewer>("OsgBridge", 1, 0, "Viewer");
    qmlRegisterUncreatableType<Object>("OsgBridge", 1, 0, "Object", "Object is uncreatable type");
    qmlRegisterType<Node>("OsgBridge", 1, 0, "Node");
    qmlRegisterType<Group>("OsgBridge", 1, 0, "Group");
    qmlRegisterType<Transform>("OsgBridge", 1, 0, "Transform");
}
