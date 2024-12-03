#include "Obstaculo.h"

Entidades::Obstaculo::Obstaculo(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra)
	:Entidade(inicialX,inicialY,pgra),_danoso(false)
{

}

Entidades::Obstaculo::~Obstaculo()
{
	_danoso = false;
}

void Entidades::Obstaculo::setDanoso(bool dan)
{
	_danoso = dan;
}

bool Entidades::Obstaculo::getDanoso()const
{
	return _danoso;
}
