#pragma once
#include "PontoNaval.h"

#include "lab.h"
#include <time.h> 


class Tabuleiro
{
private:
    int dimx;
    int dimy;
    bool dev_mode = false;

public:
    char** tabuleiro;

    Tabuleiro();
    Tabuleiro(int mdx, int mdy);
    virtual ~Tabuleiro();

    void setDimX(int mdx);

    void setDimY(int mdy);

    int getDimX();

    int getDimY();

    void setCell(int l, int col, char c)
    {
        tabuleiro[l - 1][col - 1] = c;
    }

    char getCell(int l, int col)
    {
        return tabuleiro[l - 1][col - 1];
    }

    void setCell(PontoNaval P, char c)
    {
        tabuleiro[P.Getc() - 1][P.Getintc() - 1] = c;
    }

    char getCell(PontoNaval P)
    {
        return tabuleiro[P.Getl() - 1][P.Getintc() - 1];
    }

    void SimbolBoxList();

    void DrawFirstLine(int x0, int dxcel);

    void DrawMiddleLine(int x0, int dxcel);

    void DrawDataLine(int line, int x0, int dxcel, bool type);

    void DrawLastLine(int x0, int dxcel);

    void Draw(int x0, int y0, bool type);

    void set_Dev_mode(bool Developer_mode);
};