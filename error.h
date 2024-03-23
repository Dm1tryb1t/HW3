#ifndef ERROR_H
#define ERROR_H

#include <QWidget>

namespace Ui {
class error;
}

class Error : public QWidget
{
    Q_OBJECT

public:
    explicit Error(QWidget *parent = nullptr);
    ~Error();

private:
    Ui::error *ui;
};

#endif // ERROR_H
