#include "Personagem.h"

Entidades::Personagem::Personagem(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra, int vidas)
	:Entidade(inicialX, inicialY, pgra), _num_vidas(vidas),_direcao(1)
{
	setTipo(1);
}



Entidades::Personagem::~Personagem()
{
}


int Entidades::Personagem::getVidas() const
{
	return _num_vidas;
}

void Entidades::Personagem::setVidas(int vid)
{
	_num_vidas = vid;
}


void Entidades::Personagem::operator++()
{
	_num_vidas++;
}

void Entidades::Personagem::operator--(int i)
{
	if (_num_vidas >= 0)
	{
		_num_vidas -= i;
	}
}


void Entidades::Personagem::pular()
{
	if (_onGround)
	{
		_speed.y = -1.55f;
		setGround(false);
	}
	
}

int Entidades::Personagem::getDirecao() const
{

	return _direcao;
}

void Entidades::Personagem::setDirecao(int dir)
{

	_direcao = dir;
}
