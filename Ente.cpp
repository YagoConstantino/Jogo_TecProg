#include "Ente.h"

namespace Entidades
{
	Ente::Ente(Gerenciadores::Gerenciador_Grafico* pgra):id(_cont++), _pGraf(pgra), _pTexture(nullptr), _body() 
	{
	}
	void Entidades::Ente::desenhar()
	{
		 if (_pGraf)
        _pGraf->desenhar(_body);
	}
	void Ente::setTexture(sf::Texture* pText)
	{
		if (pText) 
		{
			_pTexture = pText;
			_body.setTexture(*pText);
		}
	}
}