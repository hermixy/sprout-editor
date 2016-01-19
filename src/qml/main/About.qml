import QtQuick 2.5
import QtQuick.Dialogs 1.2
import "../components/messagedialog"

MessageDialogBase {
    title: qsTr("About Greenery")
    standardButtons: StandardButton.Ok
    text: String("<h3>Greenery %1</h3>
          Based on Qt %2<br>
          Build on %3<br><br>
          Copyright © 2015-2016, Vladimir Zarypov").arg(VERSION.full).arg(UTILS.qtVersion).arg(UTILS.buildDate)
}
