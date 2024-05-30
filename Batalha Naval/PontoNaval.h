#pragma once
#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h> 
#include <stdio.h> 
class PontoNaval
{
private:
    //1 -- 10
    int l = -50;
    bool destruido = false;
    int c = 0;
public:

    PontoNaval();

    PontoNaval(int m_l, char m_c);

    PontoNaval(int m_l, int m_c);

    ~PontoNaval();

    bool Setl(int m_l);


    bool Setc(int m_c);


    int getl()
    {
        return l;
    }

    int getc()
    {
        return c;
    }

    void Ask2Set_PN();

    int Getl() const
    {
        return l;
    }

    char Getc() const
    {
        return c;
    }


    int Getintc();

    bool get_des()
    {
        return destruido;
    }


    void ShowPontoNaval();

    bool operator == (const PontoNaval ponto) const;

    bool operator != (const PontoNaval ponto) const;

    void set_des(bool des);
};