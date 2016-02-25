#ifndef STROMKALK_H
#define STROMKALK_H
#include "prvekkalk.h"

#include <qstring.h>

class StromKalk
{
public:
    StromKalk();
    double VyhodnotStrom();
    double VyhodnotStrom(PrvekKalk *uzel);
    bool IsNumber(QString text);
    bool IsChar(QChar c);

private:
    PrvekKalk *koren;
};

#endif // STROMKALK_H
