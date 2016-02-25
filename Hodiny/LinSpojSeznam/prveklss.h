#ifndef PRVEKLSS_H
#define PRVEKLSS_H
class PrvekLSS
{
public:
    PrvekLSS();
    PrvekLSS(int hodnota);

    void SetHodnota(int hod);
    int GetHodnota();
    void SetUkDalsi(PrvekLSS *uk);
    PrvekLSS *GetUkDalsi();
private:
    int hodnota;
    PrvekLSS *ukDalsiPrvek;
};

#endif // PRVEKLSS_H
