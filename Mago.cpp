#include "Mago.h"

// IMPORTANTE
// direcao = -1 � esquerda, direcao = 1 � direita
// _clock e _segundos controlam a frequencia de bater do boss

Entidades::Mago::Mago(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra, Entidades::Jogador* pJog1, Entidades::Jogador* pJog2, int vidas)
	: Inimigo(inicialX, inicialY, pgra, pJog1,pJog2, vidas), 
	_vidasPerdidas(0), _projetil(nullptr), _segundosIntervaloPro(0.f) 
{

	setMaldade(3);
	setTipo(6);
	_speed.x = 0.06f;

	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/chefe.png"))
	{
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	setTexture(textura);
	_body.setScale(0.1f, 0.1f);

	_clock.restart();
	deltaTime.restart();
}

Entidades::Mago::~Mago() 
{
	_projetil = nullptr;
	_pJog1 = nullptr;
	_pJog2 = nullptr;
	_vidasPerdidas = 0;
	_direcao = 0;
}

void Entidades::Mago::setProjetil(Entidades::Projetil* pProj) 
{
	if (pProj == nullptr) 
	{
		std::cerr << "Ponteiro de projetil invalido. Impossivel vincular com boss.\n";
		return;
	}

	_projetil = pProj;
}

void Entidades::Mago::executar() 
{
	if (_num_vidas <= 0)
	{
		setVivo(false);
	}

	float dt = deltaTime.restart().asSeconds();

	_segundos += dt;
	_segundosIntervaloPro += dt;

	verificarVida();

	desenhar();
	 
	danificar(_pJog1);
}

void Entidades::Mago::verificarVida() {
	if (_vidasPerdidas > _num_vidas / 2) {
		_speed.x = 0.09f;
		setMaldade(2);
	}
}

void Entidades::Mago::mover() 
{
	Entidades::Jogador* jogadorAlvo = getJogadorMaisProximo();
	if (jogadorAlvo) 
	{
		if ((jogadorAlvo->getPositionX() - getPositionX() < 0.f))
			_direcao = -1;
		else
			_direcao = 1;

		sf::Vector2f velocidadeAtual = _speed;
		velocidadeAtual.x *= _direcao;

		Position += velocidadeAtual;
		_body.setPosition(Position);
	}
}

void Entidades::Mago::danificar(Entidades::Jogador* pJog) {
	
	// Fora de alcance
	if (getDistanciaInicioVector().x > 800.f) return;
	
	// Dentro do alcance para se mover
	mover();
	Entidades::Jogador* jogProximo = getJogadorMaisProximo();
	// Dentro do alcance para atirar
	if (jogProximo == _pJog1)
	{
		if (getDistanciaJogador1() > _body.getGlobalBounds().width * 1.65f) 
		{
			atirar();
		}
		// Dentro do alcance para bater
		else 
		{
			bater();
		}
	}
	else
	{
		if (getDistanciaJogador2() > _body.getGlobalBounds().width * 1.65f) 
		{
			atirar();
		}
		// Dentro do alcance para bater
		else {
			bater();
		}
	}
	
}

void Entidades::Mago::atirar() {
	// Cria o projetil
	Entidades::Jogador* jogadorProximo = getJogadorMaisProximo();

	if (!_projetil->getLancar() && _segundosIntervaloPro > 3.f) {
		// Zera o cronometro
		_segundosIntervaloPro = 0.f;

		// "Cria" projetil
		_projetil->setPosition
		(
			getPositionX(),
			getPositionY()
		);

		if (jogadorProximo == _pJog1) 
		{
			_projetil->lancar
			(
				0.20f * _direcao, (float)_projetil->calcularForcaY(getDistanciaJogador1(), 0.005f, 0.20f) * -1, getMaldade()
			);
		}
		else
		{
			_projetil->lancar
			(
				0.20f * _direcao, (float)_projetil->calcularForcaY(getDistanciaJogador2(), 0.005f, 0.20f) * -1, getMaldade()
			);
		}
		
	}
}

void Entidades::Mago::bater() 
{
	if (_segundos > 0.5f) 
	{
		_segundos = 0;
		Entidades::Jogador* jogProximo = getJogadorMaisProximo();

		if (jogProximo == _pJog1)
		{
			_pJog1->operator--(3);

			_pJog1->knockBack(this);
		}
		else
		{
			_pJog2->operator--(3);

			_pJog2->knockBack(this);
		}
			
		
	}
}

