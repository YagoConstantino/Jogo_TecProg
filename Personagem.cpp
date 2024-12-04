#include "Personagem.h"

Entidades::Personagem::Personagem(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra )
	:Entidade(inicialX,inicialY,pgra),_num_vidas(4),onGround(false)
{
}

Entidades::Personagem::~Personagem()
{
}

bool Entidades::Personagem::getOnGround() const
{
	return onGround;
}

void Entidades::Personagem::setBool(bool ong)
{
	onGround = ong;
}
