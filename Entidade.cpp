#include "Entidade.h"

namespace Entidades
{
	Entidades::Entidade::Entidade(float inicialX, float inicialY, float Heigth, float Width):
		Ente()
	{
		Position.x = inicialX;
		Position.y = inicialY;
		Size.x = Width;
		Size.y = Heigth;

		_body.setPosition(Position);
		_body.setScale(Size);
	}
}

