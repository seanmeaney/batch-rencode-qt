#ifndef CODEC_H
#define CODEC_H

#include <QString>


class Codec
{
public:
    Codec(const QString& codecName, int codecType);


    const QString& getName() { return name; }
    int getType() { return type; }
    bool isVideoCodec();



    bool isAudioCodec();

protected:

    void init();

    QString name;
    int type;
};

#endif // CODEC_H
