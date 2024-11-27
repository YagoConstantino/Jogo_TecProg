#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Entidades
{
	class Ente
	{
	protected:

		int id;
		GerenciadorGrafico* _pGraf;
		sf::Texture* _pTexture;
		sf::Sprite _body;
		//Criei um contador estatico para o ID
		static int _cont;
		

	public:
		Ente(GerenciadorGrafico* pgra = nullptr) :id(_cont++), _pGraf(nullptr), _body(), _pGraf(pgra){}
		~Ente() {};
		virtual void executar() = 0;
		void desenhar();

		int getId()const { return id; }

		void setTexture(sf::Texture* pText) { if (pText)_pTexture = pText; }
		sf::Texture* getTexture()const { return _pTexture; }
		

		//Optei por não fazer get pois todos os Entes terão acesso ao Gerenciador
		//void setGraf(GerenciadorGrafico* pgra) { if (pgra)_pGraf = pgra; }

		
	};
	int Ente::_cont(1);
}