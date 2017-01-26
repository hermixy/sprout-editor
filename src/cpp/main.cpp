#include <QtWidgets>
#include <QtQml>
#include <RegisterOsgTypes.h>
#include "Base/Core.h"
#include "Base/Settings.h"
#include "Base/FileSystemModel.h"
#include "Base/OperatorModel.h"
#include "Base/OperatorProxyModel.h"
#include "Db/SproutDb.h"
#include "Gui/MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    app.setOrganizationName("Greenery");
    app.setApplicationName("Greenery");
    app.setApplicationVersion("0.1.0");

    QCommandLineParser parser;
    parser.addOptions({
        {{"q", "qwidget"}, QCoreApplication::translate("main", "QWidget GUI")},
    });

    parser.process(app);

    if (parser.isSet("qwidget")) {
        MainWindow mainWindow;
        mainWindow.show();
        return app.exec();
    }

    registerOsgTypes();
    qmlRegisterType<FileSystemModel>("Greenery", 0, 1, "FileSystemModel");
    qmlRegisterType<SproutDb>("Greenery", 0, 1, "SproutDb");

    Core core;
    Settings settings;

    OperatorModel operatorModel;
    OperatorProxyModel operatorProxyModel;
    operatorProxyModel.setSourceModel(&operatorModel);
    operatorProxyModel.setFilterRole(operatorModel.firstRole());

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Core", &core);
    engine.rootContext()->setContextProperty("Settings", &settings);
    engine.rootContext()->setContextProperty("OperatorModel", &operatorModel);
    engine.rootContext()->setContextProperty("OperatorProxyModel", &operatorProxyModel);

#ifdef QT_DEBUG
    engine.rootContext()->setContextProperty("debugMode", QVariant(true));
#else
    engine.rootContext()->setContextProperty("debugMode", QVariant(false));
#endif

    engine.load(QUrl("qrc:/qml/Main.qml"));

    if (engine.rootObjects().isEmpty()) return EXIT_FAILURE;

    return app.exec();
}
