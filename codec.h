#ifndef CODEC_H
#define CODEC_H

#include <QString>
#include "worker.h"


class Codec
{
public:
    Codec(const QString& codecName, int codecType);

    bool isVideoCodec();
    bool supportsCRF();
    bool supportsPreset();


    bool isAudioCodec();

private:

    void init();

    QString name;
    int type;
    Worker* w;

    bool crf;
    bool preset;
};

#endif // CODEC_H
