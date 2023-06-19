#ifndef VIDEOCODEC_H
#define VIDEOCODEC_H

#include "codec.h"


class VideoCodec : public Codec
{
public:
    VideoCodec(const QString& codecName, int codecType);
};

#endif // VIDEOCODEC_H
