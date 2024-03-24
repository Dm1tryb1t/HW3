#ifndef SOLVER_H
#define SOLVER_H

#include <QProcess>
#include <QFile>

class Solver
{
public:
    Solver();
    QString getAnswer(const QString&, const QString&);
};

#endif // SOLVER_H
