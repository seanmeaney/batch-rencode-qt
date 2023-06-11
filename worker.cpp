#include "worker.h"

#include <iostream>
//#include <QList>
#include <QDir>
#include <QPair>


Worker::Worker()
{
    ffPath = nullptr;
    init();
}

void Worker::init(){
    if (findFFmpegPath()){
        codecs = getSupportedCodecs();
    } else{
        qDebug() << "Unable to find ffmpeg (make sure it is in path)";
    }
}

const QPair<QStringList, QStringList> Worker::getSupportedCodecs(){
    startFFmpeg(ffPath.append("/ffmpeg"), QStringList("-encoders"));
    return parseSupportedCodecs(QString(ffProcess.readAllStandardOutput()));
}

const QPair<QStringList, QStringList> Worker::parseSupportedCodecs(const QString &wallOfText){
    QPair<QStringList, QStringList> codecs;
    QStringList lines = wallOfText.split("\n ");
    QStringList lineSeperated;
    QString line;
    //first 10 lines are formatting info
    for (int i=10; i < lines.size(); i++){
        line = lines[i];
        lineSeperated = line.split(" ");
        if (line[0] == "V"){    //video codec
            codecs.first.append(lineSeperated[1]);
        } else if (line[0] == "A"){ //audio codec
            codecs.second.append(lineSeperated[1]);
        }
    }
    return codecs;
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
        }
        #else
        if (QDir(s).entryList().contains("ffmpeg")){
            ffPath = s;
        }
        #endif

    }
    return !ffPath.isNull();
}
