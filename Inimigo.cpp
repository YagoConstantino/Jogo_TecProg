#include "Inimigo.h"

Entidades::Inimigo::Inimigo(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra, Entidades::Jogador* pJog,int vidas)
	:Personagem(inicialX,inicialY,pgra,vidas),
	_pJog(pJog),atacar(false),_nivel_maldade(0), posInicialX(inicialX), posInicialY(inicialY)
{
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
	else
	{
		std::cerr << "Erro: Jogador inválido ao setar no inimigo!" << std::endl;
	}
}

double Entidades::Inimigo::getDistanciaJogador()
{
	
	if (!_pJog)
	{
		std::cerr << "Erro: Ponteiro para jogador é nulo. Distância não pode ser calculada!" << std::endl;
		return -1.0;
	}
	//Pitagoras para calcular a distancia 
	return sqrt(pow(getPositionX() - _pJog->getPositionX(), 2) + pow(getPositionY() - _pJog->getPositionY(), 2));
}

double Entidades::Inimigo::getDistanciaoInicio()
{
	return sqrt(pow(getPositionX() - posInicialX, 2) + pow(getPositionY() - posInicialY, 2));
}

sf::Vector2f Entidades::Inimigo::getDistanciaInicioVector()
{
	sf::Vector2f distancia;

	distancia.x = getPosition().x - posInicialX;
	distancia.y = getPosition().y - posInicialY;

	return distancia;
}



