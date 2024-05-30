#include "PontoNaval.h"
#include <iostream>


using namespace std;

PontoNaval::PontoNaval()
{
    l = 1;
    c = 1;
}

PontoNaval::PontoNaval(int m_l, char m_c)
{
    Setl(m_l);
    Setc(m_c);
}

PontoNaval::PontoNaval(int m_l, int m_c)
{
    Setl(m_l);
    Setc(m_c);
}

PontoNaval::~PontoNaval()
{
}


bool PontoNaval::Setl(int m_l)
{
    if (m_l >= 0 && m_l < 10)
    {
        l = m_l;
        return true;
    }
    else
    {
        return false;
    }
}



bool PontoNaval::Setc(int m_c)
{
    if (m_c >= 0 && m_c < 10)
    {
        c = m_c;

        return true;
    }
    else
    {
        return false;
    }
}


int PontoNaval::Getintc()
{
    int aux;
    aux = int(c) - 64;
    return aux;
}


void PontoNaval::Ask2Set_PN() {
    int aux_l;
    char aux_c;

    cout << "Insira um valor de l: ";
    do {
        cin >> aux_l;
    } while (!Setl(aux_l));
    cout << "Insira um valor de c: ";
    do {
        cin >> aux_c;
    } while (!Setc(aux_c));

}

void PontoNaval::ShowPontoNaval()
{
    cout << "(" << Getl() << "," << Getc() << ")" << endl;
}

bool PontoNaval::operator == (const PontoNaval ponto) const
{
    if (Getl() == ponto.Getl() && Getc() == ponto.Getc())
    {
        return true;
    }

    return false;
}

bool PontoNaval::operator != (const PontoNaval ponto) const
{
    if (Getl() != ponto.Getl() || Getc() != ponto.Getc()) {
        return true;
    }

    return false;
}

void PontoNaval::set_des(bool des)
{
    destruido = des;
}