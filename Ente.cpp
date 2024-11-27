#include "Ente.h"

namespace Entidades
{


	void Entidades::Ente::desenhar()
	{
		_pGraf->desenhar(_body);
	}
}