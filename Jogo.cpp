#include "Jogo.h"
#include <iostream>


/*
	StateNum é uma variavel que permite o fluxo de diferentes estados no jogo
	Tipos de stateNum's:

	10 - menu
	11 - menu de ranking (exemplo)
	20 - fase 1, floresta
	21 - fase 2, ...
*/

Jogo::Jogo(std::string nome) : stateNum(10)

{
	_GerenciadorGráfico = Gerenciadores::Gerenciador_Grafico::getInstancia();
	_jogador1 = new Entidades::Jogador(0, 0, _GerenciadorGráfico, nome);

	_florest = nullptr;
	_menu = nullptr;

}

Jogo::~Jogo()
{
	if (_jogador1)
	{
		delete _jogador1;
	}
	if (_GerenciadorGráfico)
	{
		delete _GerenciadorGráfico;
	}
	if (_florest)
	{
		delete _florest;
	}
}

void Jogo::executar()
{
	while (_GerenciadorGráfico->getOpen()) 
	{
		sf::Event event;
		while (_GerenciadorGráfico->getWindow()->pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				_GerenciadorGráfico->closeWindow();
				
		}

		_GerenciadorGráfico->clear();

		switch (stateNum) 
		{
			// Cria menu principal
		case 10:
			criaMenu();
			JogarMenu();
			stateNum = _menu->getStateNum();
			break;

			// Cria o menu de ranking
		case 11:
			break;

			// Cria a fase 1, floresta
		case 20:
			criaFloresta();
			JogarFloresta();
			break;
		}

		_GerenciadorGráfico->display();
	}
}

void Jogo::JogarFloresta()
{
	_florest->executar();
}



void Jogo::criaMenu() {
	if (_menu == nullptr) {
		_menu = new Menu(_GerenciadorGráfico);

		// Destroi o estado anterior
		if (_florest != nullptr) 
		{
			delete _florest;
			_florest = nullptr;
		}
	}
}

void Jogo::JogarMenu() 
{
	_menu->executar();
}

void Jogo::criaFloresta() 
{
	if (_florest == nullptr) {
		_florest = new Fases::Floresta(_GerenciadorGráfico, _jogador1);

		_florest->criarInimigos();
		_florest->criarObstaculos();

		
		// destroi o estado anterior
		if(_menu != nullptr){
			delete _menu;
			_menu = nullptr;
		}
		
	}
}


