#ifndef AUDIOCODEC_H
#define AUDIOCODEC_H

#include "codec.h"

class AudioCodec : public Codec
{
public:
    AudioCodec(const QString& codecName, int codecType);

    int getSamplerate() { return samplerate; }
    float getBitrate() { return bitrate; }
    void setSampleRate(int s) { samplerate = s; }
    void setBitrate(float b) { bitrate = b; }

private:
    int samplerate;
    float bitrate;
};

#endif // AUDIOCODEC_H
