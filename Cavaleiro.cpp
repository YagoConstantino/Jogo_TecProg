#include "Cavaleiro.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "Constantes.h"
Entidades::Cavaleiro::Cavaleiro(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog1,Entidades::Jogador*pJog2, int vidas)
	:Inimigo(inicialX, inicialY, pgra, pJog1,pJog2, vidas)
{
	setTipo(Constantes::TIPO_CAVALEIRO);
	setMaldade(Constantes::MALDADE_CAVALEIRO);
	_speed.x = Constantes::VEL_CAVALEIRO;


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
	_pJog1 = nullptr;
	_pJog2 = nullptr;
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
	if (abs(getDistanciaInicioVector().x) >= Constantes::DISTANCIA_INICIO_CAVALEIRO)
	{
		_direcao *= -1;
		_speed.x *= _direcao;
	}
	Position += _speed;
	_body.setPosition(Position);
	
}

void Entidades::Cavaleiro::danificar(Entidades::Jogador* pJog)
{
	if (_segundos > 0.75f) {
		_segundos = 0.f;

		pJog->operator--(1);
		pJog->knockBack(this);
	}
}
