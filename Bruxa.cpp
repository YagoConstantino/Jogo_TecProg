#include "Bruxa.h"

Entidades::Bruxa::Bruxa(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog, int vidas)
	:Inimigo(inicialX,inicialY,pgra,pJog,vidas)
{
	setMaldade(2);
	_speed.x = 0.05f;

	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/Mortovivo-.png"))
	{
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	setTexture(textura);
	_body.setScale(0.1f, 0.1f);
}

Entidades::Bruxa::~Bruxa()
{
	_pJog = nullptr;
}

void Entidades::Bruxa::executar()
{
}

void Entidades::Bruxa::mover()
{
}

void Entidades::Bruxa::danificar(Entidades::Jogador* pJog)
{
}
