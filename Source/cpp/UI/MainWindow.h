#pragma once
#include <QMainWindow>
#include <QSettings>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionShow_left_sidebar_toggled(bool checked=false);

private:
    Ui::MainWindow* ui;
    QSettings settings;

    void readSettings();
    void writeSettings();
};
