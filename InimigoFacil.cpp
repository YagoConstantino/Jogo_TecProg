#include "InimigoFacil.h"

Entidades::InimigoFacil::InimigoFacil(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog, int vidas)
	:Inimigo(inicialX,inicialY,pgra,pJog,vidas),posInicialX(inicialX),posInicialY(inicialY)
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

double Entidades::InimigoFacil::getDistanciaoInicio()
{
	return sqrt(pow(getPositionX()-posInicialX,2)+pow(getPositionY()-posInicialY,2));
}

void Entidades::InimigoFacil::executar()
{
	//Fazer ele andar em 50 pixeis para direita e 50 pixeis para esquerda OK
	//Caso ele encoste no jogador da dano * nivelmaldade nele
	Position += _speed;
	desenhar();
	if (getDistanciaoInicio() >= 100)
	{
		_speed.x *= -1;
	}
	_body.setPosition(Position);
}

void Entidades::InimigoFacil::salvar()
{
}

void Entidades::InimigoFacil::render()
{
}

void Entidades::InimigoFacil::danificar(Entidades::Jogador* pJog)
{
	pJog->operator--();
	pJog->knockBack(this);
}
