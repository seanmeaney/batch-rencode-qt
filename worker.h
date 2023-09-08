#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <QDebug>
#include <QProcess>
#include "codec.h"
#include "videocodec.h"
#include "audiocodec.h"

const static QStringList recommendedVideoCodecs = {"libx264", "h264_nvenc", "h264_qsv", "h264_amf", "libx265", "hevc_nvenc", "hevc_qsv", "hevc_amf"};
const static QStringList recommendedAudioCodecs = {"aac", "libfdk_aac", "flac", "libopus", "ac3", "eac3"};

const static QStringList searchFileExentions = {"*.mp4", "*.mkv", "*.mov", "*.avi", "*.wmv"};

class Worker
{

public:

    Worker(const QString& ffath_);

    const QList<Codec>& getCodecs() { return codecs; }
    const QStringList& getAudioEncoders();
    const QStringList& getVideoEncoders();
    Codec* getCodec(const QString& name);
    bool startConversion(const QString & in, const QString & out, AudioCodec* audioCodec, VideoCodec* videoCodec);
    bool parseExtraCodecData(const QString& codecName, const QString& wallOfText);
    const QList<Codec> getSupportedCodecs();

    const QStringList findVideos(const QString& path);


private:

    const QList<Codec> parseSupportedCodecs(const QString& wallOfText);
    bool addCodecFeatures();
    bool startFFmpeg(const QString&, const QStringList&, bool = false);

    QProcess ffProcess;
    QString ffPath;

    QList<Codec> codecs;
    QStringList audioEncoders;
    QStringList videoEncoders;

};

#endif // WORKER_H
