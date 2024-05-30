#include <windows.h>
#include <locale.h>
#include <mmsystem.h>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>
#include <iterator>
#include <stdlib.h>
#include <array>
#include <algorithm>
#include "lab.h"
#include "Barco.cpp"
#include "Tabuleiro.cpp"
#include "Jogo.cpp"
#include "Jogador.cpp"
#include "PontoNaval.cpp"
#include <time.h>


using namespace std;

bool Dev_mode = false;
int opcao;
bool intro = true;


void game();
void menu();
void dev_mode();
void sobre();
void andar(int type);



int main() 
{
    
    andar(0);
    return 0;
}
void game() 
{
    system("cls");
    cout << endl;


    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);


    Jogo jogo_1;
    jogo_1.set_Dev_mode(Dev_mode);

    //Jogo Novo
    jogo_1.Jogo_Novo();


}
void dev_mode() 
{
    const double pass = 4250;
    bool vere = false;
    while (vere == false)
    {
        double pass_colo;
        system("cls");
        cout << "Pass:";
        cin >> pass_colo;
        if (pass == pass_colo)
        {
            system("cls");
            cout << "correto" << endl;
            system("pause");
            cout << endl;
            dev_mode = true;
            vere = true;
            game();
        }
        else
        {
            system("cls");
            cout << "errado";
        }
    }
}
void menu() 
{
    system("cls");
    showRectAt(20, 1, 100, 25);
    gotoxy(25, 10);
    cout << "BATALHA NAVAL";
    gotoxy(55, 15);
    cout << "_____________________________________" << endl;
    gotoxy(60, 16);
    cout << "                                     " << endl;
    gotoxy(66, 17);
    cout << "Jogar" << endl;
    gotoxy(66, 18);
    cout << "Carregar Jogo" << endl;
    gotoxy(66, 19);
    cout << "Regras" << endl;
    gotoxy(66, 20);
    cout << "Sair" << endl;
    gotoxy(66, 21);
    cout << "Sobre" << endl;
    gotoxy(66, 22);
    cout << "dev mode" << endl;
    gotoxy(50, 27);
    cout << "Desenvolvido por --> Guilherme Andrade (73475) | Bernardo Meneses (74116)" << endl;
    resetColor();
 
    if (opcao == 1) {
        gotoxy(66, 17);
        setColor(1, 15);
        printf("-> Jogar\n");
        setColor(15, 0);
    }
    else if (opcao == 2) {
        gotoxy(66, 18);
        setColor(1, 15);
        printf("-> Carregar Jogo.\n");
        setColor(15, 0);
    }
    else if (opcao == 3) {
        gotoxy(66, 19);
        setColor(1, 15);
        printf("-> Regras.\n");
        setColor(15, 0);
    }
    else if (opcao == 4) {
        gotoxy(66, 20);
        setColor(1, 15);
        printf("-> Sair.\n");
        setColor(15, 0);
    }
    else if (opcao == 5) {
        gotoxy(66, 21);
        setColor(1, 15);
        printf("-> Sobre\n");
        setColor(15, 0);
    }
    else if (opcao == 6) {
        gotoxy(66, 22);
        setColor(1, 15);
        printf("-> dev mode.\n");
        setColor(15, 0);
    }
}
void sobre() 
{
    system("cls");
    showRectAt(20, 1, 100, 25);
    gotoxy(25, 10);
    cout << "BATALHA NAVAL";
    gotoxy(55, 15);
    cout << "_________________________________" << endl;
    gotoxy(60, 16);
    cout << "                                     " << endl;
    gotoxy(66, 17);
    cout << "Menu Inicial" << endl;
    gotoxy(66, 18);
    cout << "Sair" << endl;
    gotoxy(66, 19);
    if (opcao == 1)
    {
        gotoxy(66, 17);
        setColor(1, 15);
        printf("--> Menu Inicial\n");
        setColor(15, 0);
    }
    else if (opcao == 2)
    {
        gotoxy(66, 18);
        setColor(1, 15);
        printf("--> Sair\n");
        setColor(15, 0);
    }
}
void andar(int type) {
    opcao = 1;
    int op;
    if (type == 0) {
        do {

            menu();
            op = _getch();

            if (op == 80) {
                opcao++;
            }
            if (op == 72) {
                opcao--;
            }
            if (opcao > 6) {
                opcao = 1;
            }

            if (opcao < 1) {
                opcao = 6;
            }
        } while (op != 13);

        switch (opcao) {
        case 1:
            game();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            exit(0);
            break;
        case 5:
            sobre();
            break;
        case 6:
            dev_mode();
            break;
        }
    }
}