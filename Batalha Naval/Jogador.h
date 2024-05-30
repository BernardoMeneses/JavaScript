#pragma once
#include <iostream>
#include <string>
#include "Barco.h"
#include "navio.h"
#include <cstdlib>

using namespace std;

class Jogador
{
public:

	string nome;

	Barco  submarinos[4], contratorpedeiro[3], cruzador[2];
	Barco couracado;
	Barco  Porta_avioes;
	Jogador();	

	void set_dev(bool develop_mod);

	int get_number_of_boats_intact();

	int Testar_destruido(int l, int c);

	void atulaizar_lista_destruido();

private:

	bool naviosDestruidos[11];
	bool dev_mode = false;
};