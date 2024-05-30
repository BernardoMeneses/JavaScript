#pragma once
#include <iostream>
#include <algorithm>
#include <time.h>
#include "Tabuleiro.h"
#include "Jogador.h"
#include <string>

using namespace std;

class Bot
{
	private:
		
		bool dev_mod = false;
		bool hard_mode = false;
		void easy_mod(Tabuleiro& t1, Tabuleiro& t2, Jogador& user);
		void hard_mod(Tabuleiro& t1, Tabuleiro& t2, Jogador& user);
		void desenhar_essencial(Tabuleiro& t1, Tabuleiro& t2, Jogador& s);
		int destruir(Tabuleiro& t1, Tabuleiro& t2, int& l, int& guarda, Jogador& user);
		int hard_mod_locacion[4] = { -257,-257,-257,-257 };
		int save_location[2] = { -57,-57 };
		bool first = true;
	
	public:
		Bot();
		~Bot();
		
		void set_dev(bool dev)
		{
			dev_mod = dev;
		}
		void set_hard_mod(bool hard)
		{
			hard_mode = hard;
		}
		void bot(Tabuleiro& t1, Tabuleiro& t2, Jogador& user);
};

