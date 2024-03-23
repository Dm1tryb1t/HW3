#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "edit.h"
#include "result.h"
#include "error.h"

#include <QProcess>
#include <QMainWindow>
#include <QFileDialog>
#include <QDesktopServices>
#include <QFileSystemWatcher>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clear_fields();
private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void resShow();

private:
    Ui::MainWindow *ui;
    Edit edit;
    Result result;
    Error error;
};
#endif // MAINWINDOW_H
