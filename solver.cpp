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
        progname += ".exe";
        process.start("g++", QStringList() << filename << "-o" << progname << "-w" << "-std=c++20");
        process.waitForFinished();
        QString error = QString(process.readAll());
        if (error != "") {
            process.close();
            return error;
        }
        // process.startCommand("C:\\prog");
        process.startCommand(progname);
        process.waitForFinished();
        QString answer = QString(process.readAll());
        QFile prog(progname);
        prog.remove();
        // process.startCommand("del " + progname);
        return answer;
    }
    if (!language.contains("thon")) {
        // process.startCommand("g++ " + filename + " -o C:\\prog -w");
        QString progname = filename;
        progname.resize(progname.size() - 2);
        progname += ".exe";
        process.start("gcc", QStringList() << filename << "-o" << progname << "-w" << "-std=c++20");
        process.waitForFinished();
        QString error = QString(process.readAll());
        if (error != "") {
            QFile prog(progname);
            prog.remove();
            return error;
        }
        // process.startCommand("C:\\prog");
        process.startCommand(progname);
        process.waitForFinished();
        QString answer = QString(process.readAll());
        QFile prog(progname);
        prog.remove();
        // process.startCommand("del " + progname);
        return answer;
    }
    process.start("python", QStringList() << filename);
    process.waitForFinished();
    QString answer = QString(process.readAll());
    return answer;
    return "-1";
}
