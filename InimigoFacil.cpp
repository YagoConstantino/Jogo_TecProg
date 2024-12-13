#include "InimigoFacil.h"

Entidades::InimigoFacil::InimigoFacil(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog, int vidas)
	:Inimigo(inicialX,inicialY,pgra,pJog,vidas)
{
	setMaldade(1);
	_speed.x = 0.03f;

	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/Inimigo.png"))
	{
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	setTexture(textura);
	_body.setScale(0.1f, 0.1f);
}

Entidades::InimigoFacil::~InimigoFacil()
{
	_pJog = nullptr;
}



void Entidades::InimigoFacil::executar()
{
	mover();
	
}

void Entidades::InimigoFacil::mover()
{
	//Fazer ele andar em 150 pixeis para direita e 50 pixeis para esquerda OK
	//Caso ele encoste no jogador da dano * nivelmaldade nele
	Position += _speed;
	desenhar();
	if (getDistanciaoInicio() >= 150)
	{
		_speed.x *= -1;
	}
	_body.setPosition(Position);
}

void Entidades::InimigoFacil::danificar(Entidades::Jogador* pJog)
{
	pJog->operator--();
	pJog->knockBack(this);
}
