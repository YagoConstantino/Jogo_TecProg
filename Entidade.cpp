#include "Entidade.h"

namespace Entidades
{
	Entidades::Entidade::Entidade(float inicialX, float inicialY, 
		float Heigth, float Width, Gerenciadores::Gerenciador_Grafico* pgra):
		Ente(pgra), Position(inicialX, inicialY), Size(Width, Heigth)
	{
		_body = new sf::Sprite();
		_body->setPosition(Position);
		_body->setScale(Size);
	}
}

