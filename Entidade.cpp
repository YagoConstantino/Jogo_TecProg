#include "Entidade.h"

namespace Entidades
{
	Entidades::Entidade::Entidade(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra):
		Ente(pgra), Position(inicialX, inicialY)
	{
		_body.setPosition(Position);
		//_body.setScale(Size);
	}
}

