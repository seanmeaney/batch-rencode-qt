#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worker.h"
#include "codec.h"

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
    Codec* vidEncoder;
    Codec* audioEncoder;

    QString outDir;
    QString inDir;
//    QString crf;
//    QString audioBitrate;
//    QString preset;
//    bool fastStart;
//    bool overwriteVids;

    void populateEncoders();

private slots:

    void on_choosePath_released();
    void on_chooseOutPath_released();
    void on_onlyRecomended_released();
    void on_audioEncoders_currentTextChanged(const QString &text);
    void on_videoEncoders_currentTextChanged(const QString &text);

};
#endif // MAINWINDOW_H
