#pragma once

#include "Jogador.h"
#include "Tabuleiro.h"
#include "Barco.h"
#include <iostream>
#include "Jogador.h"
#include <fstream> 
#include "Bot.h"
#include <string>

using namespace std;



class Jogo
{
private:
    Jogador player1, player2;

    Bot bo;

    bool Dev_mode = false;
    Tabuleiro t1, t2;

    void  Destruir(int l, int guarda);


public:
    Jogo();
    virtual ~Jogo();
    bool Demo();
    void Jogo_Novo();
    virtual bool Save(string file);
    virtual bool Read(string file);




    bool checkCords(int x, int y, int cords[4][2], int pos);
    void gerarBarcos();
    void set_user();
    void set_Dev_mode(bool developer_mode);

    void desenhar_essencial();

    int batalha();

    int vereficao_final();

    void bot();
    void mostrar_legenda();
};