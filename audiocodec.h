#ifndef AUDIOCODEC_H
#define AUDIOCODEC_H

#include "codec.h"

class AudioCodec : public Codec
{
public:
    AudioCodec(const QString& codecName, int codecType);
};

#endif // AUDIOCODEC_H
