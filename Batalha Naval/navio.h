#pragma once
#include <algorithm>
#include <time.h>
#include "Tabuleiro.h"
#include "lab.h"
#include "PontoNaval.h"

#include "Barco.h"

using namespace std;

class Navio : public Barco {
    private:
        string nome;

        int type_boat = -10;
        bool dev_mode = false;

        bool destruido = false;


    public:
        Navio();
        ~Navio();
};