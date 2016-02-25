#include "stromkalk.h"

StromKalk::StromKalk()
{

}

double StromKalk::VyhodnotStrom()
{
    return VyhodnotStrom(koren);
}

double StromKalk::VyhodnotStrom(PrvekKalk *uzel)
{
    if(uzel->GetOperace() == '')
        return uzel->GetCislo();
    else
    {
        double levy = uzel->GetLevy()->GetCislo();
        double pravy = uzel->GetPravy()->GetCislo();
        switch (uzel->GetOperace().toLatin1()) {
        case '+':
            return levy + pravy;
            break;
        case '-':
            return levy - pravy;
            break;
        case '*':
            return levy * pravy;
            break;
        case '/':
            return pravy != 0 ? levy / pravy : 0;
            break;
        default:
            break;
        }
    }
}

bool StromKalk::IsNumber(QString text)
{
    bool result;
    text.toInt(&result);
    return result;
}

bool StromKalk::IsChar(QChar c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

