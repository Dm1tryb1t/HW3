#ifndef EDIT_H
#define EDIT_H

#include <QWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QFileSystemWatcher>
#include <QString>

namespace Ui {
class Edit;
}

class Edit : public QWidget
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    ~Edit();
    void setPathAndLanguage(const QString&, const QString&);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_toolButton_clicked();

signals:
    void showResult();

private:
    Ui::Edit *ui;
};

#endif // EDIT_H
