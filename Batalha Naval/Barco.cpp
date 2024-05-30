#include "Barco.h"

using namespace std;

void Barco::Iniciar_pontos(int type)
{
    pontos = new PontoNaval[type];
    type_boat = type;
}

Barco::~Barco()
{
    delete[]pontos;
    pontos = NULL;
}

int Barco::get_type_Boat()
{
    if (type_boat <= 0)
    {
        cout << "\nErro N_xxx\n";
        exit(0);
    }
    else
    {
        return type_boat;
    }
}


void Barco::generate_boat(Tabuleiro& tp)
{
    
    if (type_boat <= 0 || type_boat >= 6)
    {
        cout << "\nErro N_xxx\n";
        system("pause");
        exit(0);
    }


    bool atempt = true;

    if (type_boat == 5)
    {
        bool verificar = true;
        while (verificar == true)
        {
            srand(time(NULL));
            Sleep(100);
            bool ver_hor = ((rand() % 1000) % 2) == 0;
            Sleep(100);
            bool dir_esq = ((rand() % 1000) % 2) == 0;
            int l_i = 0, l_f = 0, c_i = 0, c_f = 0;
          
           
            if (ver_hor==true)
            {
                
                //horizental
                if (dir_esq==true)
                {

                    l_f = 0;
                    //virado cima
                    while (l_f<2)
                    {
                        Sleep(100);
                        l_f = rand() % (tp.getDimX());
                        
                    }
                    
                    if (l_f >= 10 || l_f < 2)
                    {
                      
                        system("cls");
                        if (dev_mode == true )
                        {
                            cout << "\n\nO numero l_i e impossivel\n\n ";
                        }
                        else
                        {
                            cout << "\n\nErro N_xxx\n\n";
                        }
                        
                        system("pause");
                        exit(0);
                    }
                    l_i = l_f -2;
                    if (l_i<0)
                    {
                        system("cls");
                        cout << "Erro N_xxx\n\n";
                        system("pause");
                        exit(0);

                    }

                    c_i = rand() % (tp.getDimY() -3);
                    c_f = c_i + 3 - 1;

                    if (dev_mode==true)
                    {

                        cout << "O valor de l_i e =" << l_i << " o valor c_i =" << c_i << " o valor de l_f =" << l_f << " o valor da c_f =" << c_f << " .\n\n";

                    }
                    bool aaa=false;
                   aaa= set_porta(true, true, l_i, c_i, l_f, c_f, tp);

                   if (aaa==true && dev_mode==true)
                   {
                       cout << endl;
                       for (int i = 0; i <10; i++)
                       {
                           for (int j = 0; j < 10; j++)
                           {
                               cout << tp.tabuleiro[i][j] << " ";
                           }
                           cout << endl;

                       }
                      
                       verificar = false;
                   }
              

                }
                else
                {
                    
                    //virado baixo

                    l_i = 10;
                    l_f = 0;
                    c_i = 0;
                    c_f = 0;

                    //virado cima

                    while (l_i >= 8)
                    {
                        Sleep(100);
                        l_i = rand() % (tp.getDimX() );

                    }

                    if (l_i >= 8 || l_i < 0)
                    {

                        system("cls");
                        if (dev_mode == true)
                        {
                            cout << "\n\nO numer l_i e impossivel\n\n ";
                        }
                        else
                        {
                            cout << "\n\nErro N_xxx\n\n";
                        }

                        system("pause");
                        exit(0);
                    }
                    l_f = l_i + 2;
                    if (l_f >= 10)
                    {
                        system("cls");
                        cout << "Erro N_xxx\n\n";
                        system("pause");
                        exit(0);

                    }

                    c_i = rand() % (tp.getDimY() - 3);
                    c_f = c_i + 3 - 1;

                    if (dev_mode == true)
                    {

                        cout << "O valor de l_i e =" << l_i << " o valor c_i =" << c_i << " o valor de l_f =" << l_f << " o valor da c_f =" << c_f << " .\n\n";

                    }
                    bool aaa = false;
                    aaa = set_porta(true, false, l_i, c_i, l_f, c_f, tp);

                    if (aaa == true && dev_mode==true)
                    {
                        cout << endl;
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                cout << tp.tabuleiro[i][j] << " ";
                            }
                            cout << endl;
                        }
                        verificar = false;
                    }
                }
            }
            else
            {
                
                //vertical
                if (dir_esq == true)
                {
                    //virado direita
                    c_i = 10;
                    while (c_i>7)
                    {
                        Sleep(200);
                        c_i = rand() % tp.getDimY();
                    }
                    if (c_i+2>=10)
                    {
                        system("cls");
                        cout << "\nErro N_xxx\n" << endl;
                        system("pause");
                        exit(0);

                    }
                    c_f = c_i + 2;

                    Sleep(200);
                    l_i = rand() % (tp.getDimY() - 3);
                    l_f = l_i + 3 - 1;
                    if (dev_mode == true)
                    {

                        cout << "O valor de l_i e =" << l_i << " o valor c_i =" << c_i << " o valor de l_f =" << l_f << " o valor da c_f =" << c_f << " .\n\n";

                    }
                    verificar = set_porta(false, true, l_i, c_i, l_f, c_f, tp);
                    if (verificar==true)
                    {
                        verificar = false;
                    }
                    else
                    {
                        verificar = true;
                    }   
                }
                else
                {
                    //virado esquerda
                    c_f = 0;
                    while (c_f < 2)
                    {
                        Sleep(200);
                        c_f = rand() % tp.getDimY();
                    }
                    if (c_f - 2 < 0)
                    {
                        system("cls");
                        cout << "\nErro N_xxx\n" << endl;
                        system("pause");
                        exit(0);

                    }
                    c_i = c_f - 2;

                    Sleep(20);
                    l_i = rand() % (tp.getDimY() - 3);
                    l_f = l_i + 3 - 1;
                    if (dev_mode == true)
                    {

                        cout << "O valor de l_i e =" << l_i << " o valor c_i =" << c_i << " o valor de l_f =" << l_f << " o valor da c_f =" << c_f << " .\n\n";

                    }
                    verificar = set_porta(false, false, l_i, c_i, l_f, c_f, tp);
                    if (verificar == true)
                    {
                        verificar = false;
                    }
                    else
                    {
                        verificar = true;
                    }
                }
            }
        }
    }
    else
    {
        int l_i = 0, c_i = 0, l_f = 0, c_f = 0;
        bool verificador = true;

        do
        {
            srand(time(NULL));
            //tp = tabuleiro do inim. (bot)
            
            Sleep(50);
            if ((1 + rand() % 1000) % 2 == 0)
            {
                
                    Sleep(105);
                    l_i = rand() % tp.getDimX();
                    l_f = l_i;
                    Sleep(105);
                    c_i = rand() % (tp.getDimY() - type_boat);
                    c_f = c_i + type_boat - 1;

                   

               
                verificador = verifica_gerar(tp, l_i, c_i, l_f, c_f, true);

               
            }
            else
            {
                    Sleep(105);

                    l_i = rand() % (tp.getDimX() - type_boat);
                    l_f = l_i + type_boat - 1;
                    Sleep(105);
                    c_i = rand() % tp.getDimY();
                    c_f = c_i;

                verificador = verifica_gerar(tp, l_i, c_i, l_f, c_f, false);

            }




        } while (verificador == true);

        if (dev_mode == true)
        {
            cout << "\n\n";
            for (int i = 0; i < tp.getDimX(); i++)
            {
                for (int j = 0; j < tp.getDimY(); j++)
                {
                    cout << "   " << tp.tabuleiro[i][j];
                }
                cout << endl;
            }
        }
    }
    if (dev_mode==true)
    {
        system("pause");
    }
}



bool Barco::verifica_gerar(Tabuleiro& tp, int l_i, int c_i, int l_f, int c_f, bool direcao)
{
    bool verificador = true;
    switch (direcao)
    {
        case true:
        {

            if (c_f >= tp.getDimY())
            {
                cout << "\nErro N_xxx\n";
                system("pause");
            }
            else
            {
                if (dev_mode == true)
                {
                    cout << "l_i=" << l_i << "  l_f=" << l_f << "  c_i=" << c_i << "  c_f=" << c_f << "  type=" << type_boat << "\n\n";
                    system("pause");
                }

                int contador = 0;
                for (int i = c_i; i <= c_f; i++)
                {
                    if (tp.tabuleiro[l_i][i] == '.')
                    {
                        contador++;
                    }
                }

                if (contador == type_boat)
                {
                    int contador_2 = 0;

                    if (dev_mode == true)
                    {
                        cout << "\nLivre, verificar dos lados\n";

                    }

                    //develop mode
                    char tabuleiro_2[10][10];

                    for (int k = 0; k < 10; k++)
                    {
                        for (int i = 0; i < 10; i++)
                        {
                            tabuleiro_2[k][i] = '.';
                        }
                    }

                    bool verificar_2 = true;

                    for (int i = c_i; i <= c_f; i++)
                    {
                        if (l_i - 1 >= 0)
                        {
                            if (l_i == tp.getDimX() - 1)
                            {
                                if (tp.tabuleiro[l_i - 1][i] == '.')
                                {
                                    contador_2++;
                                    tabuleiro_2[l_i - 1][i] = '@';
                                }
                                else
                                {
                                    verificar_2 = false;
                                }
                            }
                            else
                            {

                                if (tp.tabuleiro[l_i - 1][i] == '.')
                                {
                                    tabuleiro_2[l_i - 1][i] = '@';
                                    contador_2++;
                                }
                                else
                                {
                                    verificar_2 = false;
                                }
                                if (tp.tabuleiro[l_i + 1][i] == '.')
                                {
                                    tabuleiro_2[l_i + 1][i] = '@';
                                    contador_2++;
                                }
                                else
                                {
                                    verificar_2 = false;
                                }
                            }
                        }
                        else
                        {
                            if (tp.tabuleiro[l_i + 1][i] == '.')
                            {
                                contador_2++;
                                tabuleiro_2[l_i + 1][i] = '@';
                            }
                            else
                            {
                                verificar_2 = false;
                            }

                        }
                    }

                    if ((contador_2 == type_boat && verificar_2 == true) || (contador_2 == (2 * type_boat) && verificar_2 == true))
                    {
                        contador = 0;
                        if (c_i > 0 && c_f < tp.getDimY() - 1)
                        {
                            if (tp.tabuleiro[l_i][c_i - 1] == '.')
                            {
                                tabuleiro_2[l_i][c_i - 1] = '@';
                                contador++;
                            }

                            if (tp.tabuleiro[l_i][c_f + 1] == '.')
                            {

                                tabuleiro_2[l_i][c_f + 1] = '@';

                                contador++;
                            }
                            if (contador == 2)
                            {
                                if (dev_mode == true)
                                {
                                    cout << "\nLivre dos lados\n";
                                }

                                contador = 666;
                            }
                        }
                        else
                        {
                            if (c_i == 0)
                            {

                                if (tp.tabuleiro[l_i][c_f + 1] == '.')
                                {
                                    tabuleiro_2[l_i][c_f + 1] = '@';

                                    contador++;
                                }
                            }
                            else
                            {
                                if (dev_mode == true)
                                {
                                    cout << endl << c_i << endl;

                                }
                                if (tp.tabuleiro[l_i][c_i - 1] == '.')
                                {
                                    tabuleiro_2[l_i][c_i - 1] = '@';

                                    contador++;
                                }
                            }
                            if (contador == 1)
                            {
                                if (dev_mode == true)
                                {
                                    cout << "\nlivre dos lados\n";

                                }

                                contador = 666;
                            }

                        }
                        if (contador == 666)
                        {
                            int count = 0;
                            bool nova = false;
                            for (int j = c_i; j <= c_f; j++)
                            {
                                if (dev_mode == true)
                                {
                                    cout << "\n\nO valor de j:" << j << "\nO valor de count:" << count << endl;
                                }
                                tp.tabuleiro[l_i][j] = 'O';

                                nova = pontos[count].Setl(l_i);
                                if (nova == false)
                                {
                                    system("cls");
                                    cout << "\nErro N_XXX" << endl;
                                    system("pause");
                                    exit(0);

                                }
                                nova = pontos[count].Setc(j);
                                if (nova == false)
                                {
                                    system("cls");
                                    cout << "\nErro N_XXX" << endl;
                                    system("pause");
                                    exit(0);

                                }
                                count++;

                                verificador = false;
                            }
                        }
                    }
                    if (dev_mode == true)
                    {
                        cout << "\n\n\n Olhar à volta \n\n\n";
                        for (int i = 0; i < tp.getDimX(); i++)
                        {
                            for (int j = 0; j < tp.getDimY(); j++)
                            {
                                cout << "  " << tabuleiro_2[i][j];
                            }
                            cout << endl;

                        }
                        cout << "\n\n";
                        system("pause");

                    }




                }
            }

            return verificador;

            break;
        }

        case false:
        {

            if (l_f >= tp.getDimY())
            {
                cout << "\nErro N_xxx\n";
                system("pause");
            }
            else
            {
                if (dev_mode == true)
                {
                    cout << "l_i=" << l_i << "  l_f=" << l_f << "  c_i=" << c_i << "  c_f=" << c_f << "  type=" << type_boat << "\n\n";
                    system("pause");
                }

                int contador = 0;

                //develop mod
                char tabuleiro_2[10][10];
                for (int k = 0; k < 10; k++)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        tabuleiro_2[k][i] = '.';
                    }

                }

                for (int i = l_i; i <= l_f; i++)
                {
                    if (tp.tabuleiro[i][c_i] == '.')
                    {
                        contador++;
                    }
                }
                if (contador == type_boat)
                {
                    int contador_2 = 0;
                    if (dev_mode == true)
                    {
                        cout << "\nLivre, verificar dos lados\n";

                    }
                    bool verificar_2 = true;
                    for (int i = l_i; i <= l_f; i++)
                    {
                        if (c_i - 1 >= 0)
                        {
                            if (c_i == tp.getDimX() - 1)
                            {
                                if (tp.tabuleiro[i][c_i - 1] == '.')
                                {
                                    tabuleiro_2[i][c_i - 1] = '@';
                                    contador_2++;
                                }
                                else
                                {
                                    verificar_2 = false;
                                }


                            }
                            else
                            {
                                if (tp.tabuleiro[i][c_i - 1] == '.')
                                {
                                    tabuleiro_2[i][c_i - 1] = '@';
                                    contador_2++;
                                }
                                else
                                {
                                    verificar_2 = false;
                                }

                                if (tp.tabuleiro[i][c_i + 1] == '.')
                                {
                                    tabuleiro_2[i][c_i + 1] = '@';
                                    contador_2++;
                                }
                                else
                                {
                                    verificar_2 = false;
                                }
                            }
                        }
                        else
                        {
                            if (tp.tabuleiro[i][c_i + 1] == '.')
                            {
                                tabuleiro_2[i][c_i + 1] = '@';
                                contador_2++;
                            }
                            else
                            {
                                verificar_2 = false;
                            }
                        }
                    }
                    if ((contador_2 == type_boat && verificar_2 == true) || (contador_2 == (2 * type_boat) && verificar_2 == true))
                    {
                        contador = 0;
                        if (l_i > 0 && l_f < tp.getDimX() - 1)
                        {
                            if (tp.tabuleiro[l_i - 1][c_i] == '.')
                            {
                                contador++;
                                tabuleiro_2[l_i - 1][c_i] = '@';
                            }
                            if (tp.tabuleiro[l_f + 1][c_i] == '.')
                            {
                                contador++;
                                tabuleiro_2[l_f + 1][c_f] = '@';
                            }
                            if (contador == 2)
                            {
                                if (dev_mode == true)
                                {
                                    cout << "\nLivre dos lados\n";
                                }
                                contador = 666;
                            }
                        }
                        else
                        {
                            if (l_i == 0)
                            {

                                if (tp.tabuleiro[l_f + 1][c_i] == '.')
                                {
                                    tabuleiro_2[l_f + 1][c_i] = '@';
                                    contador++;
                                }
                            }
                            else
                            {
                                cout << endl << c_f << endl;
                                if (tp.tabuleiro[l_i - 1][c_i] == '.')
                                {
                                    tabuleiro_2[l_i - 1][c_i] = '@';
                                    contador++;
                                }
                            }
                            if (contador == 1)
                            {
                                if (dev_mode == true)
                                {
                                    cout << "\nlivre dos lados\n";

                                }
                                contador = 666;

                            }

                        }
                        if (contador == 666)
                        {
                            int count = 0;
                            bool nova = false;
                            for (int j = l_i; j <= l_f; j++)
                            {

                                tp.tabuleiro[j][c_i] = 'O';

                                if (dev_mode == true)
                                {
                                    cout << "\n\nO valor de j:" << j << "\nO valor de count:" << count << endl;
                                }



                                nova = pontos[count].Setl(j);
                                if (nova == false)
                                {
                                    system("cls");
                                    cout << "\nErro N_XXX" << endl;
                                    system("pause");
                                    exit(0);

                                }
                                nova = pontos[count].Setc(c_i);
                                if (nova == false)
                                {
                                    system("cls");
                                    cout << "\nErro N_XXX" << endl;
                                    system("pause");
                                    exit(0);

                                }
                                count++;


                            }
                            verificador = false;
                        }
                    }
                    if (dev_mode == true)
                    {
                        cout << "\n\n\n OLhar a volta \n\n\n";
                        for (int i = 0; i < tp.getDimX(); i++)
                        {
                            for (int j = 0; j < tp.getDimY(); j++)
                            {
                                cout << "   " << tabuleiro_2[i][j];
                            }
                            cout << endl;

                        }
                        cout << "\n\n";
                        system("pause");
                    }
                }
            }

            return verificador;
            break;
        }
       
    }
}





void Barco::set_Dev_mode(bool Dev_mode)
{
    dev_mode = Dev_mode;
}





void Barco::set_user_boat(Tabuleiro& t1, Tabuleiro& t2)
{
    bool verificar = true;
    int direction = -123;
    int l = 0;
    char c = '@';

    int guarda = -57;
    char letras[10] = { 'a','b','c','d','e','f','g','h','i','j' };
    char letras_g[10] = { 'A','B','C','D','E','F','G','H','I','J' };

    int porta_variable = 0;

    while (verificar == true)
    {
        
        short int p = 0;
        if (type_boat > 1)
        {
            int k=0;
            while (k != 80 && k != 72 && k != 75 && k != 77)
            {
                desenhar_essencial(t1, t2);

                if (type_boat==5)
                {

                    cout << "Qual a direcao do porta-avioes =" << type_boat << ")? (use as setas de direcao)";

                }
                else
                {
                    cout << "Qual a direcao do navio (Tamanho do navio=" << type_boat << ")? (use as setas de direcao)";

                }

                _getch();
                k = _getch();
                if (k == 80 || k == 72)
                {
                    direction = 2;
                    desenhar_essencial(t1, t2);

                }
                else if (k == 75 || k == 77)
                {
                    direction = 1;
                    desenhar_essencial(t1, t2);
                }
                else
                {
                    desenhar_essencial(t1, t2);
                    cout << "Erro...direcao " << k << " invalida";
                    Sleep(5000);
                    desenhar_essencial(t1, t2);

                }

                if (type_boat == 5)
                {
                    bool verificar_por = false;
                    
                    while (verificar_por == false)
                    {
                        if (direction == 1)
                        {
                            cout << "Ponta virada para cima ou baixo? (use as setas de direcao)";
                            _getch();
                            porta_variable = _getch();
                            if (porta_variable == 80)
                            {
                                p = 0;
                                verificar_por = true;
                            }
                            else
                            {
                                if (porta_variable==72)
                                {
                                    p = 1;
                                    verificar_por = true;
                                }
                                else
                                {
                                    desenhar_essencial(t1,t2);
                                    cout << "Erro... volte a selecionar uma seta...";
                                    Sleep(5000);
                                    desenhar_essencial(t1, t2);
                                }
                               
                            }

                        }
                        else
                        {
                            cout << "Ponta virada para direita ou esquerda? (use as setas de direcao)";
                            _getch();
                            porta_variable = _getch();
                            if (porta_variable == 75) 
                            {
                                p = 2;
                                verificar_por = true;
                            }
                            else
                            {
                                if (porta_variable == 77)
                                {
                                    p = 3;
                                    verificar_por = true;
                                }
                                else
                                {
                                    desenhar_essencial(t1, t2);
                                    cout << "Erro... volte a selecionar uma seta...";
                                    Sleep(5000);
                                    desenhar_essencial(t1, t2);
                                }
                            }
                        }
                    }
                }
            }
        }

        bool verificador_2 = true;
        while (verificador_2 == true)
        {
            desenhar_essencial(t1,t2);
            gotoxy(26, 31);
            cout << "                                                                                               ";
            gotoxy(26, 31);
            if (type_boat == 5)
            {
                cout << "Qual a linha que deseja iniciar o porta_avioes (Tamanho do barco=" << type_boat << ")(Coloque as cordenadas do meio do navio) ?";

            }
            else
            {
                cout << "Qual a linha que deseja iniciar o barco (Tamanho do barco=" << type_boat << ") ?";
            }
            cin >> l;
            gotoxy(31, 31);

            if (l <= 10 && l >= 1)
            {
                desenhar_essencial(t1, t2);
                cout << "Qual e a coluna que deseja iniciar o barco (Tamanho do barco=" << type_boat << ") ?";
                cin >> c;
                for (int a = 0; a < 10; a++)
                {
                    if (letras[a] == c)
                    {

                        verificador_2 = false;
                        guarda = a;
                    }
                }
                if (guarda == -57)
                {
                    for (int a = 0; a < 10; a++)
                    {
                        if (letras_g[a] == c)
                        {
                            verificador_2 = false;
                            guarda = a;
                        }
                    }
                    if (guarda == -57)
                    {
                        l = 0;
                        c = '@';
                        desenhar_essencial(t1, t2);
                        cout << "As letras tem que estar contindas entre a e j inclusive.";
                        Sleep(5000);
                    }
                }
            }
            else
            {
                guarda = -57;
                l = 0;
                c = '@';
                desenhar_essencial(t1, t2);
                cout << "O numero tem que estar contido entre [1,10]";
                Sleep(5000);
            }
        }
        
        int variavel_sec = 0;
        int contador = 0;
        bool verificar_2 = false;
        int c_i = 0, c_f = 0, l_i = 0, l_f = 0;
        l = l - 1;
        if (type_boat == 5)
        {
            switch (p)
            {
                case 0:
                {

                    l_i = l;
                    c_i = guarda - 1;
                    c_f = guarda + 1;

                    l_f = l + 2;
                    if (l_i<0 || l_f >=10 || c_i<0 || c_f>=10)
                    {
                        desenhar_essencial(t1, t2);
                        cout << "Cordenadas impossiveis...(3s)";
                        Sleep(3000);
                        
                    }
                    else
                    {
                        verificador_2=set_porta(true,false,l_i,c_i,l_f,c_f,t1);
                    }
                    break;
                }


                case 1:
                {
                    l_f = l;
                    c_i = guarda - 1;
                    c_f = guarda + 1;
                    l_i = l - 2;

                    if (l_i < 0 || l_f >= 10 || c_i < 0 || c_f >= 10)
                    {
                        desenhar_essencial(t1, t2);
                        cout << "Cordenadas impossiveis..(3s).";
                        Sleep(3000);
                    }
                    else
                    {
                        verificador_2=set_porta(true, true, l_i, c_i, l_f, c_f, t1);
                    }

                    break;
                }
                case 2:
                {
                    //vertical

                    //esquerda 
                    c_i = guarda - 2;
                    l_i = l - 1;
                    l_f = l + 1;
                    c_f = guarda;
                    if (l_i < 0 || l_f >= 10 || c_i < 0 || c_f >= 10)
                    {
                        desenhar_essencial(t1, t2);
                        cout << "Cordenadas impossiveis..(3s).";
                        Sleep(3000);

                    }
                    else
                    {
                        verificador_2 = set_porta(false, false, l_i, c_i, l_f, c_f, t1);
                    }

                    break;
                }
                case 3:
                {
                    //vertical

                    //direita

                    c_i = guarda;
                    l_i = l - 1;
                    l_f = l + 1;
                    c_f = guarda+2;

                    if (l_i < 0 || l_f >= 10 || c_i < 0 || c_f >= 10)
                    {
                        desenhar_essencial(t1, t2);
                        cout << "Cordenadas impossiveis..(3s).";
                        Sleep(3000);

                    }
                    else
                    {
                        verificador_2 = set_porta(false, true, l_i, c_i, l_f, c_f, t1);
                    }

                    break;
                }

                default:
                {
                    break;
                }
                    
            }
            if (verificador_2==true)
            {
                verificar = false;
            }
        }
        else
        {
            switch (direction)
            {
            case -123:
            {
                l_i = l;
                c_i = guarda;

                l_f = l;
                c_f = guarda;
                verificar = verifica_gerar(t1, l_i, c_i, l_f, c_f, true);
                if (verificar == true)
                {
                    desenhar_essencial(t1, t2);
                    cout << "O local que esta a tentar colocar ja esta oucupado ou tem um barco/submarino muito perto...(5s)";
                    Sleep(5000);
                    cout << "                                                                                               ";
                }
                break;
            }

            case 1:
            {
                l_i = l;
                c_i = guarda;

                l_f = l;
                c_f = guarda + type_boat - 1;


                verificar = verifica_gerar(t1, l_i, c_i, l_f, c_f, true);

                if (verificar == true)
                {
                    desenhar_essencial(t1, t2);
                    cout << "O local que esta a tentar colocar ja esta oucupado ou tem um barco/submarino muito perto...(5s)";
                    Sleep(5000);
                    cout << "                                                                                               ";
                }

                break;
            }
            case 2:
            {
                l_i = l;
                c_i = guarda;

                l_f = l + type_boat - 1;
                c_f = guarda;


                verificar = verifica_gerar(t1, l_i, c_i, l_f, c_f, false);

                if (verificar == true)
                {
                    desenhar_essencial(t1, t2);
                    cout << "O local que esta a tentar colocar ja esta oucupado ou tem um barco/submarino muito perto...(5s)";
                    Sleep(5000);
                    cout << "                                                                                               ";
                }

                break;
            }

            default:
            {
                cout << "Erro N_xxx\n\n\n";
                system("pause");
                exit(0);
                break;
            }
            }
        }
    }
}




void Barco::desenhar_essencial(Tabuleiro& t1, Tabuleiro& t2)
{
    system("cls");
    gotoxy(75, 0);
    t2.Draw(75, 5, false);
    gotoxy(0, 0);
    t1.Draw(27, 5, true);

    gotoxy(26, 3);
    cout << nome;
    gotoxy(110, 3);
    cout << "COMPUTADOR";
    showRectAt(25, 4, 48, 24);
    showRectAt(73, 4, 48, 24);

    show90RectAt(25, 30, 10, 48);
    gotoxy(26, 31);
}




void Barco::set_name(string name)
{
    nome = name;

}


bool Barco::get_destroid()
{
    return destruido;
}


void Barco::set_destruido()
{
    int contador = 0;
    for (int i = 0; i < type_boat; i++)
    {
        if (pontos[i].get_des() == true)
        {
            contador++;
        }
    }
    if (contador == type_boat)
    {
        destruido = true;
    }

}

bool Barco::set_porta(bool hor_ver,bool sentido, int l_i, int c_i,int l_f ,int c_f, Tabuleiro& tb)
{
    if (l_i==l_f || c_i==c_f)
    {
        system("cls");
        cout << "Erro N_xxxx\n\n";
        system("pause");
        exit(0);
    }

    //contador
    char tabuleiro_dev[10][10];
    if (dev_mode==true)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                tabuleiro_dev[i][j] = '.';
            }
        }
    }
    int contador = 0;
    bool verificar = true;

    bool ter_acerteza = false;

 
    if (hor_ver==true)
    {
       
        for (int i = c_i; i <= c_f; i++)
        {
            if (tb.tabuleiro[l_f][i]=='.' && sentido==true)
            {
                contador++;
            }
            else
            {
                if (tb.tabuleiro[l_i][i] == '.' && sentido == false)
                {
                    contador++;
                }
            }
        }
        
        if (contador==3)
        {
            if (sentido == true)
            {
                for (int i = l_i; i < l_f; i++)
                {
                    if (tb.tabuleiro[i][c_i + 1] == '.')
                    {
                        contador++;
                    }
                }
                if (contador==5)
                {
                    contador = 0;
                    for (int i = c_i; i <= c_f; i++)
                    {
                        if (tb.tabuleiro[l_f-1][i]=='.')
                        {
                            contador++;
                            if (c_i+1 != i)
                            {
                                tabuleiro_dev[l_f - 1][i] = '@';
                            }
                            
                        }
                        else
                        {
                            verificar = false;
                        }
                 
                    }
                    if (l_f != 9)
                    {
                        for (int i = c_i; i <= c_f; i++)
                        {
                            if (tb.tabuleiro[l_f+1][i]=='.')
                            {
                                contador++;
                                
                                tabuleiro_dev[l_f + 1][i] = '@';
                                
                                
                            }
                            else
                            {
                                verificar = false;
                            }
                            
                        }
                    }   
                    if ((contador==3 || contador==6) && (verificar==true))
                    {
                        contador = 0;
                        verificar = false;
                        if (c_i==0 || c_f==9)
                        {
                            if (c_i==0)
                            {
                                if (tb.tabuleiro[l_f][c_f + 1] == '.')
                                {
                                    contador++;
                                    tabuleiro_dev[l_f][c_f + 1] = '@';
                                    verificar = true;
                                }
                                else
                                {
                                    verificar = false;
                                }
                            }
                            else
                            {
                                if (c_f==9)
                                {
                                    if (tb.tabuleiro[l_f][c_i - 1] == '.')
                                    {
                                        contador++;
                                        tabuleiro_dev[l_f][c_i - 1] = '@';
                                        verificar = true;
                                    }
                                    else
                                    {
                                        verificar = false;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (tb.tabuleiro[l_f][c_i-1]=='.')
                            {
                                tabuleiro_dev[l_f][c_i - 1] = '@';
                                contador++;
                                verificar = true;
                            }
                            else
                            {
                                verificar = false;
                            }
                            if (tb.tabuleiro[l_f][c_f + 1] == '.' && verificar==true)
                            {
                                tabuleiro_dev[l_f][c_f + 1] = '@';
                                contador++;
                                verificar = true;
                            }
                            else
                            {
                                verificar = false;
                            }
                           
                        }


                        if (contador == 2 && verificar == true)
                        {
                            contador = 0;
                            verificar = true;
                            for (int i = l_i; i < l_f; i++)
                            {
                                if (tb.tabuleiro[i][c_i] == '.')
                                {
                                    contador++;
                                    tabuleiro_dev[i][c_i] = '@';
                                }
                                else
                                {
                                    verificar = false;
                                }
                                if (tb.tabuleiro[i][c_f] == '.')
                                {
                                    contador++;
                                    tabuleiro_dev[i][c_f] = '@';
                                }
                                else
                                {
                                    verificar = false;
                                }
                            }
                            if (contador == 4 && verificar == true)
                            {
                                contador = 0;
                                verificar = false;
                               
                                if (l_i != 0)
                                {
                                    if (tb.tabuleiro[l_i - 1][c_i + 1] == '.')
                                    {
                                        contador = 666;
                                        tabuleiro_dev[l_i - 1][c_i + 1] = '@';
                                    }
                                    else
                                    {
                                        contador = 666;
                                    }
                                    
                                }
                                else
                                {
                                    contador = -666;
                                }
                            }
                            else
                            {
                                contador = 666;
                            }
                            if (contador == 666)
                            {
                                ter_acerteza = true;
                                for (int i = c_i; i <= c_f; i++)
                                {
                                    tb.tabuleiro[l_f][i] = 'O';
                                }
                                for (int i = l_i; i < l_f; i++)
                                {
                                    tb.tabuleiro[i][c_i + 1] = 'O';
                                }
                                contador = 0;
                                int zz = 0;
                                for (int i = 0; i < 5; i++)
                                {
                                    if (i>2)
                                    {
                                       
                                        pontos[i].Setc(c_i + 1);
                                        pontos[i].Setl(l_i + zz);
                                        zz++;
                                        

                                    }
                                    else
                                    {
                                        pontos[i].Setl(l_f);
                                        pontos[i].Setc(c_i + contador);
                                        contador++;

                                    }
                                    

                                }
                                verificar = true;
                            }
                        }
                        else
                        {
                            verificar = false;
                        }
                               
                               
                               
                            
                        
                    }
                    else
                    {
                        verificar = false;
                    }

                   

                }
                else
                {
                     verificar = false;
                }
            }
            else
            {
                for (int i = l_i+1; i <= l_f; i++)
                {
                    if (tb.tabuleiro[i][c_i + 1] == '.')
                    {
                        contador++;
                    }
                }
                if (contador == 5)
                {
                    contador = 0;

                    for (int i = c_i; i <= c_f; i++)
                    {
                       if (tb.tabuleiro[l_i+1][i] == '.')
                       {
                            contador++;
                            if (c_i + 1 != i)
                            {
                                 tabuleiro_dev[l_i + 1][i] = '@';
                            }

                       }
                       else
                       {
                           verificar = false;
                       }

                    }
                    

                    if (l_i!=0)
                    {
                        for (int i = c_i; i <= c_f; i++)
                        {
                            if (tb.tabuleiro[l_i - 1][i] == '.')
                            {
                                contador++;
                                
                                tabuleiro_dev[l_i - 1][i] = '@';
                                

                            }
                            else
                            {
                                verificar = false;
                            }

                        }
                    }
                    
                    




                    if ((contador == 3 || contador == 6) && (verificar == true))
                    {
                        contador = 0;
                        verificar = false;
                        if (c_i == 0 || c_f == 9)
                        {
                            if (c_i == 0)
                            {
                                if (tb.tabuleiro[l_i][c_f + 1] == '.')
                                {
                                    contador++;
                                    tabuleiro_dev[l_i][c_f + 1] = '@';
                                    verificar = true;
                                }
                                else
                                {
                                    verificar = false;
                                }
                            }
                            else
                            {
                                if (c_f == 9)
                                {
                                    if (tb.tabuleiro[l_i][c_i - 1] == '.')
                                    {
                                        contador++;
                                        tabuleiro_dev[l_i][c_i - 1] = '@';
                                        verificar = true;
                                    }
                                    else
                                    {
                                        verificar = false;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (tb.tabuleiro[l_i][c_i - 1] == '.')
                            {
                                tabuleiro_dev[l_i][c_i - 1] = '@';
                                contador++;
                                verificar = true;
                            }
                            else
                            {
                                verificar = false;
                            }
                            if (tb.tabuleiro[l_i][c_f + 1] == '.' && verificar == true)
                            {
                                tabuleiro_dev[l_i][c_f + 1] = '@';
                                contador++;
                                verificar = true;
                            }
                            else
                            {
                                verificar = false;
                            }

                        }


                        if (contador == 2 && verificar == true)
                        {
                            contador = 0;
                            verificar = true;
                            for (int i = l_i + 1; i <= l_f; i++)
                            {
                                if (tb.tabuleiro[i][c_i] == '.')
                                {
                                    contador++;
                                    tabuleiro_dev[i][c_i] = '@';
                                }
                                else
                                {
                                    verificar = false;
                                }
                                if (tb.tabuleiro[i][c_f] == '.')
                                {
                                    contador++;
                                    tabuleiro_dev[i][c_f] = '@';
                                }
                                else
                                {
                                    verificar = false;
                                }
                            }
                            if (contador == 4 && verificar == true)
                            {
                                contador = 0;
                                verificar = false;

                                if (l_f != 9)
                                {
                                    if (tb.tabuleiro[l_f + 1][c_i + 1] == '.')
                                    {
                                        contador = 666;
                                        tabuleiro_dev[l_f + 1][c_i + 1] = '@';
                                    }
                                    else
                                    {
                                        contador = -666;
                                    }

                                }
                                else
                                {
                                    contador = 666;
                                }
                            }
                            else
                            {
                                contador = 666;
                            }
                            if (contador == 666)
                            {
                                ter_acerteza = true;
                                for (int i = c_i; i <= c_f; i++)
                                {
                                    tb.tabuleiro[l_i][i] = 'O';
                                }
                                for (int i = l_i + 1; i <= l_f; i++)
                                {
                                    tb.tabuleiro[i][c_i + 1] = 'O';
                                }
                                contador = 0;
                                int zz = 0;
                                for (int i = 0; i < 5; i++)
                                {
                                    if (i > 2)
                                    {

                                        pontos[i].Setc(c_i + 1);
                                        pontos[i].Setl((l_i+1) + zz);
                                        zz++;


                                    }
                                    else
                                    {
                                        pontos[i].Setl(l_i);
                                        pontos[i].Setc(c_i + contador);
                                        contador++;

                                    }


                                }
                                verificar = true;
                            }
                        }
                        else
                        {
                            verificar = false;
                        }





                    }
                    else
                    {
                        verificar = false;
                    }



                }
                else
                {
                    verificar = false;
                }
            }
        }
        else
        {
             verificar = false;
        }

       
    }
    else
    {

        for (int i = l_i; i <= l_f; i++)
        {
            if (tb.tabuleiro[i][c_f] == '.' && sentido == true)
            {
                contador++;
            }
            else
            {
                if (tb.tabuleiro[i][c_i] == '.' && sentido == false)
                {
                    contador++;
                }
                else
                {
                    verificar = false;
                }
            }
        }

        if (sentido==true)
        {
            for (int i = c_i+1; i <= c_f; i++)
            {
                if (tb.tabuleiro[l_i+1][i]=='.')
                {
                    contador++;
                }
            }
            if (contador==5)
            {
                
                contador = 0;
                verificar = true;
                for (int i = l_i; i <= l_f; i++)
                {
                    if (tb.tabuleiro[i][c_i+1]=='.')
                    {
                        if (i != l_i+1)
                        {
                            tabuleiro_dev[i][c_i + 1] = '@';
                            
                        }
                            
                        contador++;
                    }
                    else
                    {
                        verificar = false;
                    }
                }
                if (c_i!=0)
                {
                    for (int i = l_i; i <= l_f; i++)
                    {
                        if (tb.tabuleiro[i][c_i -1] == '.')
                        {
                            tabuleiro_dev[i][c_i - 1] = '@';
    
                            contador++;
                        }
                        else
                        {
                            verificar = false;
                        }
                    }
                }


                if ((contador == 3 || contador == 6) && verificar == true)
                {
                    contador = 0;
                    verificar = true;
                    if (l_i == 0 || l_f == 9)
                    {
                        if (l_i == 0)
                        {
                            if (tb.tabuleiro[l_f + 1][c_i] == '.')
                            {
                                tabuleiro_dev[l_f+1][c_i] = '@';
                                contador++;
                            }
                            else
                            {
                                verificar = false;
                            }
                        }
                        else
                        {
                            if (tb.tabuleiro[l_i - 1][c_i] == '.')
                            {
                                contador++;
                                tabuleiro_dev[l_i - 1][c_i] = '@';
                            }
                            else
                            {
                                verificar = false;
                            }
                        }

                    }
                    else
                    {
                        if (tb.tabuleiro[l_f + 1][c_i] == '.')
                        {
                            contador++;
                            tabuleiro_dev[l_f + 1][c_i] = '@';
                        }
                        else
                        {
                            verificar = false;
                        }

                        if (tb.tabuleiro[l_i - 1][c_i] == '.')
                        {
                            contador++;
                            tabuleiro_dev[l_i - 1][c_i] = '@';
                        }
                        else
                        {
                            verificar = false;
                        }
                    }

                    if (c_f==9)
                    {
                        verificar = true;

                    }
                    else
                    {
                        if (tb.tabuleiro[l_i+1][c_f+1]=='.')
                        {
                            tabuleiro_dev[l_i + 1][c_f +1] = '@';
                            contador++;
                        }
                        else
                        {
                            verificar = false;
                        }
                    }

                    if ((contador==1 || contador==2 || contador==3) && verificar==true )
                    {
                        contador = 0;
                        for (int i = c_i+1; i <= c_f; i++)
                        {
                            if (tb.tabuleiro[l_i][i] == '.')
                            {
                                tabuleiro_dev[l_i][i] = '@';

                                contador++;
                            }
                            else
                            {
                                verificar = false;
                            }

                            if (tb.tabuleiro[l_f][i] == '.')
                            {
                                tabuleiro_dev[l_f][i] = '@';
                                contador++;
                            }
                            else
                            {
                                verificar = false;
                            }


                        }

                        if (contador==4 && verificar==true)
                        {
                            ter_acerteza = true;
                            int zz = 1;
                            contador = 0;
                            for (int i = 0; i < 5; i++)
                            {
                                if (i<3)
                                {
                                    pontos[i].Setc(c_i);
                                    pontos[i].Setl(l_i + contador);
                                    contador++;
                                }
                                else
                                {
                                    pontos[i].Setl(l_i + 1);
                                    pontos[i].Setc(c_i + zz);
                                    zz++;
                                }
                                
                            }
                            for (int i = l_i; i <= l_f; i++)
                            {
                                tb.tabuleiro[i][c_i] = 'O';
                            }
                            for (int i = c_i+1; i <= c_f; i++)
                            {
                                tb.tabuleiro[l_i+1][i] = 'O';
                            }
                        }
                    }
                 
                }
             }
        }
        else
        {
            for (int i = c_i ; i < c_f; i++)
            {
                if (tb.tabuleiro[l_i + 1][i] == '.')
                {
                    contador++;
                }
            }
            if (contador == 5)
            {

                contador = 0;
                verificar = true;
                for (int i = l_i; i <= l_f; i++)
                {
                    if (tb.tabuleiro[i][c_f - 1] == '.')
                    {
                        if (i != l_i + 1)
                        {
                            tabuleiro_dev[i][c_f - 1] = '@';

                        }

                        contador++;
                    }
                    else
                    {
                        verificar = false;
                    }
                }
                if (c_f != 9)
                {
                    for (int i = l_i; i <= l_f; i++)
                    {
                        if (tb.tabuleiro[i][c_f + 1] == '.')
                        {
                            tabuleiro_dev[i][c_f + 1] = '@';

                            contador++;
                        }
                        else
                        {
                            verificar = false;
                        }
                    }
                }


                if ((contador == 3 || contador == 6) && verificar == true)
                {
                    contador = 0;
                    verificar = true;
                    if (l_i == 0 || l_f == 9)
                    {
                        if (l_i == 0)
                        {
                            if (tb.tabuleiro[l_f + 1][c_f] == '.')
                            {
                                tabuleiro_dev[l_f + 1][c_f] = '@';
                                contador++;
                            }
                            else
                            {
                                verificar = false;
                            }
                        }
                        else
                        {
                            if (tb.tabuleiro[l_i - 1][c_f] == '.')
                            {
                                contador++;
                                tabuleiro_dev[l_i - 1][c_f] = '@';
                            }
                            else
                            {
                                verificar = false;
                            }
                        }

                    }
                    else
                    {
                        if (tb.tabuleiro[l_f + 1][c_f] == '.')
                        {
                            contador++;
                            tabuleiro_dev[l_f + 1][c_f] = '@';
                        }
                        else
                        {
                            verificar = false;
                        }

                        if (tb.tabuleiro[l_i - 1][c_f] == '.')
                        {
                            contador++;
                            tabuleiro_dev[l_i - 1][c_f] = '@';
                        }
                        else
                        {
                            verificar = false;
                        }
                    }

                    if (c_i == 0)
                    {
                        verificar = true;
                    }
                    else
                    {
                        if (tb.tabuleiro[l_i + 1][c_i - 1] == '.')
                        {
                            tabuleiro_dev[l_i + 1][c_i - 1] = '@';
                            contador++;
                        }
                        else
                        {
                            verificar = false;
                        }
                    }

                    if ((contador == 1 || contador == 2 || contador == 3) && verificar == true)
                    {
                        contador = 0;
                        for (int i = c_i ; i < c_f; i++)
                        {
                            if (tb.tabuleiro[l_i][i] == '.')
                            {
                                tabuleiro_dev[l_i][i] = '@';

                                contador++;
                            }
                            else
                            {
                                verificar = false;
                            }

                            if (tb.tabuleiro[l_f][i] == '.')
                            {
                                tabuleiro_dev[l_f][i] = '@';
                                contador++;
                            }
                            else
                            {
                                verificar = false;
                            }


                        }

                        if (contador == 4 && verificar == true)
                        {
                            ter_acerteza = true;
                            int zz = 1;
                            contador = 0;
                            for (int i = 0; i < 5; i++)
                            {
                                if (i < 3)
                                {
                                    pontos[i].Setc(c_i);
                                    pontos[i].Setl(l_i + contador);
                                    contador++;
                                }
                                else
                                {
                                    pontos[i].Setl(l_i + 1);
                                    pontos[i].Setc(c_i + zz);
                                    zz++;
                                }

                            }
                            for (int i = l_i; i <= l_f; i++)
                            {
                                tb.tabuleiro[i][c_f] = 'O';
                            }
                            for (int i = c_i; i < c_f; i++)
                            {
                                tb.tabuleiro[l_i + 1][i] = 'O';
                            }
                        }
                        else
                        {
                            verificar = false;
                        }
                    }
                    else
                    {
                        verificar = false;
                    }

                }
                else
                {
                    verificar = false;
                }
            }
            else
            {
                 verificar = false;
            }
        }

    }

    if (dev_mode == true)
    {
        cout << "\n\n Porta aviao =\n\n";
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << tabuleiro_dev[i][j] << " ";
            }
            cout << endl;
        }
    }

    if (verificar==true && ter_acerteza==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}