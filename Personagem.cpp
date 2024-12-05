#include "Personagem.h"

Entidades::Personagem::Personagem(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra, int vidas)
	:Entidade(inicialX, inicialY, pgra), _num_vidas(vidas), _onGround(false), _vivo(true)
{
	_speed.x = 0.5f;
	_speed.y = 0.5f;
}



Entidades::Personagem::~Personagem()
{
}

bool Entidades::Personagem::getOnGround() const
{
	return _onGround;
}

void Entidades::Personagem::setGround(bool ong)
{
	_onGround = ong;
}

bool Entidades::Personagem::getVivo() const
{
	return _vivo;
}

void Entidades::Personagem::setVivo(bool ong)
{
	_vivo = ong;
}

int Entidades::Personagem::getVidas() const
{
	return _num_vidas;
}

void Entidades::Personagem::setVidas(int vid)
{
	_num_vidas = vid;
}

void Entidades::Personagem::sofrerGravidade(float gravidade)
{
	if (Position.y + _body.getGlobalBounds().height + gravidade <= _pGraf->getWindow()->getSize().y) 
	{
		Position.y += gravidade;
	}
	_body.setPosition(Position);
}

void Entidades::Personagem::pular()
{
	Position.y -= _speed.y * 300;
	setGround(false);
}
