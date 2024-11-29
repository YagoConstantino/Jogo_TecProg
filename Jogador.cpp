#include "Jogador.h"

Entidades::Jogador::Jogador(float inlX, float inY, Gerenciadores::Gerenciador_Grafico* pgra)
	:Personagem(inlX,inY,pgra),_pontos(0),_speed(5)
{
	sf::Texture* textura = new sf::Texture();
	if (!textura->loadFromFile("8-bits-characters-gaming-assets.jpg")) {
		std::cout << "Falha ao carregar textura!" << std::endl;
	}
	setTexture(textura);

	//_body.setColor(sf::Color::Red);
	//_pGraf->desenhar(this);
}

Entidades::Jogador::~Jogador()
{
  
    if (_pTexture)
    {
        delete _pTexture;
    }

	_pGraf = nullptr;
    _pTexture = nullptr;
	Position.x = 0.0;
	Position.y = 0.0;
	//Size.x = 0.0;
	//Size.y = 0.0;
}

void Entidades::Jogador::setPosition(float x, float y)
{
	Position.x = x;
	Position.y = y;
	_body.setPosition(Position);
}

sf::Vector2f Entidades::Jogador::getPosition() const
{
	return Position;
}

void Entidades::Jogador::executar()
{
 //Esses testes de se a posicao mais o tamanho nao chegou na borda devem ser transferidos para o Gerenciador de Colisoes
 //Depois não sei se precisa desse Evento, não lembro como que o sfml captura o teclado, se usa o evento ou não
	
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Position.x + _body.getScale().x < _pGraf->getWindow()->getSize().x)
		Position.x += _speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (Position.y > _speed))
		Position.y -= _speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (Position.x > _speed))
		Position.x -= _speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (Position.y + _body.getScale().y < _pGraf->getWindow()->getSize().y))
		Position.y += _speed;

    _body.setPosition(Position);
	_pGraf->desenhar(this);

}

void Entidades::Jogador::salvar()
{
}

void Entidades::Jogador::render()
{
}
