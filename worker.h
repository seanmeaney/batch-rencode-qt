#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <QDebug>
#include <QProcess>

const static QStringList recommendedVideoCodecs = {"libx264", "nvenc_h264", "h264_qsv", "hs264_vaapi", "h264_amf", "libx265", "hevc_nvenc", "hevc_qsv", "hevc_vaapi", "hevc_amf"};
const static QStringList recommendedAudioCodecs = {"aac", "libfdk_aac", "flac", "libopus", "ac3", "eac3"};

class Worker
{

public:



    Worker();

    const QStringList& getAudioEncoders() { return codecs.second; }
    const QStringList& getVideoEncoders() { return codecs.first; }
    const QString& getFFPath() { return ffPath; }

    bool getCodecInfo();


private:

    void init();
    bool findFFmpegPath();
    const QPair<QStringList, QStringList> getSupportedCodecs();
    const QPair<QStringList, QStringList> parseSupportedCodecs(const QString& wallOfText);
    bool startFFmpeg(const QString&, const QStringList&, bool = false);

    QString ffPath;
    QProcess ffProcess;

    //first is video codecs, second is audio codecs
    QPair<QStringList, QStringList> codecs;

};

#endif // WORKER_H
