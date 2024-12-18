#include "Cavaleiro.h"
#include <stdlib.h>
#include <time.h>
Entidades::Cavaleiro::Cavaleiro(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog, int vidas)
	:Inimigo(inicialX,inicialY,pgra,pJog,vidas)
{
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
}

Entidades::Cavaleiro::~Cavaleiro()
{
	_pJog = nullptr;
}



void Entidades::Cavaleiro::executar()
{
	mover();
	if (_num_vidas <= 0)
	{
		setVivo(false);
	}
	
}

void Entidades::Cavaleiro::mover()
{
	//Fazer ele andar em 150 pixeis para direita e 50 pixeis para esquerda OK
	//Caso ele encoste no jogador da dano * nivelmaldade nele
	Position += _speed;
	desenhar();
	if (getDistanciaoInicio() >= 150)
	{
		_speed.x *= -1;
	}
	_body.setPosition(Position);
}

void Entidades::Cavaleiro::danificar(Entidades::Jogador* pJog)
{
	pJog->operator--();
	pJog->knockBack(this);
}
