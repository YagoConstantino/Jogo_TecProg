#include "Entidade.h"

namespace Entidades
{
	Entidades::Entidade::Entidade(float inicialX, float inicialY, float Heigth, float Width, GerenciadorGrafico* pgra):
		Ente(pgra), Position(inicialX, inicialY), Size(Width, Heigth)
	{
		_body.setPosition(Position);
		_body.setScale(Size);
	}
}

