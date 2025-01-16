#include "Jogo.h"
#include <iostream>

// EST�TICOS

/*
	StateNum � uma variavel que permite o fluxo de diferentes estados no jogo
	Tipos de stateNum's:

	10 - menu
	11 - menu de fases
	12 - menu de ranking (exemplo)
	20 - fase 1, floresta
	21 - fase 2, castelo
*/

int Jogo::stateNum = 10;

void Jogo::mudarStateNum(int state) { stateNum = state; }


// DEMAIS

Jogo::Jogo():_jogador1(nullptr),_jogador2(nullptr)
{
	_GerenciadorGrafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
	rank = new Ranking();

	_castelo = nullptr;
	_florest = nullptr;
	_menu = nullptr;
	_menuFases = nullptr;
	_menuRanking = nullptr;
}

Jogo::~Jogo()
{
	if (_jogador1)
		delete _jogador1;
	
	if (_jogador2)
		delete _jogador2;
	
	if (_GerenciadorGrafico)
		delete _GerenciadorGrafico;
	
	if (_castelo)
		delete _castelo;
	
	if (_florest)
		delete _florest;
	
	if (_menu) 
		delete _menu;
	
	if (_menuFases) 
		delete _menuFases;
	
	if (_menuRanking) 
		delete _menuRanking;
	
	if (rank)
		delete rank;
	

	_jogador1 = nullptr;
	_jogador1 = nullptr;
	_GerenciadorGrafico = nullptr;
	_florest = nullptr;
	_menu = nullptr;
	_menuFases = nullptr;
	_menuRanking = nullptr;
	rank = nullptr;
}

void Jogo::executar()
{
	while (_GerenciadorGrafico->getOpen()) 
	{
		
		// Escolhe o estado da janela

		switch (stateNum) {
			// Fecha janela
		case 0:
			_GerenciadorGrafico->closeWindow();
			break;

			// Cria menu principal
		case 10:
			criaMenu();
			JogarMenu();
			break;

			// Cria o menu de fases
		case 11:
			criaMenuFases();
			JogarMenuFases();
			break;

			// Cria o menu de ranking
		case 12:
			criaMenuRanking();
			JogarMenuRanking();
			break;

			// Cria a fase 1, floresta
		case 20:
			criaFloresta();
			JogarFloresta();
			atualizaRanking();
			break;

		case 21: // Cria a fase 2, castelo
			criaCastelo();
			JogarCastelo();
			atualizaRanking();
			break;
			
		}
	}
}
void Jogo::destroiEstadosAnteriores()
{
	if (_menu) 
	{
		
		delete _menu;
		_menu = nullptr;
	}
	if (_menuFases) 
	{
		
		delete _menuFases;
		_menuFases = nullptr;
	}
	if (_menuRanking) 
	{
		
		delete _menuRanking;
		_menuRanking = nullptr;
	}
	if (_florest) 
	{
		
		delete _florest;
		_florest = nullptr;
	}
	if (_castelo) 
	{
		
		delete _castelo;
		_castelo = nullptr;
	}
}
void Jogo::atualizaRanking()
{
	if (rank)
	{
		cout << "Atualizando leaderboard..." << endl;
		rank->atualizaLeaderboard(_jogador1);
		rank->atualizaLeaderboard(_jogador2);

		rank->salvarDados();
	}
	else
	{
		cerr << "Erro: rank n�o inicializado!" << endl;
	}
	
}
bool Jogo::criarJogador1(string nome)
{
	if (!_jogador1)
	{
		_jogador1 = new Entidades::Jogador(0, 0, _GerenciadorGrafico, nome);
		if (_jogador1)
		{
			rank->verificaPontos(_jogador1);
			return true;
		}
		return false;
	}
	cerr << "Jogador1 ja existente\n";
	return false;
}

bool Jogo::criarJogador2(string nome)
{
	if (!_jogador2)
	{
		_jogador2 = new Entidades::Jogador(30, 0, _GerenciadorGrafico, nome);
		if (_jogador2) 
		{ 
			rank->verificaPontos(_jogador2);
			return true;
		};
		return false;
	}
	cerr << "Jogador2 ja existente\n";
	return false;
}


void Jogo::JogarCastelo()
{
	_castelo->executar();
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
		destroiEstadosAnteriores();
		_menu = new Menus::Menu(_GerenciadorGrafico);
	}
}

void Jogo::criaMenuFases()
{
	if (_menuFases == nullptr) {
		// Destroi o estado anterior
		destroiEstadosAnteriores();
		_menuFases = new Menus::MenuFases(_GerenciadorGrafico);
	}
}

void Jogo::criaMenuRanking()
{
	if (_menuRanking == nullptr) {
		// Destroi o estado anterior
		destroiEstadosAnteriores();

		_menuRanking = new Menus::MenuRanking(_GerenciadorGrafico,rank);
	}
}

void Jogo::criaCastelo()
{
	if (_castelo == nullptr) {
		// destroi o estado anterior
		destroiEstadosAnteriores();

		// Cria o estado atual
		_castelo = new Fases::Castelo(_GerenciadorGrafico, _jogador1,_jogador2);
	}
}

void Jogo::criaFloresta()
{
	if (_florest == nullptr) {
		// destroi o estado anterior
		destroiEstadosAnteriores();

		// Cria o estado atual
		_florest = new Fases::Floresta(_GerenciadorGrafico, _jogador1,_jogador2);

		_florest->criarInimigos();
		_florest->criarObstaculos();
	}
}

void Jogo::JogarMenu()
{
	_menu->executar();
}

void Jogo::JogarMenuFases()
{
	_menuFases->executar();
}

void Jogo::JogarMenuRanking()
{
	_menuRanking->executar();
}


