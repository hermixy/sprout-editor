import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import "../js/utils.js" as Utils

ApplicationWindow {
    id: mainRoot
    property string version: "0.1.0"
    property var currentTab: tabView.count > 0 ? tabView.getTab(tabView.currentIndex).item : null
    title: "Greenery"
    width: 800
    height: 600
    visible: true
    menuBar: TopMenuBar { id: topMenuBar }

    Component.onCompleted: {
        x = (Screen.width - width) / 2
        y = (Screen.height - height) / 2
        Utils.loadRecentFiles()
        Utils.loadSession()
    }

    Component.onDestruction: {
        Utils.saveRecentFiles(topMenuBar.recentFilesModel)
        Utils.saveSession()
    }

    TabView {
        id: tabView
        anchors.fill: parent
    }

    Component {
        id: treeArea
        TreeArea {}
    }
}


