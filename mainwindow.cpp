#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&result, &Result::firstWindowMaximized, this, &MainWindow::showMaximized);
    connect(&result, &Result::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filePath = ui->lineEdit->text();
    QDesktopServices::openUrl(QUrl("file:///" + filePath /*+ " and Settings/All Users/Desktop"*/, QUrl::TolerantMode));
    // QProcess *proc = new QProcess(this);
    // proc->start("notepad " + fileName);
    // proc->startDetached("notepad " + fileName);

    if (this->isMaximized()) {
        result.showMaximized();
    } else {
        result.show();
    }
    // result.setAnswer("AAAAAAAAAAAAAAAAAAA");
    this->close();
    // delete proc;
}


void MainWindow::on_toolButton_clicked()
{
    QString DirName = QFileDialog::getOpenFileName(this, "Choose file", "/");
    ui->lineEdit->setText(DirName);
}

