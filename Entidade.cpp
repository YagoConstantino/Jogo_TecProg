#include "Entidade.h"

namespace Entidades
{
	Entidades::Entidade::Entidade(float inicialX, float inicialY, float Heigth, float Width)
	{
		Position.x = inicialX;
		Position.y = inicialY;
		Size.x = Width;
		Size.y = Heigth;
	}
}

