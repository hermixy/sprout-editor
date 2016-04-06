#pragma once
#include <QtWidgets>
#include "WorkArea.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void newFile();
    void open();
    void save();
    void saveAs();
    void quitApp();
    void about();
    void aboutQt();

private:
    void createActions();
    void readSettings();
    void writeSettings();
    bool maybeSave();

    WorkArea* workArea;
    QSplitter* splitter;
    QFileSystemModel* fileSystemModel;
};
