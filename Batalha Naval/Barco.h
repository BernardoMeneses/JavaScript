#pragma once
#include <iostream>
#include <algorithm>
#include <time.h>
#include "Tabuleiro.h"
#include "lab.h"
#include "PontoNaval.h"
#include <conio.h>




using namespace std;
class Barco
{
private:
    string nome;

    int type_boat = -10;
    bool dev_mode = false;

    bool destruido = false;

public:
    PontoNaval* pontos;

    //l=linha c=coluna

    void Iniciar_pontos(int type);

    ~Barco();

    int get_type_Boat();

    void generate_boat(Tabuleiro& tp);

    bool verifica_gerar(Tabuleiro& tp, int l_i, int c_i, int l_f, int c_f, bool direcao);

    void set_Dev_mode(bool Developer_mode);

    void set_user_boat(Tabuleiro& t1, Tabuleiro& t2);

    void desenhar_essencial(Tabuleiro& t1, Tabuleiro& t2);

    void set_name(string name);

    bool get_destroid();

    void set_destruido();

    bool set_porta(bool hor_ver ,bool sentido, int l_i, int c_i, int l_f, int c_f, Tabuleiro& tb);

    void set_user_porta(Tabuleiro& t1, Tabuleiro& t2);

};
