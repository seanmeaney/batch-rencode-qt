#include "codec.h"

Codec::Codec(const QString& codecName, int codecType)
{
    name = codecName;
    type = codecType;
    init();
}

void Codec::init(){

}

//void Codec::findSupportedAttributes(){

//}


//bool isVideoCodec();
//bool supportsCRF();
//bool supportsPreset();


//bool isAudioCodec();
