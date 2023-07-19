#include "audiocodec.h"

AudioCodec::AudioCodec(const QString& codecName, int codecType)
    : Codec(codecName, codecType)
{
    samplerate = 44100;
    bitrate = 128;
}
