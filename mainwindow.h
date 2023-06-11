#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Worker* worker;

    QString outDir;
    QString inDir;
    QString crf;
    QString audioBitrate;
    QString vidEncoder;
    QString audioEncoder;
    QString preset;
    bool fastStart;
    bool overwriteVids;

    void populateEncoders();

private slots:

    void on_choosePath_released();
    void on_chooseOutPath_released();

};
#endif // MAINWINDOW_H
