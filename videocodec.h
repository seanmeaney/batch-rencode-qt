#ifndef VIDEOCODEC_H
#define VIDEOCODEC_H

#include "codec.h"


class VideoCodec : public Codec
{
public:
    VideoCodec(const QString& codecName, int codecType);


    void setCRF(int c) { crf = c; }
    void setPreset (const QString& p) {preset = p; }

    int getCRF() { return crf; }
    const QString& getPreset() { return preset; }

private:

    int crf;
    QString preset;
};

#endif // VIDEOCODEC_H
