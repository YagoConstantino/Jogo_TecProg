#include "Ente.h"
#include "Gerenciador_Grafico.h"
namespace Entidades
{
	int Ente::_cont(1);

	Ente::Ente(Gerenciadores::Gerenciador_Grafico* pgra):id(_cont++), _pGraf(pgra), _pTexture(nullptr), _body() 
	{
	}
	void Entidades::Ente::desenhar()
	{
		 if (_pGraf)
        _pGraf->desenhar(this);
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