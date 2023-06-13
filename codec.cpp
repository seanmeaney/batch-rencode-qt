#include "codec.h"

Codec::Codec(const QString& codecName_, Worker* worker, int codecType_)
{
    codecName = codecName_;
    w = worker;
    codecType = codecType_;
    init();
}

void Codec::init(){

}
