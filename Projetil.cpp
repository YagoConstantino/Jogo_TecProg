#include "Projetil.h"

// TO DO
// A posicao do projetil deve depender da posicao do inimigo, o qual nao tem
// o projetil deve desaparecer ao tocar em jogador, mas não ocorre pois eh preciso inimigo

// ------------------------------- PUBLIC ----------------------------------------------------

Entidades::Projetil::Projetil(int dano, float speed, Gerenciadores::Gerenciador_Grafico* pGraf) 
	: _dano(dano), _speed(speed), Entidade(0.f,0.f, pGraf){
	_lancar = false;

	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/flecha.png")) {
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	setTexture(textura);
}

Entidades::Projetil::~Projetil() {
	_pGraf = nullptr;
	_dano = 0;
	_speed = 0;

	if (_pTexture)
	{
		delete _pTexture;
	}
	_pTexture = nullptr;
}

void Entidades::Projetil::executar() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && _lancar == false) {
		_lancar = true;
		Position.y = 20.f;
		Position.x = _pGraf->getWindow()->getSize().x - _body.getScale().x;

		_body.setPosition(Position);
	}

	if (_lancar) {
		_pGraf->desenhar(this);
		if (Position.x - _speed > 0)
			Position.x -= _speed;

		_body.setPosition(Position);
	}
}

const int Entidades::Projetil::getDano() const {
	return _dano;
}

void Entidades::Projetil::salvar()
{
}

