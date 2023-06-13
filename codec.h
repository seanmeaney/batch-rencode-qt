#ifndef CODEC_H
#define CODEC_H

#include <QString>
#include "worker.h"


class Codec
{
public:
    Codec(const QString&,const Worker*, int);

    bool isVideoCodec();
    bool supportsCRF();
    bool supportsPreset();


    bool isAudioCodec();

private:

    void init();

    QString codecName;
    const Worker* w;
    int codecType;

    bool crf;
    bool preset;



};

#endif // CODEC_H
