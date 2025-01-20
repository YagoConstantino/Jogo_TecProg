#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Gerenciador_Grafico.h"

namespace Menus {
	class MenuPause : public Entidades::Ente{
	private:
		bool _mudouEstado;
		bool _voltaAoMenu;

		sf::Clock _clock;
		float _segundos;

		sf::Sprite* _imagemFase;

		sf::Mouse _mouse;
		bool _houveClique;

		sf::Font _fonte;

		sf::Text _titulo;
		sf::Text _botaoRetomar;
		sf::Text _botaoSalvarSair;

	public:
		MenuPause(Gerenciadores::Gerenciador_Grafico* _pGraf = nullptr, sf::Sprite* imgFase = nullptr);
		~MenuPause();

		const bool getVoltaAoMenu() const;

		void carregarFonte();

		void criarImagemFase();
		void criarImagemPause();
		void criarTitulo();
		void criarBotoes();

		void verificarMouse();
		void verificarMovimento();

		void destacarTexto(sf::Text& texto);
		void reposicionarTexto(sf::Text& texto);
		void padronizar(sf::Text& texto);

		void executarRetomar();
		void executarSalvarSair();

		void desenharMenu();

		void executar();
	};
}