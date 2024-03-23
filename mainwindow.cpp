#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&result, &Result::firstwindowMaximized, this, &MainWindow::showMaximized);
    connect(&result, &Result::firstwindow, this, &MainWindow::show);

    connect(&edit, &Edit::showResult, this, &MainWindow::resShow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear_fields() {
    ui->lineEdit->clear();
    ui->comboBox->clear();
}

void MainWindow::on_pushButton_clicked()
{
    QString filePath = ui->lineEdit->text();
    QString language = ui->comboBox->currentText();
    QFile file(filePath);
    bool firstCondition = file.exists();
    bool secondCondition = language.contains("++") && (filePath.endsWith(".cpp") || filePath.endsWith(".cc"));
    bool thirdCondition = language.contains("ton") && filePath.endsWith(".py");
    bool fourthCondition = filePath.endsWith(".c");
    if (!(firstCondition && (secondCondition || thirdCondition || fourthCondition))) {
        error.show();
        ui->lineEdit->setText("");
        ui->comboBox->setCurrentIndex(-1);
        return;
    }
    edit.setPathAndLanguage(filePath, language);
    edit.show();
    // this->close();
    // QProcess *proc = new QProcess(this);
    // proc->start("notepad " + fileName);
    // proc->startDetached("notepad " + fileName);

    /* if (this->isMaximized()) {
        result.showMaximized();
    } else {
        result.show();
    }
    // result.setAnswer("AAAAAAAAAAAAAAAAAAA");
    this->close();
    // delete proc;*/
}


void MainWindow::on_toolButton_clicked()
{
    QString DirName = QFileDialog::getOpenFileName(this, "Choose file", "/");
    ui->lineEdit->setText(DirName);
}

void MainWindow::resShow() {
    /* ... тут запускаем прогу ... */
    if (this->isMaximized()) {
        result.showMaximized();
    } else {
        result.show();
    }
    ui->lineEdit->setText("");
    ui->comboBox->setCurrentIndex(-1);
    this->close();
}
