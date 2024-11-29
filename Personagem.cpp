#include "Personagem.h"

Entidades::Personagem::Personagem(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra )
	:Entidade(inicialX,inicialY,pgra),_num_vidas(4)
{
}

Entidades::Personagem::~Personagem()
{
}
