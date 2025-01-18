#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <functional>
#include "Ente.h"
#include "Gerenciador_Grafico.h"

namespace Menus {
	class MenuFases : public Entidades::Ente
	{
	private:
		bool _mudouEstado;

		sf::Mouse mouse;

		sf::Font _fonte;

		sf::Text _textoFases;
		sf::Text _nomeFaseFloresta;
		sf::Text _nomeFaseCastelo;

		sf::RectangleShape _imagemFaseFloresta;
		sf::RectangleShape _imagemFaseCastelo;
		sf::Text _botaoConfirmaFase;
		bool _faseFloresta;
		bool _faseCastelo;

		std::vector<std::pair<sf::RectangleShape*, std::function<void()>>> _retangulos;
		std::vector<std::pair<sf::Text*, std::function<void()>>> _textos;
		int sizeRetangulos;
		int sizeTextos;

	protected:
		void executarFaseFloresta();
		void executarFaseCastelo();
		void executarConfirmaFase();

	public:
		MenuFases(Gerenciadores::Gerenciador_Grafico* _pGraf = nullptr);
		~MenuFases();

		void carregarFonte();

		void criaBackground();
		void criaResto();

		void carregarObjetos();

		void verificarCliques();

		void destacar(sf::Text* texto);
		void destacar(sf::RectangleShape* retangulo);
		void padronizar(sf::Text* texto);
		void padronizar(sf::RectangleShape* retangulo);

		void desenhar();

		void executar();
	};
}