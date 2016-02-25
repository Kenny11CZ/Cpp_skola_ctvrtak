#ifndef PRVEKLSS_H
#define PRVEKLSS_H




class PrvekLSS
{
public:
    PrvekLSS();
    PrvekLSS(int hodnota);

    void SetHodnota(int x);
    int GetHodnota();
    void SetDalsi(PrvekLSS *x);
    PrvekLSS *GetDalsi();

private:
    int hodnota;
    PrvekLSS *dalsi;


};

#endif // PRVEKLSS_H
