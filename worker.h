#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <QDebug>
#include <QProcess>
#include "codec.h"

const static QStringList recommendedVideoCodecs = {"libx264", "nvenc_h264", "h264_qsv", "hs264_vaapi", "h264_amf", "libx265", "hevc_nvenc", "hevc_qsv", "hevc_vaapi", "hevc_amf"};
const static QStringList recommendedAudioCodecs = {"aac", "libfdk_aac", "flac", "libopus", "ac3", "eac3"};

class Worker
{

public:

    Worker();

    const QList<Codec>& getCodecs() { return codecs; }
    const QList<Codec&> getAudioEncoders();
    const QList<Codec&> getVideoEncoders();


private:

    void init();
    bool findFFmpegPath();
    const QList<Codec> getSupportedCodecs();
    const QList<Codec> parseSupportedCodecs(const QString& wallOfText);
    bool parseExtraCodecData(const QString& codecName, const QString& wallOfText);
    bool addCodecFeatures();
    bool startFFmpeg(const QString&, const QStringList&, bool = false);

    QProcess ffProcess;

    QList<Codec> codecs;

};

#endif // WORKER_H
