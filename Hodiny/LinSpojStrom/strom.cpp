#include "strom.h"
#include "qlist.h"
#include "stdio.h"

Strom::Strom()
{
    koren = NULL;
}

void Strom::AddElement(int x)
{
    Prvek *el = new Prvek();
    el->SetValue(x);

    if(koren == NULL)
    {
        koren = el;
    }
    else
    {
        Prvek *tmp = koren;
        Prvek *prev;
        while(tmp != NULL) {
            prev = tmp;
            if(tmp->GetValue() < x) {
                tmp = tmp->GetRight();
            } else {
                tmp = tmp->GetLeft();
            }
        }

        if(prev->GetValue() < x) {
            prev->SetRight(el);
        } else {
            prev->SetLeft(el);
        }
    }
}

Prvek *Strom::GetKoren()
{
    return this->koren;
}

void Strom::Fill()
{
    AddElement(5);
    for(int i = 0; i < 10; i++)
        AddElement(i);
}

void Strom::Print(Prvek *x)
{

   if(x != NULL)
   {
       printf("%d ", x->GetValue());
       Print(x->GetLeft());
       printf(" ");
       Print(x->GetRight());
   }

}

void Strom::VPrint()
{
    QList<Prvek*> list;
    list.append(koren);
    koren->SetLast(true);
    while(list.length() != 0)
    {
        printf("%d ", list[0]->GetValue());
        if(list[0]->GetLeft() != NULL)
            list.append(list[0]->GetLeft());
        if(list[0]->GetRight() != NULL)
            list.append(list[0]->GetRight());

        if(list[0]->IsLast())
        {
            list.last()->SetLast(true);
            printf("\n");
        }
        list.removeAt(0);
    }
}

int Strom::Sum()
{
    int result = 0;
    QList<Prvek*> list;
    list.append(koren);
    koren->SetLast(true);
    while(list.length() != 0)
    {
        result += list[0]->GetValue();
        if(list[0]->GetLeft() != NULL)
            list.append(list[0]->GetLeft());
        if(list[0]->GetRight() != NULL)
            list.append(list[0]->GetRight());
        list.removeAt(0);
    }
    return result;
}

int Strom::Lenght()
{
    int result = 0;
    QList<Prvek*> list;
    list.append(koren);
    koren->SetLast(true);
    while(list.length() != 0)
    {
        ++result;
        if(list[0]->GetLeft() != NULL)
            list.append(list[0]->GetLeft());
        if(list[0]->GetRight() != NULL)
            list.append(list[0]->GetRight());
        list.removeAt(0);
    }
    return result;
}

float Strom::Avg()
{
    return (float)Sum()/Lenght();
}

