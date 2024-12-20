#include "Cavaleiro.h"
#include <stdlib.h>
#include <time.h>
Entidades::Cavaleiro::Cavaleiro(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog, int vidas)
	:Inimigo(inicialX, inicialY, pgra, pJog, vidas)
{
	setTipo(4);
	setMaldade(1);
	_speed.x = 0.03f;


	if (rand() % 2)
	{
		_speed.x *= -1;
	}

	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/Inimigo.png"))
	{
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	setTexture(textura);
	_body.setScale(0.1f, 0.1f);

	_clock.restart();
}

Entidades::Cavaleiro::~Cavaleiro()
{
	_pJog = nullptr;
}



void Entidades::Cavaleiro::executar()
{
	// controla a frequencia para bater no jogador
	_segundos += _clock.restart().asSeconds();

	mover();
	if (_num_vidas <= 0)
	{
		setVivo(false);
	}

	desenhar();
	
}

void Entidades::Cavaleiro::mover()
{
	//Fazer ele andar em 150 pixeis para direita e 50 pixeis para esquerda OK
	//Caso ele encoste no jogador da dano * nivelmaldade nele
	Position += _speed;

	if (getDistanciaoInicio() >= 150)
	{
		_speed.x *= -1;
	}
	_body.setPosition(Position);
}

void Entidades::Cavaleiro::danificar(Entidades::Jogador* pJog)
{
	if (_segundos > 0.75f) {
		_segundos = 0.f;

		pJog->operator--();
		pJog->knockBack(this);
	}
}
