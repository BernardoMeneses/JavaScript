#include <iostream>
#include "Tabuleiro.h"

using namespace std;

Tabuleiro::Tabuleiro()
{
    int i = 0, j = 0;
    setDimX(10);
    setDimY(10);

    //jogador 1


    //1 apontador linhas
    tabuleiro = new char* [10];



    //2 apontador colunas 
    for (int i = 0; i < 10; i++)
    {
        tabuleiro[i] = new char[10];
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = '.';
        }
    }
}

Tabuleiro::Tabuleiro(int mdx, int mdy)
{
    dimx = mdx;
    dimy = mdy;
    //jogador 1
    int i = 0, j = 0;

    //1 apontador linhas
    tabuleiro = new char* [mdx];

    //2 apontador colunas 
    for (int i = 0; i < mdx; i++)
    {
        tabuleiro[i] = new char[mdy];
    }

    for (i = 0; i < mdx; i++)
    {
        for (j = 0; j < mdy; j++)
        {
            tabuleiro[i][j] = '.';
        }
    }
}

Tabuleiro::~Tabuleiro()
{
    int i = 0, j = 0;
    for (i = 0; i < dimx; i++)
    {
        delete[] tabuleiro[i];
    }
    delete[] tabuleiro;
    tabuleiro = NULL;

    cout << "\nA matriz tabuleiro 1 foi apagada...\n";
}

void Tabuleiro::setDimX(int mdx)
{
    dimx = mdx;
}

void Tabuleiro::setDimY(int mdy)
{
    dimy = mdy;
}

int Tabuleiro::getDimX()
{
    return dimx;
}

int Tabuleiro::getDimY()
{
    return dimx;
}

void Tabuleiro::SimbolBoxList() {
    cout << endl << endl;
    cout << "tabela ASCII e Extendida para as box";
    cout << endl << endl;

    int tabela[] = {
        185,186,187,188,200,201,202,203,204,206,
        191,192,217,218,179,196,193,194,195,197,221,180,
        45,47,60,62,88,91,92,93,94,95,238,240,
        30,31,176,177,178,219,220,223,254,
        59,123,124,125,143,205,189,190,207,241,242,245,249,46,58,61,127,174,175,145
    };
    int j = 0;

    for (int i = 0; i < 62; i++) {
        cout << tabela[i] << '\t' << (char)tabela[i] << '\t';
        j++;
        if (j == 5) {
            cout << endl << endl;
            j = 0;
        }
    }
}

void Tabuleiro::DrawFirstLine(int x0, int dxcel) {
    int i, j;

    for (i = 0; i < x0 + 2; i++) {
        cout << " ";
    }

    cout << char(218);
    for (i = 0; i < getDimX(); i++) {
        for (j = 0; j < dxcel; j++) {
            cout << char(196);

        }
        if (i < getDimX() - 1) {
            cout << char(194);
        }
    }
    cout << char(191);
}

void Tabuleiro::DrawMiddleLine(int x0, int dxcel) {
    int i = 0, j = 0;

    for (i = 0; i < x0 + 2; i++)
    {
        cout << " ";
    }
    cout << char(195);
    for (i = 0; i < getDimX(); i++)
    {
        for (j = 0; j < dxcel; j++)
        {
            setBackColor(1);
            cout << char(196);
            resetColor();
        }
        if (i < getDimX() - 1) {
            setBackColor(1);
            cout << char(197);
            resetColor();
        }
    }
    cout << char(180);
}

void Tabuleiro::DrawLastLine(int x0, int dxcel)
{
    int i = 0, j = 0;

    for (i = 0; i < x0 + 2; i++)
    {
        cout << " ";
    }
    cout << char(192);
    for (i = 0; i < getDimX(); i++)
    {
        for (j = 0; j < dxcel; j++)
        {
            cout << char(196);

        }
        if (i < getDimX() - 1)
        {
            cout << char(192);
        }
    }
    cout << char(217);
}


void Tabuleiro::DrawDataLine(int line, int x0, int dxcel, bool type) {
    int i = 0;

    for (i = 0; i < x0; i++)
    {
        cout << " ";
    }

    if (line > 9)
    {
        cout << line;
    }
    else {
        cout << line << " ";
    }

    for (i = 1; i <= getDimX(); i++)
    {
        setBackColor(1);
        cout << char(179);
        if (dev_mode == true)
        {
            cout << " " << getCell(line, i) << " ";
        }
        else
        {
            if (type == true)
            {
                cout << " " << getCell(line, i) << " ";
            }
            else
            {
                if (getCell(line, i) == 'O')
                {
                    cout << " " << "." << " ";
                }
                else
                {
                    cout << " " << getCell(line, i) << " ";
                }
            }
        }
        resetColor();
    }
    cout << char(179);
}

void Tabuleiro::Draw(int x0, int y0, bool type)
{

    int i, l, dxtab, dytab, dxcel; // , dycel;
//	dycel = 1;
    dxcel = 3;
    dxtab = 4 * getDimX();
    dytab = 1 * getDimY();

    for (i = 0; i < y0; i++)
    {
        cout << endl;
    }

    for (i = 0; i < x0 + 2; i++)
    {
        cout << " ";
    }

    for (i = 0; i < getDimX(); i++) {
        cout << "  " << char(65 + i) << " ";
    }

    cout << endl;

    //Draw First Line
    DrawFirstLine(x0, dxcel);
    cout << endl;
    DrawDataLine(1, x0, dxcel, type);
    cout << endl;

    //Draw Middle Lines
    for (l = 2; l <= getDimY(); l++) {
        DrawMiddleLine(x0, dxcel);
        cout << endl;
        DrawDataLine(l, x0, dxcel, type);
        cout << endl;
    }

    //Draw Last Line
    DrawLastLine(x0, dxcel);
    cout << endl << endl;
}
void Tabuleiro::set_Dev_mode(bool Dev_mode)
{
    dev_mode = Dev_mode;
}