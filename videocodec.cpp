#include "videocodec.h"

VideoCodec::VideoCodec(const QString& codecName, int codecType)
    : Codec(codecName, codecType)
{
    crf = 23;
    preset = "medium";
}
