#include "Jogador.h"
#include "stdlib.h"

Entidades::Jogador::Jogador(float inlX, float inY, Gerenciadores::Gerenciador_Grafico* pgra, std::string name)
	:Personagem(inlX, inY, pgra, 10), _pontos(0), nome(name), tempoPulo(80.f), _velocidade(0.2f), 
	_paralisado(false), _duracaoParalisia(0.f), _tempoParalisado(0.f),_clockParalisia(),
	_atacando(false),_clockAtaque(),_tempoAtaque(0)
{
	setTipo(3);

	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/Player1.png"))
	{
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	adicionarTextura("assets/Player1.png");
	adicionarTextura("assets/Player1Esquerda.png");

	Ente::setTexture(textura);
	_body.setScale(0.1f, 0.1f);

	// tela de paralisia
	texturaTela = new sf::Texture();

	if (!texturaTela->loadFromFile("assets/TelaParalisada.png")) {
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	telaParalisada.setTexture(*texturaTela);

	// tamanho da tela paralisada
	sf::Vector2u tamJanela = _pGraf->getWindow()->getSize();
	float escalaX = (float)tamJanela.x / telaParalisada.getGlobalBounds().width;
	float escalaY = (float)tamJanela.y / telaParalisada.getGlobalBounds().height;

	telaParalisada.setScale
	(
		escalaX,
		escalaY
	);

	// Posicao
	telaParalisada.setPosition(0.f, 0.f);
}

Entidades::Jogador::~Jogador()
{

	if (_pTexture)
	{
		delete _pTexture;
	}
	if (texturaTela)
	{
		delete texturaTela;
	}

	_pGraf = nullptr;
	_pTexture = nullptr;
	texturaTela = nullptr;
	Position.x = 0.0;
	Position.y = 0.0;

}

void Entidades::Jogador::setNome(std::string& name)
{
	nome = name;
}

std::string Entidades::Jogador::getNome()const
{
	return nome;
}

void Entidades::Jogador::setParalisado(const bool para, float duracao)
{
	_paralisado = para;
	_duracaoParalisia = duracao;
}

void Entidades::Jogador::SetPontos(int pont)
{
	_pontos = pont;
}

int Entidades::Jogador::getPontos() const
{
	return _pontos;
}



void Entidades::Jogador::pular()
{
	if (_onGround)
	{
		_speed.y = -1.75f;
		setGround(false);
	}
}

void Entidades::Jogador::mover()
{

	_speed.x = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_speed.x += _velocidade;
		setDirecao(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

		tempoPulo += _clock.getElapsedTime().asMilliseconds();
		if (tempoPulo >= 80.f)
		{
			pular();
			tempoPulo = 0.f;

		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		_speed.x -= _velocidade;
		setDirecao(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) 
	{
		setAtacando(true);
	}
	// Detectar o soltar da tecla F
	else 
	{
		setAtacando(false);
	}

	// (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (Position.y + _body.getGlobalBounds().height <= _pGraf->getWindow()->getSize().y))
		//_speed.y = +_velocidade;

	

	Position += _speed;
	setTexture(getDirecao());

}

void Entidades::Jogador::setTexture(int direcao)
{
	int index;
	if (direcao == 1)
		index = 0;
	
	else
		index = 1;
	_body.setTexture(*_texturas[index]);
}

void Entidades::Jogador::adicionarTextura(const std::string& path)
{
	sf::Texture* textura1 = new sf::Texture();
	

	if (textura1->loadFromFile(path))
	{
		_texturas.push_back(textura1);
	}
	else
	{
		std::cout << "Falha ao carregar texturas!" << std::endl;
	}
}

bool Entidades::Jogador::getAtacando() const
{
	return _atacando;
}

void Entidades::Jogador::setAtacando(bool atac)
{
	_atacando = atac;
}


void Entidades::Jogador::executar()
{
	if (!_paralisado) {
		mover();
		_clockParalisia.restart();
	}
	else {
		_tempoParalisado += _clockParalisia.getElapsedTime().asSeconds();

		if (_tempoParalisado > _duracaoParalisia) {
			_tempoParalisado = 0.f;
			_paralisado = false;
			_clockParalisia.restart();
		}

		_pGraf->getWindow()->draw(telaParalisada);
	}

	if (_speed.x > 0.3f)
	{
		setSpeed(0.3f, getSpeedY());
	}

	if (_num_vidas <= 0)
	{
		setVivo(false);
	}

	if (_onGround)
	{
		restartClock();
	}

	_body.setPosition(Position);
	_pGraf->desenhar(this);

}