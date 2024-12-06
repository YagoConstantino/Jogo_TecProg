#include "Entidade.h"

namespace Entidades
{
	Entidades::Entidade::Entidade(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra):
		Ente(pgra), Position(inicialX, inicialY),_clock(),_segundos(0.0f)
	{
		_body.setPosition(Position);
		//_body.setScale(Size);
	}
	void Entidade::restartClock()
	{
		_clock.restart();
	}
}

