#include "Plataforma.h"

Entidades::Plataforma::Plataforma(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra, float alt)
	:Obstaculo(inicialX,inicialY,pgra),altura(alt)
{
	sf::Texture* textura = _pGraf->getTextura("Plat");

	/*
	if (!textura->loadFromFile("assets/TerrenoComFundo.png")) {
		std::cout << "Falha ao carregar textura!" << std::endl;
	}
	*/

	setTexture(textura);
	_body.setScale(1.3f,0.3f);
	desenhar();
}

Entidades::Plataforma::~Plataforma()
{
}

void Entidades::Plataforma::executar()
{
	desenhar();
}

void Entidades::Plataforma::obstacular(Entidades::Jogador* pJog)
{
	/*float novaPosicao = pJog->getPositionX();
	pJog->setPositionX(novaPosicao-10);*/
	executar();
}


