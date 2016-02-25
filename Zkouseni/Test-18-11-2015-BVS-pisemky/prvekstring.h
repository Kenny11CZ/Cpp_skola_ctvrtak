#ifndef PRVEKSTRING_H
#define PRVEKSTRING_H
#include <QString>

class PrvekString
{
public:
    PrvekString();
    QString GetHodnota();
    void SetHodnota(QString hodnota);
    PrvekString *GetLevy();
    void SetLevy(PrvekString *ukLevy);
    PrvekString *GetPravy();
    void SetPravy(PrvekString *ukPravy);

private:
    QString hodnota;
    PrvekString *ukLevy;
    PrvekString *ukPravy;
};

#endif // PRVEKSTRING_H
