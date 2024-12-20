#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Entidades { class Ente; }

namespace Gerenciadores{
	class Gerenciador_Grafico {
	private:
		// Atributos
		sf::RenderWindow* window;
		sf::View view;

		//Implementando Singleton
		static Gerenciador_Grafico* instancia;
		Gerenciador_Grafico();

	public:
		
		static Gerenciador_Grafico* getInstancia();
		~Gerenciador_Grafico();

		void desenhar(Entidades::Ente* pE);
		void desenhar(sf::Text* texto);
		//void desenhar(sf::RectangleShape& shape);
		void clear();
		void display();
		sf::RenderWindow* getWindow()const;
		bool getOpen()const;
		void closeWindow();
		

	};
} 