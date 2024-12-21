#include "Bruxa.h"

Entidades::Bruxa::Bruxa(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog, int vidas)
	:Inimigo(inicialX,inicialY,pgra,pJog,vidas)

{
	setMaldade(2);
	_speed.x = 0.04f;

	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/Mortovivo-.png"))
	{
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	setTexture(textura);
	_body.setScale(1.f, 1.f);
}

Entidades::Bruxa::~Bruxa()
{
	_pJog = nullptr;
}

void Entidades::Bruxa::executar()
{

	if (atacar)
	{
		mover();
	}
	else
	{
		Position.y += _speed.y;
		_body.setPosition(Position);
	}


	if (getDistanciaJogador() <= 700)
	{
		atacar = true;
	}
	else
	{
		atacar = false;
	}
	desenhar();
}

void Entidades::Bruxa::mover()
{
	// Define a direcao do inimigo
	if (_pJog->getPositionX() - getPositionX() < 0.f)
		_direcao = -1; // para a esquerda
	else
		_direcao = 1;  // para a direita

	if (_pJog->getPositionY() - getPositionY() < -100.f && getDistanciaJogador() < 350.f)
	{
		pular();
	}

	sf::Vector2f velocidadeAtual = _speed;
	velocidadeAtual.x *= _direcao;

	Position += velocidadeAtual;
	_body.setPosition(Position);
}

void Entidades::Bruxa::danificar(Entidades::Jogador* pJog)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		pJog->operator--();

	}
	pJog->knockBack(this);

}

