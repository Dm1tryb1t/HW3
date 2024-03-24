#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Edit)
{
    ui->setupUi(this);
}

Edit::~Edit()
{
    delete ui;
}

void Edit::setPathAndLanguage(const QString& filepath, const QString& language) {
    ui->lineEdit->setText(filepath);
    ui->lineEdit_2->setText(language);
}

void Edit::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    this->close();
}


void Edit::on_pushButton_clicked()
{
    if (ui->checkBox->isChecked() && ui->checkBox_2->isChecked()) {
        emit showResult();
        ui->checkBox->setChecked(0);
        ui->checkBox_2->setChecked(0);
        this->close();
    }
}


void Edit::on_toolButton_clicked()
{
    QString filePath = ui->lineEdit->text();
    QDesktopServices::openUrl(QUrl("file:///" + filePath /*+ " and Settings/All Users/Desktop"*/, QUrl::TolerantMode));
}

