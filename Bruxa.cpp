#include "Bruxa.h"
#include "Constantes.h"
Entidades::Bruxa::Bruxa(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog1, Entidades::Jogador* pJog2, int vidas)
	:Inimigo(inicialX,inicialY,pgra,pJog1,pJog2,vidas)

{
	setTipo(Constantes::TIPO_BRUXA);
	setMaldade(Constantes::MALDADE_BRUXA);
	_speed.x = Constantes::VEL_BRUXA;

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
	_pJog1 = nullptr;
	_pJog2 = nullptr;
}

void Entidades::Bruxa::executar()
{
	double distanciaJog1 = -1;
	double distanciaJog2 = -1;
	
	if(_pJog1) distanciaJog1 = getDistanciaJogador1();
	if(_pJog2) distanciaJog2 = getDistanciaJogador2();

	if (
		(distanciaJog1 > 0 && distanciaJog1 <= Constantes::DISTANCIA_ATIVACAO_BRUXA) 
		|| (distanciaJog2 > 0 && distanciaJog2 <= Constantes::DISTANCIA_ATIVACAO_BRUXA)
		)
	{
		atacar = true;
	}
	else
	{
		atacar = false;
	}

	
	if (atacar)
	{
		mover();
	}
	else
	{
		Position.y += _speed.y;
		_body.setPosition(Position);
	}

	
	if (_num_vidas <= 0)
	{
		setVivo(false);
	}

	desenhar();
	_speed.x = 0.04f;
	
}



void Entidades::Bruxa::mover()
{
	Entidades::Jogador* jogadorMaisProximo = getJogadorMaisProximo();

	if (jogadorMaisProximo != nullptr)
	{
		if (jogadorMaisProximo->getPositionX() - getPositionX() < 0.f)
		{
			_direcao = -1; // Para a esquerda
		}
		else
		{
			_direcao = 1;  // Para a direita
		}

		if (getPositionY() - jogadorMaisProximo->getPositionY() >= 150)
		{
			pular();
		}
	}

	// Verificando se o jogador mais próximo não é nulo antes de se mexer
	if (jogadorMaisProximo != nullptr)
	{
		sf::Vector2f velocidadeAtual = _speed;
		velocidadeAtual.x *= _direcao;
		Position += velocidadeAtual;
		_body.setPosition(Position);
	}
}

void Entidades::Bruxa::danificar(Entidades::Jogador* pJog)
{
	pJog->operator--(2);
	
	pJog->knockBack(this);

}

