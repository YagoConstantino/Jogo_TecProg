#include "Personagem.h"

Entidades::Personagem::Personagem(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra, int vidas)
	:Entidade(inicialX, inicialY, pgra), _num_vidas(vidas),  _vivo(true)
{
	setTipo(1);
}



Entidades::Personagem::~Personagem()
{
}


bool Entidades::Personagem::getVivo() const
{
	return _vivo;
}

void Entidades::Personagem::setVivo(bool vivo)
{
	_vivo = vivo;
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

void Entidades::Personagem::operator--()
{
	if (_num_vidas > 0)
	{
		_num_vidas--;
	}
}


void Entidades::Personagem::pular()
{
	if (_onGround)
	{
		_speed.y = -18.f;
		setGround(false);
	}
	
}
