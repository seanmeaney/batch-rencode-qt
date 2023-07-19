#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worker.h"
#include "codec.h"
#include "audiocodec.h"
#include "videocodec.h"

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
    VideoCodec* vidEncoder;
    AudioCodec* audioEncoder;

    QString outDir;
    QString inDir;
    QStringList inVids;
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
    void on_startConversion_released();

};
#endif // MAINWINDOW_H
