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

    QJsonDocument readCodecSupport();

private:

    bool findFFmpegPath();

    Ui::MainWindow *ui;
    Worker* worker;
    VideoCodec* vidEncoder;
    AudioCodec* audioEncoder;

    QString ffPath;
    QString outDir;
    QString inDir;
    QStringList inVids;

    void populateEncoders();

private slots:

    void updatePath();
    void showTheseEncoders();
    void changeAudioEncoder(const QString &text);
    void changeVideoEncoder(const QString &text);
    void startTranscode();

};
#endif // MAINWINDOW_H
