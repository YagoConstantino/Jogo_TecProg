#include "Jogo.h"
#include <iostream>

// ESTÁTICOS

/*
	StateNum é uma variavel que permite o fluxo de diferentes estados no jogo
	Tipos de stateNum's:

	10 - menu
	11 - menu de ranking (exemplo)
	12 - menu de fases
	20 - fase 1, floresta
	21 - fase 2, ...
*/
int Jogo::stateNum = 10;

void Jogo::mudarStateNum(int state) { stateNum = state; }


// DEMAIS

Jogo::Jogo():_jogador1(nullptr),_jogador2(nullptr)
{
	_GerenciadorGráfico = Gerenciadores::Gerenciador_Grafico::getInstancia();
	rank = new Ranking();
	_florest = nullptr;
	_menu = nullptr;

}

Jogo::~Jogo()
{
	if (_jogador1)
	{
		delete _jogador1;
	}
	if (_jogador2)
	{
		delete _jogador2;
	}

	if (_GerenciadorGráfico)
	{
		delete _GerenciadorGráfico;
	}
	if (_florest)
	{
		delete _florest;
	}
	if (_menu) {
		delete _menu;
	}
	if (rank)
	{
		delete rank;
	}

	_jogador1 = nullptr;
	_jogador1 = nullptr;
	_GerenciadorGráfico = nullptr;
	_florest = nullptr;
	_menu = nullptr;
	rank = nullptr;
}

void Jogo::executar()
{
	while (_GerenciadorGráfico->getOpen()) 
	{
		
		// Escolhe o estado da janela
		
		switch (stateNum) {
			// Fecha janela
		case 0:
			_GerenciadorGráfico->closeWindow();
			break;
			
			// Cria menu principal
		case 10:
			criaMenu();
			JogarMenu();
			break;

			// Cria o menu de ranking
		case 11:

			break;

			// Cria o menu de fases
		case 12:

			break;

			// Cria a fase 1, floresta
		case 20:
			criaFloresta();
			JogarFloresta();
			if (rank) 
			{
				cout << "Atualizando leaderboard..." << endl;
				rank->atualizaLeaderboard(_jogador1);
				rank->atualizaLeaderboard(_jogador2);
				rank->imprimirLeaderboard();
				rank->salvarDados();
			}
			else 
			{
				cerr << "Erro: rank não inicializado!" << endl;
			}
			break;
		}
	}
}
bool Jogo::criarJogador1(string nome)
{
	if (!_jogador1)
	{
		_jogador1 = new Entidades::Jogador(0, 0, _GerenciadorGráfico, nome);
		if (_jogador1)
		{
			rank->verificaPontos(_jogador1);
			return true;
		}
		return false;
	}
	cerr << "Jogador1 já existente\n";
	return false;
}

bool Jogo::criarJogador2(string nome)
{
	if (!_jogador2)
	{
		_jogador2 = new Entidades::Jogador(30, 0, _GerenciadorGráfico, nome);
		if (_jogador2) 
		{ 
			rank->verificaPontos(_jogador2);
			return true;
		};
		return false;
	}
	cerr << "Jogador2 já existente\n";
	return false;
}


void Jogo::JogarFloresta()
{
	_florest->executar();
}



void Jogo::criaMenu() 
{
	if (_menu == nullptr) 
	{
		// Destroi o estado anterior
		if (_florest != nullptr) 
		{
			delete _florest;
			_florest = nullptr;
		}

		_menu = new Menu(_GerenciadorGráfico);
	}
}

void Jogo::JogarMenu() 
{
	_menu->executar();
}

void Jogo::criaFloresta() 
{
	if (_florest == nullptr) 
	{
		// destroi o estado anterior
		if (_menu != nullptr) 
		{
			delete _menu;
			_menu = nullptr;
		}

		_florest = new Fases::Floresta(_GerenciadorGráfico, _jogador1,_jogador2);

		_florest->criarInimigos();
		_florest->criarObstaculos();
	}
}


