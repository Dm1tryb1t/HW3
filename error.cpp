#include "error.h"
#include "ui_error.h"

Error::Error(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::error)
{
    ui->setupUi(this);
}

Error::~Error()
{
    delete ui;
}
