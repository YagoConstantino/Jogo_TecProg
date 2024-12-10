#include "Entidade.h"

namespace Entidades
{
	Entidades::Entidade::Entidade(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra):
		Ente(pgra), Position(inicialX, inicialY),_clock(),_segundos(0.0f)
	{
		_body.setPosition(Position);
		//_body.setScale(Size);
	}
	void Entidade::setPosition(float x, float y)
	{
		Position.x = x;
		Position.y = y;
		_body.setPosition(Position);
	}
	sf::Vector2f Entidade::getPosition() const
	{
			return Position;
	}
	void Entidade::restartClock()
	{
		_clock.restart();
	}
}

