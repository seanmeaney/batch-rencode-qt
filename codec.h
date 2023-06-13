#ifndef CODEC_H
#define CODEC_H

#include <QString>

class Codec
{
public:
    Codec(const QString& codecName, int codecType);

private:
    QString name;
    int type;
};

#endif // CODEC_H
