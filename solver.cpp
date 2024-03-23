#include "solver.h"

Solver::Solver() {}

QString Solver::getAnswer(const QString& language, const QString& filename) {
    QProcess process;
    // process.open();
    if (language.contains("++")) {
        // process.startCommand("g++ " + filename + " -o C:\\prog -w");
        process.start("C:\\Windows\\System32\\cmd.exe", QStringList() << "g++ " + filename + " -o C:\\prog -w");
        process.waitForReadyRead();
        QString error = QString(process.readAllStandardOutput());
        if (error != "") {
            process.close();
            return error + "-2";
        }
        // process.startCommand("C:\\prog");
        process.start("C:\\Windows\\System32\\cmd.exe", QStringList() <<  "C:\\prog");
        process.waitForReadyRead();
        QString answer = QString(process.readAllStandardOutput());
        process.startCommand("rm C:\\prog");
        process.close();
        return answer + "-3";
    } /*else if (language.contains("thon")) {

    } else {

    }*/
    return "-1";
}
