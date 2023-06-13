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

const QList<Codec> Worker::getSupportedCodecs(){
    startFFmpeg(ffPath.append("/ffmpeg"), QStringList("-encoders"));
    return parseSupportedCodecs(QString(ffProcess.readAllStandardOutput()));
}

const QList<Codec> Worker::parseSupportedCodecs(const QString &wallOfText){
    QStringList lines = wallOfText.split("\n ");
    QStringList lineSeperated;
    QString line;
    //first 10 lines are formatting info
    for (int i=10; i < lines.size(); i++){
        line = lines[i];
        lineSeperated = line.split(" ");        //video codec 1 else 2
        codecs.append(Codec(lineSeperated[1],(line[0] == "V")? 1 : 2));
    }
    if (!addCodecFeatures())
        qDebug() << "error parsing codec feature text";
    return codecs;
}

bool Worker::addCodecFeatures(){
    for (Codec c: codecs){
        QStringList t = {"-h", "-encoder=", c.getName()};
//        QString argtemp("-h -encoder=");
//        argtemp.append(c.getName());
        startFFmpeg(ffPath.append("/ffmpeg"), QStringList(t));
        QString output(ffProcess.readAllStandardOutput());
        int tmemt = 0;
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
        }
        #else
        if (QDir(s).entryList().contains("ffmpeg")){
            ffPath = s;
        }
        #endif

    }
    return !ffPath.isNull();
}
