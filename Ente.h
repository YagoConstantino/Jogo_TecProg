#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Gerenciadores{ class Gerenciador_Grafico; }
namespace Entidades
{
	
	class Ente
	{
	protected:
		//Atributos 
		int id;
		Gerenciadores::Gerenciador_Grafico* _pGraf;
		sf::Texture* _pTexture;
		sf::Sprite* _body;
		
		//Criei um contador estatico para o ID
		static int _cont;
		

	public:
		Ente(Gerenciadores::Gerenciador_Grafico* pgra = nullptr);
		virtual  ~Ente() {};

		virtual void executar() = 0;
		void desenhar();

		int getId()const { return id; }

		void setTexture(sf::Texture* pText);
		sf::Texture* getTexture()const { return _pTexture; }
		

		
	};
	
}