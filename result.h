#ifndef RESULT_H
#define RESULT_H

#include <QWidget>

namespace Ui {
class Result;
}

class Result : public QWidget
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
    void setAnswer(QString);

signals:
    void firstwindow();
    void firstwindowMaximized();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
