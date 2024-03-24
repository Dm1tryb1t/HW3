#include "solver.h"

Solver::Solver() {}

QString Solver::getAnswer(const QString& language, const QString& filename) {
    QProcess process;
    // process.open();
    process.setWorkingDirectory("C:/");
    process.setProcessChannelMode(QProcess::ProcessChannelMode::MergedChannels);
    if (language.contains("++")) {
        // process.startCommand("g++ " + filename + " -o C:\\prog -w");
        QString progname = filename;
        if (progname.endsWith(".cc")) {
            progname.resize(progname.size() - 3);
        } else {
            progname.resize(progname.size() - 4);
        }
        process.start("cmd.exe", QStringList() << "g++" << filename << "-o" << progname);
        process.waitForFinished();
        QString error = QString(process.readAll());
        if (error != "") {
            process.close();
            return error + "-2";
        }
        // process.startCommand("C:\\prog");
        process.start("cmd.exe", QStringList() << progname);
        process.waitForFinished();
        QString answer = QString(process.readAll());
        // process.startCommand("rm C:\\prog");
        process.close();
        return answer + "-3";
    } /*else if (language.contains("thon")) {

    } else {

    }*/
    return "-1";
}
