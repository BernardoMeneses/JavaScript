#include "Bot.h"

void Bot::easy_mod(Tabuleiro& t1, Tabuleiro& t2, Jogador& user)
{
	srand(time(NULL));
	int aa = 0;
	bool k = false;
	while (aa < 3)
	{
		cout << "E a " << aa + 1 << " jogada neste turno...";
		int l = 0;
		int c = 0;

		Sleep(1000);
		l = rand() % t1.getDimX();
		Sleep(550);
		c = rand() % t1.getDimY();
		if (t1.tabuleiro[l][c] == 'O' || t1.tabuleiro[l][c] == '.')
		{

			destruir(t1,t2,l, c,user);
			aa++;
		}

	}
	
}

void Bot::hard_mod(Tabuleiro& t1, Tabuleiro& t2, Jogador& user)
{
	srand(time(NULL));
	int aa = 0;
	bool k = false;
	int n_boat = -50;
	bool continuar = true;
	while (aa < 3)
	{
		cout << "E a " << aa + 1 << " jogada neste turno...";
		int l = 0;
		int c = 0;

		if (first == true)
		{
			Sleep(500);
			l = rand() % t1.getDimX();
			Sleep(550);
			c = rand() % t1.getDimY();
			Sleep(500);
			if (t1.tabuleiro[l][c] == 'O' || t1.tabuleiro[l][c] == '.')
			{


				n_boat=destruir(t1, t2, l, c, user);
				aa++;
				if (t1.tabuleiro[l][c] == 'T')
				{	
					first = false;
					save_location[0] = l;
					save_location[1] = c;
				}


			}
		}
		else
		{
			Sleep(50);
			int contador = 0;
			int var = rand() % 1000;
			for (int i = 0; i < 4; i++)
			{
				if (hard_mod_locacion[i] == -257)
				{
					contador++;
				}
			}
			switch (contador)
			{
				case 4:
				{

					if (n_boat>=0 && n_boat <=3)
					{
						continuar = false;
					}

					if (continuar == true)
					{
						if ((save_location[0]>=1 && save_location[0]<=8) && (save_location[1] >= 1 && save_location[1] <= 8))
						{
							if (t1.tabuleiro[save_location[0]-1][save_location[1]]=='O')
							{
								int x = save_location[0] - 1;
								n_boat=destruir(t1, t2, x, save_location[1], user);
								if (n_boat >=0)
								{
									continuar = false;
								}
							
							}
							else
							{
								int x = save_location[0] - 1;
								destruir(t1, t2, x, save_location[1], user);

								if (dev_mod == true)
								{

								}
							}
						}
						else
						{
							bool ppp[2] ;

							bool esquinas = false;
							switch (save_location[0])
							{
								case 0:
								{
									//l=0

									break;
								}


								case 9:
								{
									//l=9

									break;
								}

								default:
								{
									ppp[0] = true;
									break;
								}
									
							}
							switch (save_location[1])
							{
								case 0:
								{ 
									//c=0

									break;
								}

								case 9:
								{
									//c=9

									break;
								}

								default:
								{
									if (ppp[0]==true)
									{
										system("cls");
										cout << "\nErro N_xxx\n";

										system("pause");
									}
									break;
								}
									
							}

							switch (esquinas)
							{
								case true:
								{

								}

								case false:
								{

								}

								default:
									break;
							}

						}
					}
	
					break;
				}
				case 3:
				{


					break;
				}
				case 2:
				{

					break;
				}
				case 1: 
				{

					break;
				}
				default:
				{
					
					break;
				}	
			}
		}
	}
}

Bot::Bot()
{
}

Bot::~Bot()
{
}

void Bot::bot(Tabuleiro& t1, Tabuleiro& t2, Jogador& user)
{
	
	if (hard_mode==true)
	{
		hard_mod(t1, t2, user);
	}
	else
	{
		 easy_mod(t1,t2,user);
	}

}

int Bot::destruir(Tabuleiro& t1, Tabuleiro& t2,int &l, int &guarda,Jogador &user)
{
	int n_boat = 0;
	if (t1.tabuleiro[l][guarda] == 'O')
	{
		n_boat = user.Testar_destruido(l, guarda);
		if (n_boat == -2)
		{
			t1.tabuleiro[l][guarda] = 'T';
			desenhar_essencial(t1,t2,user);
			cout << "O bot acertou num navio...";
			Sleep(5000);
		}
		else
		{
			if (dev_mod == true)
			{
				system("cls");
				cout << "\n\n N_" << n_boat << endl;
				system("pause");
				desenhar_essencial(t1,t2,user);
			}
			if (n_boat >= 0 && n_boat < 4)
			{
				t1.tabuleiro[l][guarda] = 'T';
				user.submarinos[n_boat].set_destruido();
				desenhar_essencial(t1,t2,user);
				cout << "O submarino numero " << n_boat + 1 << " foi destruido...";

				Sleep(5000);
			}
			else
			{
				if (n_boat >= 4 && n_boat < 7)
				{
					t1.tabuleiro[l][guarda] = 'T';
					if (dev_mod == true)
					{
						system("cls");
						cout << "\n\ncontratorpedeiro numero no vetor= " << n_boat - 4 << "\n\n" << endl;
						system("pause");
						system("cls");
					}
					user.contratorpedeiro[n_boat - 4].set_destruido();
					if (user.contratorpedeiro[n_boat - 4].get_destroid() == false)
					{
						system("cls");
						cout << "\n\nSuper Erro_xxxx\n" << endl;
						system("pause");
						exit(0);
					}
					desenhar_essencial(t1,t2,user);
					cout << "O contratorpedeiro numero " << n_boat - 3 << " foi destruido";
					Sleep(5000);


				}
				else
				{
					if (n_boat >= 7 && n_boat < 9)
					{
						t1.tabuleiro[l][guarda] = 'T';
						if (dev_mod == true)
						{
							system("cls");
							cout << "\n\ncruzador numero no vetor= " << n_boat - 7 << "\n\n" << endl;
							system("pause");
							system("cls");
						}
						user.cruzador[n_boat - 7].set_destruido();
						desenhar_essencial(t1,t2,user);
						cout << "O cruzador numero " << n_boat - 6 << " foi destruido";
						Sleep(5000);
					}
					else
					{
						if (n_boat == 9)
						{
							t1.tabuleiro[l][guarda] = 'T';
							user.couracado.set_destruido();
							desenhar_essencial(t1,t2,user);
							cout << "O couracado foi destruido";
							Sleep(5000);

						}
						else
						{
							if (n_boat == 10)
							{
								t1.tabuleiro[l][guarda] = 'T';
								user.Porta_avioes.set_destruido();
								desenhar_essencial(t1,t2,user);
								cout << "O Porta avioes foi destruido";
								Sleep(5000);
							}
						}
					}
				}

			}
		}

	}
	else if (t1.tabuleiro[l][guarda] == '.')
	{
		t1.tabuleiro[l][guarda] = 'A';
		desenhar_essencial(t1,t2,user);
		cout << "O bot nao acertou em nenhum navio...";
		Sleep(5000);
	}
	user.atulaizar_lista_destruido();
	if (n_boat >= 0)
	{
		return n_boat;
	}

}

void Bot::desenhar_essencial(Tabuleiro& t1, Tabuleiro& t2,Jogador &s)
{
	system("cls");
	gotoxy(75, 0);
	t2.Draw(75, 5, false);
	gotoxy(0, 0);
	t1.Draw(27, 5, true);

	gotoxy(26, 3);
	cout << s.nome;
	gotoxy(110, 3);
	cout << "COMPUTADOR";
	showRectAt(25, 4, 48, 24);
	showRectAt(73, 4, 48, 24);

	show90RectAt(25, 30, 10, 48);
	gotoxy(26, 31);
}