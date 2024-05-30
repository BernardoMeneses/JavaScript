#include "Jogo.h"

using namespace std;

Jogo::Jogo()
{



}

Jogo::~Jogo()
{


}

bool Jogo::Demo()
{
	return false;
}

void Jogo::Jogo_Novo()
{
	bool ala = true;
	int i = 0, j = 0;
	bool asi = false;
	int t = 0;
	desenhar_essencial();
	cout << "Qual o nome do player?";
	getline(cin, player1.nome);
	
	desenhar_essencial();
	cout << "Qual a dificuldade que quer jogar?(0=false,1=true)";
	cin >> t;
	if (t != 0 && t != 1)
	{
		system("cls");
		cout << "\nErro N_xxx\n\n";
		system("pause");
	}
	if (t == 1)
	{
		bo.set_hard_mod(true);
	}
	bo.set_dev(Dev_mode);
	desenhar_essencial();
	cout << "Vamos agora gerar os barcos(em 2s)";
	Sleep(1500);
	

	if (Dev_mode == true)
	{
		system("cls");
	}
	gerarBarcos();

	system("cls");

	if (Dev_mode == true && ala == false)
	{
		set_user();
	}
	else
	{
		if (Dev_mode == false)
		{
			set_user();
		}
	}

	int aux = 0;
	int aux_2 = 1;
	string verefi = "N";
	system("cls");
	desenhar_essencial();
	cout << "Agora vamos começar o jogo real...(5s)";
	Sleep(5000);
	while (true)
	{
		aux = batalha();

		if (aux == 0)
		{
			break;
		}
		else
		{
			if (aux == 1)
			{
				break;
			}
		}

		system("cls");
		desenhar_essencial();
		cout << "\nE a vez do Bot...\n";
		desenhar_essencial();
		bot();
		aux = vereficao_final();
		if (aux == 0)
		{
			break;
		}
		else
		{
			if (aux == 1)
			{
				break;
			}
		}
		aux_2++;
		desenhar_essencial();

		cout << "Voce quer salvar o jogo atual ?(s/S ou n/N)=" << endl;
		cin >> verefi;
		if (verefi == "S" || verefi == "s")
		{
			bool p = false;
			string file_name = "Save_file.txt";
			desenhar_essencial();
			cout << "Voce quer salvar o ficheiro como, ficheiro tem que acabar com .txt=" << endl;
			cin >> file_name;
			p = Save(file_name);
			desenhar_essencial();
		}

		desenhar_essencial();
		cout << "Vamos agora para o turno " << aux_2 << ".(5s)";

		Sleep(5000);
	}


}

bool Jogo::Save(string file)
{
	ofstream Save;
	if (Dev_mode == true)
	{
		system("cls");
		cout << "\n\n Nome do ficheiro =" << file << endl;

	}
	Save.open(file);
	for (int i = 0; i < t1.getDimX(); i++)
	{
		for (int j = 0; j < t1.getDimY(); j++)
		{
			Save << t1.tabuleiro[i][j] << " ";
		}
	}
	system("pause");

	return false;
}

bool Jogo::Read(string file)
{





	return false;
}



bool Jogo::checkCords(int x, int y, int cords[4][2], int pos)
{
	bool exists = false;
	for (int i = 0; i < 4; i++)
	{
		if (i == pos)
		{
			continue;
		}
		else
		{
			if (x == cords[i][0] && y == cords[i][1])
			{
				exists = true;
			}
		}
	}
	return exists;
}


void Jogo::gerarBarcos()
{
	int i = 0;
	
	t1.set_Dev_mode(Dev_mode);
	t2.set_Dev_mode(Dev_mode);

	player1.set_dev(Dev_mode);
	player2.set_dev(Dev_mode);

	//porta-avioes

	player2.Porta_avioes.set_name(player1.nome);
	
	player2.Porta_avioes.generate_boat(t2);
	if (Dev_mode==false)
	{
		desenhar_essencial();
		cout << "Porta avioes gerado...";
	}

	//couracado
	player2.couracado.set_name(player1.nome);


	player2.couracado.generate_boat(t2);
	if (Dev_mode==false)
	{
		desenhar_essencial();
		cout << "Couracado gerado...";
	}

	//cruzadores
	for (i = 0; i < 2; i++)
	{
		player1.cruzador[i].set_name(player1.nome);


		player2.cruzador[i].generate_boat(t2);
	}

	if (Dev_mode == false)
	{
		desenhar_essencial();
		cout << "Cruzadores gerados...";
	}

	//contratorpedeiro
	for (i = 0; i < 3; i++)
	{
		player2.contratorpedeiro[i].set_name(player1.nome);


		player2.contratorpedeiro[i].generate_boat(t2);
	}
	if (Dev_mode == false)
	{
		desenhar_essencial();
		cout << "Contratorpedeiros gerados...";
	}

	//submarinos

	for (i = 0; i < 4; i++)
	{
		player2.submarinos[i].set_name(player1.nome);

		player2.submarinos[i].generate_boat(t2);

	}
	
	if (Dev_mode==false)
	{
		desenhar_essencial();
		cout << "Submarinos gerados...";
		Sleep(700);
		desenhar_essencial();
		cout << "Completo...";
		Sleep(3000);
		desenhar_essencial();
	}

	if (Dev_mode == true)
	{
		system("pause");
		system("cls");
	}



}
void Jogo::set_user()
{
	
	player1.submarinos[0].set_name(player1.nome);
	player1.submarinos[0].desenhar_essencial(t1, t2);

	cout << "Tens que prencher o tabuleiro antes de continuar...(5s)";

	Sleep(5000);

	player1.submarinos[0].desenhar_essencial(t1, t2);
	
	for (int i = 0; i < 4; i++)
	{
		player1.submarinos[i].set_name(player1.nome);
		player1.submarinos[i].set_user_boat(t1, t2);
		player1.submarinos[i].desenhar_essencial(t1, t2);
	}

	for (int i = 0; i < 3; i++)
	{
		player1.contratorpedeiro[i].set_name(player1.nome);

		player1.contratorpedeiro[i].set_user_boat(t1, t2);
		player1.contratorpedeiro[i].desenhar_essencial(t1, t2);
	}

	for (int i = 0; i < 2; i++)
	{
		player1.cruzador[i].set_name(player1.nome);
		player1.cruzador[i].set_user_boat(t1, t2);
		player1.cruzador[i].desenhar_essencial(t1, t2);
	}


	player1.couracado.set_name(player1.nome);

	player1.couracado.set_user_boat(t1, t2);
	
	player1.Porta_avioes.set_name(player1.nome);

	player1.Porta_avioes.set_user_boat(t1, t2);
}



void Jogo::desenhar_essencial()
{

	system("cls");

	gotoxy(75, 0);
	t2.Draw(75, 5, false);
	gotoxy(0, 0);
	t1.Draw(27, 5, true);

	gotoxy(26, 3);
	cout << player1.nome;
	gotoxy(110, 3);
	cout << "COMPUTADOR";
	showRectAt(25, 4, 48, 24);
	showRectAt(73, 4, 48, 24);

	show90RectAt(25, 30, 10, 48);
	gotoxy(26, 31);
}

int Jogo::batalha()
{
	bool batalha = true;
	int vencer_perder = 0;
	int aa = 1;
	while (batalha == true)
	{

		desenhar_essencial();
		cout << "E a " << aa << " jogada neste turno";
		Sleep(5000);
		desenhar_essencial();

		bool verificador = true;
		int l = 0;
		char c = '@';
		char letras[10] = { 'a','b','c','d','e','f','g','h','i','j' };
		char letras_g[10] = { 'A','B','C','D','E','F','G','H','I','J' };
		int guarda = -57;

		while (verificador == true)
		{
			desenhar_essencial();
			gotoxy(31, 31);
			cout << "Qual e a linha que deseja atacar ?=";
			cin >> l;
			gotoxy(31, 31);

			if (l <= 10 && l >= 1)
			{
				l--;
				desenhar_essencial();
				cout << "Qual e a coluna que deseja atacar ?=";
				cin >> c;
				for (int a = 0; a < 10; a++)
				{
					if (letras[a] == c)
					{

						if (t2.tabuleiro[l][a] == '.' || t2.tabuleiro[l][a] == 'O')
						{
							verificador = false;
							guarda = a;
						}
					}
				}
				if (guarda == -57)
				{
					for (int a = 0; a < 10; a++)
					{
						if (letras_g[a] == c)
						{
							if (t2.tabuleiro[l][a] == '.' || t2.tabuleiro[l][a] == 'O')
							{
								verificador = false;
								guarda = a;
							}
						}
					}
					if (guarda == -57)
					{
						l = 0;
						c = '@';
						desenhar_essencial();
						cout << "Erro...(letra nao combina) N_xxx";
						Sleep(5000);
					}

				}

			}
			else
			{
				guarda = -57;
				l = 0;
				c = '@';
				desenhar_essencial();
				cout << "Erro...N_xxx";
				Sleep(5000);

			}
		}



		Destruir( l, guarda);

		vencer_perder = vereficao_final();
		switch (vencer_perder)
		{

		case 0:
		{
			aa = 3;
			batalha = false;
			return 0;
			break;
		}

		case 1:
		{
			batalha = false;
			aa = 3;
			return 1;
			break;
		}

		case 2:
		{
			if (aa == 3)
			{

				batalha = false;
				return 2;
			}
			break;
		}

		default:
		{
			system("cls");

			cout << "\n\nErro...N_xxx\n\n" << endl;
			system("pause");
			exit(0);
			break;
		}
		}
		aa++;
	}

}


int Jogo::vereficao_final()
{
	int vereficar_1 = player1.get_number_of_boats_intact();
	int vereficar_2 = player2.get_number_of_boats_intact();

	if (vereficar_1 == 0)
	{
		desenhar_essencial();
		cout << "O computador ganhou...(7s)";
		Sleep(7000);
		return 0;
	}
	else
	{
		if (vereficar_2 == 0)
		{
			desenhar_essencial();
			cout << "O " << player1.nome << " ganhou...(7s)";
			Sleep(7000);
			return 1;
		}
		else
		{
			desenhar_essencial();
			cout << "O " << player1.nome << " tem " << vereficar_1 << " ativos e computador tem " << vereficar_2 << " navios ativos...(5s)";
			Sleep(5000);
			return 2;
		}
	}
}


void Jogo::bot()
{
	
	bo.bot(t1, t2, player1);
}

void Jogo::set_Dev_mode(bool dev_mode)
{
	Dev_mode = dev_mode;
}

void Jogo::mostrar_legenda()
{

	gotoxy(22, 55);
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << " " << endl;

}

void Jogo::Destruir(int l, int guarda)
{

		
			if (t2.tabuleiro[l][guarda] == 'O')
			{
				int n_boat = player2.Testar_destruido(l, guarda);
				if (n_boat == -2)
				{
					t2.tabuleiro[l][guarda] = 'T';
					desenhar_essencial();
					cout << "Voce acertou num navio...";
					Sleep(5000);
				}
				else
				{
					if (Dev_mode == true)
					{
						system("cls");
						cout << "\n\n N_" << n_boat << endl;
						system("pause");
						desenhar_essencial();
					}
					if (n_boat >= 0 && n_boat < 4)
					{
						t2.tabuleiro[l][guarda] = 'T';
						player2.submarinos[n_boat].set_destruido();
						desenhar_essencial();
						cout << "O submarino numero " << n_boat + 1 << " foi destruido...";

						Sleep(5000);
					}
					else
					{
						if (n_boat >= 4 && n_boat < 7)
						{
							t2.tabuleiro[l][guarda] = 'T';
							if (Dev_mode == true)
							{
								system("cls");
								cout << "\n\ncontratorpedeiro numero no vetor= " << n_boat - 4 << "\n\n" << endl;
								system("pause");
								system("cls");
							}
							player2.contratorpedeiro[n_boat - 4].set_destruido();
							if (player2.contratorpedeiro[n_boat - 4].get_destroid() == false)
							{
								system("cls");
								cout << "\n\nSuper Erro_xxxx\n" << endl;
								system("pause");
								exit(0);
							}
							desenhar_essencial();
							cout << "O contratorpedeiro numero " << n_boat - 3 << " foi destruido";
							Sleep(5000);


						}
						else
						{
							if (n_boat >= 7 && n_boat < 9)
							{
								t2.tabuleiro[l][guarda] = 'T';
								if (Dev_mode == true)
								{
									system("cls");
									cout << "\n\ncruzador numero no vetor= " << n_boat - 7 << "\n\n" << endl;
									system("pause");
									system("cls");
								}
								player2.cruzador[n_boat - 7].set_destruido();
								desenhar_essencial();
								cout << "O cruzador numero " << n_boat - 6 << " foi destruido";
								Sleep(5000);
							}
							else
							{
								if (n_boat == 9)
								{
									t2.tabuleiro[l][guarda] = 'T';
									player2.couracado.set_destruido();
									desenhar_essencial();
									cout << "O couracado foi destruido";
									Sleep(5000);

								}
								else
								{
									if (n_boat == 10)
									{
										t2.tabuleiro[l][guarda] = 'T';
										player2.Porta_avioes.set_destruido();
										desenhar_essencial();
										cout << "O Porta avioes foi destruido";
										Sleep(5000);
									}
								}
							}
						}
					}
				}
			}
			else if (t2.tabuleiro[l][guarda] == '.')
			{
				t2.tabuleiro[l][guarda] = 'A';
				desenhar_essencial();
				cout << "Voce nao acertou em nenhum navio...";
				Sleep(5000);
			}
			player2.atulaizar_lista_destruido();
}