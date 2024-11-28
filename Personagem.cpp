#include "Personagem.h"

Entidades::Personagem::Personagem(float inicialX, float inicialY,
	float Heigth, float Width, Gerenciadores::Gerenciador_Grafico* pgra )
	:Entidade(inicialX,inicialY,Heigth,Width,pgra),_num_vidas(4)
{
}

Entidades::Personagem::~Personagem()
{
}
