#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Result)
{
    ui->setupUi(this);
}

Result::~Result()
{
    delete ui;
}

void Result::setAnswer(QString answer) {
    ui->textEdit->setText(answer);
}

void Result::on_pushButton_clicked()
{
    ui->textEdit->setText("");
    if (this->isMaximized()) {
        emit firstwindowMaximized();
    } else {
        emit firstwindow();
    }
    this->close();
}

