#include "Personagem.h"

Entidades::Personagem::Personagem(float inicialX = 0, float inicialY = 0,
	float Heigth = 0, float Width = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr)
	:Entidade(inicialX,inicialY,Heigth,Width,pgra),_num_vidas(4)
{
}

Entidades::Personagem::~Personagem()
{
}
