#include "worker.h"

#include <iostream>
#include <QDir>

static QString ffPath = nullptr;

Worker::Worker()
{
    init();
}

void Worker::init(){
    if (ffPath == nullptr && findFFmpegPath()){
        codecs = getSupportedCodecs();
    } else{
        qDebug() << "Unable to find ffmpeg (make sure it is in path)";
    }
}
Codec* Worker::getCodec(const QString& name){
    for (Codec& c: codecs){
        if (c.getName() == name)
            return &c;
    }
    //temp should make a sentinel value
    return &codecs.first();
}

const QStringList& Worker::getAudioEncoders(){
    return audioEncoders;
}
const QStringList& Worker::getVideoEncoders(){
    return videoEncoders;
}

const QList<Codec> Worker::getSupportedCodecs(){
    startFFmpeg(ffPath, QStringList("-encoders"));
    return parseSupportedCodecs(QString(ffProcess.readAllStandardOutput()));
}

bool Worker::parseExtraCodecData(const QString& codecName, const QString& wallOfText){
    return false;
}

const QList<Codec> Worker::parseSupportedCodecs(const QString &wallOfText){
    QStringList lines = wallOfText.split("\n ");
    QString line;
    QStringList lineSeperated;
    //first 10 lines are formatting info
    for (int i=10; i < lines.size(); i++){
        line = lines[i];
        lineSeperated = line.split(" ");
        if (line[0] == "V"){
            codecs.append(Codec(lineSeperated[1],1));
            videoEncoders.append(lineSeperated[1]);
        } else if (line[0] == "A"){
            codecs.append(Codec(lineSeperated[1],2));
            audioEncoders.append(lineSeperated[1]);
        }
    }
    if (!addCodecFeatures())
        qDebug() << "error parsing codec feature text";
    return codecs;
}

bool Worker::addCodecFeatures(){
    for (Codec c: codecs){
        QStringList t = {"-h", QString("encoder=").append(c.getName())};
        startFFmpeg(ffPath, t);
        QString output(ffProcess.readAllStandardOutput());
        parseExtraCodecData(c.getName(), output);
    }
    return 1;
}

bool Worker::startFFmpeg(const QString& path, const QStringList& args, bool forwardOutput){
    if (forwardOutput)
        ffProcess.setProcessChannelMode(QProcess::ForwardedChannels);
    ffProcess.start(path, args);
    return ffProcess.waitForFinished();
}

bool Worker::findFFmpegPath(){
    QString path(std::getenv("PATH"));

    #ifdef _WIN32
    QStringList pathSeperated = path.split(";");
    #else
    QStringList pathSeperated = path.split(":");
    #endif

    for (QString& s : pathSeperated){
        #ifdef _WIN32
        if (QDir(s).entryList().contains("ffmpeg.exe")){
            ffPath = s;
            ffPath.append("\ffmpeg.exe");
        }
        #else
        if (QDir(s).entryList().contains("ffmpeg")){
            ffPath = s;
            ffPath.append("/ffmpeg");
        }
        #endif

    }
    return !ffPath.isNull();
}
