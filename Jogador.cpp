#include "Jogador.h"

Entidades::Jogador::Jogador(float inlX, float inY, float H, float W, Gerenciadores::Gerenciador_Grafico* pgra)
	:Personagem(inlX,inY,H,W,pgra),_pontos(0),_speed(5)
{
	_body = new sf::Sprite();
	//_pGraf->desenhar(this);
	_body->setColor(sf::Color::Red);
}

Entidades::Jogador::~Jogador()
{
    if (_body)
    {
        delete _body;
    }
    if (_pTexture)
    {
        delete _pTexture;
    }

	_pGraf = nullptr;
	_body = nullptr;
    _pTexture = nullptr;
	Position.x = 0.0;
	Position.y = 0.0;
	Size.x = 0.0;
	Size.y = 0.0;
}

void Entidades::Jogador::executar(sf::Event* ev)
{/*
 //Esses testes de se a posicao mais o tamanho nao chegou na borda devem ser transferidos para o Gerenciador de Colisoes
 //Depois não sei se precisa desse Evento, não lembro como que o sfml captura o teclado, se usa o evento ou não
	
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Position.x + Size.x < _pGraf->getWindow()->getSize().x)
		Position.x += _speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (Position.y > _speed))
		Position.y -= _speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (Position.x > _speed))
		Position.x -= _speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (Position.y + Size.y < _pGraf->getWindow()->getSize().y))
		Position.y += _speed;

    _body->setPosition(Position);

	//_pGraf->desenhar(this);*/
}

void Entidades::Jogador::salvar()
{
}

void Entidades::Jogador::render()
{
}
