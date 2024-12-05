#include "Inimigo.h"

Entidades::Inimigo::Inimigo(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra, Entidades::Jogador* pJog,int vidas)
	:Personagem(inicialX,inicialY,pgra,vidas),_pJog(pJog),atacar(false)
{
	_nivel_maldade = 0;
}

Entidades::Inimigo::~Inimigo()
{
	_pJog = nullptr;
}

void Entidades::Inimigo::setMaldade(int mal)
{
	_nivel_maldade = mal;
}

int Entidades::Inimigo::getMaldade() const
{
	return _nivel_maldade;
}

void Entidades::Inimigo::setJogador(Entidades::Jogador* pJog)
{
	if (pJog)
	{
		_pJog = pJog;
	}
}

double Entidades::Inimigo::getDistancia()
{
	//Pitagoras para calcular a distancia 
	return sqrt(pow(getPositionX() - _pJog->getPositionX(), 2) + pow(getPositionY() - _pJog->getPositionY(), 2));
}
