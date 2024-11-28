#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

namespace Entidades { class Ente; }
namespace Gerenciadores{
	class Gerenciador_Grafico {
	private:
		// Atributos
		sf::RenderWindow* window;
		std::list<Entidades::Ente*> listaEntes;
		std::list<Entidades::Ente*>::iterator it;

		// Metodos
		void criarJanela();
		void update();
		void render();

	public:
		Gerenciador_Grafico();
		~Gerenciador_Grafico();

		// Metodos
		sf::RenderWindow* getWindow() const;
		void desenharEnte(Entidades::Ente* pE);
		void removerEnte(Entidades::Ente* pE);
	};
} 