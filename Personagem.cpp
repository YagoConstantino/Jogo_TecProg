#include "Personagem.h"

Entidades::Personagem::Personagem(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra )
	:Entidade(inicialX,inicialY,pgra),_num_vidas(4),onGround(false),vivo(true)
{
}

Entidades::Personagem::~Personagem()
{
}

bool Entidades::Personagem::getOnGround() const
{
	return onGround;
}

void Entidades::Personagem::setGround(bool ong)
{
	onGround = ong;
}

bool Entidades::Personagem::getVivo() const
{
	return vivo;
}

void Entidades::Personagem::setVivo(bool ong)
{
	vivo = ong;
}

int Entidades::Personagem::getVidas() const
{
	return _num_vidas;
}
