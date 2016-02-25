#include <QFile>

void VytvorSoubor();
void VypisSoubor(QString nazev);

int main()
{

    return 0;
}

void VytvorSoubor()
{
    QFile file("..\\qfile\\in.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    file.write("ahoj\n");
    file.write("svete\n");
    file.write("!!!\n");
    file.close();
}
void VypisSoubor(QString nazev)
{
    QFile file(nazev);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        printf("%s", QString(line));
    }
}

