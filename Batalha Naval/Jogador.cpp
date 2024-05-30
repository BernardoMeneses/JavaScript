#include "Jogador.h"

int Jogador::get_number_of_boats_intact()
{
	int contador = 0;
	for (int i = 0; i < 11; i++)
	{
		if (naviosDestruidos[i] == false)
		{
			contador++;
		}
	}
	return contador;
}

void Jogador::atulaizar_lista_destruido()
{
	int contador = 0;
	int i = 0;
	for (i = 0; i < 4; i++)
	{

		naviosDestruidos[contador] = submarinos[i].get_destroid();
		contador++;
	}
	for (i = 0; i < 3; i++)
	{

		naviosDestruidos[contador] = contratorpedeiro[i].get_destroid();
		contador++;
	}
	for (int i = 0; i < 2; i++)
	{

		naviosDestruidos[contador] = cruzador[i].get_destroid();
		contador++;
	}

	naviosDestruidos[contador] = couracado.get_destroid();
	contador++;

	naviosDestruidos[contador] = Porta_avioes.get_destroid();
	contador++;
	if (dev_mode == true)
	{
		system("cls");
		cout << "\n contador=" << contador << "\n\n";
		system("pause");
	}
}

Jogador::Jogador()
{

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		submarinos[i].Iniciar_pontos(1);


	}
	for (i = 0; i < 3; i++)
	{
		contratorpedeiro[i].Iniciar_pontos(2);
	}
	for (int i = 0; i < 2; i++)
	{
		cruzador[i].Iniciar_pontos(3);

	}
	couracado.Iniciar_pontos(4);

	for (int i = 0; i < 11; i++)
	{
		naviosDestruidos[i] = false;
	}
	Porta_avioes.Iniciar_pontos(5);
}



int Jogador::Testar_destruido(int l, int c)
{

	int guarda = -5;

	bool verificar = false;

	for (int i = 0; i < 4; i++)
	{
		if (submarinos[i].pontos[0].getc() == c && submarinos[i].pontos[0].getl() == l)
		{
			if (submarinos[i].get_destroid() == false)
			{
				submarinos[i].pontos[0].set_des(true);
				guarda = i;
				verificar = true;
			}
			else
			{
				cout << "\n\nErro N_xxx" << endl;
			}
		}
	}

	if (guarda == -5 && verificar == false)
	{
		int z = 0;
		for (int i = 0; i < 3; i++)
		{
			z = 0;
			for (int j = 0; j < 2; j++)
			{
				if (contratorpedeiro[i].pontos[j].getl() == l && contratorpedeiro[i].pontos[j].getc() == c)
				{
					if (contratorpedeiro[i].pontos[j].get_des() == false)
					{
						contratorpedeiro[i].pontos[j].set_des(true);
						z++;
						verificar = true;
					}
				}
				else
				{
					if (contratorpedeiro[i].pontos[j].get_des() == true)
					{
						z++;
					}
				}
			}
			if (verificar == true)
			{
				if (contratorpedeiro[i].get_destroid() == false)
				{
					if (z == contratorpedeiro[i].get_type_Boat())
					{
						guarda = i + 4;
						break;
					}
					else
					{
						guarda = -2;
						break;
					}
				}
				else
				{
					system("cls");
					cout << "\n\nErro N_xxx" << endl;
					system("pause");
					exit(0);
				}
			}
		}

	}


	if (guarda == -5 && verificar == false)
	{
		int z = 0;
		for (int i = 0; i < 2; i++)
		{
			z = 0;
			for (int j = 0; j < 3; j++)
			{
				if (cruzador[i].get_destroid() == false)
				{
					if (cruzador[i].pontos[j].getl() == l && cruzador[i].pontos[j].getc() == c)
					{
						if (cruzador[i].pontos[j].get_des() == false)
						{
							cruzador[i].pontos[j].set_des(true);
							z++;
							verificar = true;
						}
					}
					else
					{
						if (cruzador[i].pontos[j].get_des() == true)
						{
							z++;
						}
					}
				}

			}
			if (verificar == true)
			{
				if (cruzador[i].get_destroid() == false)
				{
					if (z == cruzador[i].get_type_Boat())
					{
						guarda = i + 7;
						break;
					}
					else
					{
						guarda = -2;
						break;
					}
				}
				else
				{
					system("cls");
					cout << "\n\nErro N_xxx" << endl;
					system("pause");
					exit(0);
				}

			}
		}
	}

	if (guarda == -5 && verificar == false)
	{
		int z = 0;
		for (int j = 0; j < 4; j++)
		{
			if (couracado.get_destroid() == false)
			{
				if (couracado.pontos[j].getc() == c && couracado.pontos[j].getl() == l)
				{
					if (couracado.pontos[j].get_des() == false)
					{
						couracado.pontos[j].set_des(true);
						z++;
						verificar = true;
					}
				}
				else
				{
					if (couracado.pontos[j].get_des() == true)
					{
						z++;
					}
				}
			}

		}
		if (verificar == true)
		{
			if (couracado.get_destroid() == false)
			{
				if (z == couracado.get_type_Boat())
				{
					guarda = 9;
				}
				else
				{
					guarda = -2;
				}
			}
			else
			{
				system("cls");
				cout << "\n\nErro N_xxx\n\n" << endl;
				system("pause");
				exit(0);
			}
		}
	}

	if (guarda== -5 && verificar == false)
	{
		int z = 0;
		for (int j = 0; j < 5; j++)
		{
			if (Porta_avioes.get_destroid() == false)
			{
				if (Porta_avioes.pontos[j].getc() == c && Porta_avioes.pontos[j].getl() == l)
				{
					if (Porta_avioes.pontos[j].get_des() == false)
					{
						Porta_avioes.pontos[j].set_des(true);
						z++;
						verificar = true;
					}

				}
				else
				{
					if (Porta_avioes.pontos[j].get_des() == true)
					{
						z++;
					}
				}
			}

		}
		if (verificar == true)
		{
			if (Porta_avioes.get_destroid() == false)
			{
				if (z == Porta_avioes.get_type_Boat())
				{
					guarda = 10;
				}
				else
				{
					guarda = -2;
				}
			}
			else
			{
				system("cls");
				cout << "\n\nErro N_xxx\n\n" << endl;
				system("pause");
				exit(0);
			}
		}
	}

	if (guarda == -5)
	{
		system("cls");
		cout << "\n\nErro N_xxx" << endl;
		system("pause");
		exit(0);

	}
	else
	{
		return guarda;
	}
}

void Jogador::set_dev(bool dev_mod)
{
	dev_mode = dev_mod;
	int i = 0;
	for (i = 0; i < 4; i++)
	{

		submarinos[i].set_Dev_mode(dev_mode);

	}
	for (i = 0; i < 3; i++)
	{

		contratorpedeiro[i].set_Dev_mode(dev_mode);
	}
	for (int i = 0; i < 2; i++)
	{

		cruzador[i].set_Dev_mode(dev_mode);
	}

	couracado.set_Dev_mode(dev_mode);

	Porta_avioes.set_Dev_mode(dev_mode);
}