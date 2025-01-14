#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <functional>
#include "Ente.h"
#include "Gerenciador_Grafico.h"
namespace Menus
{

	class MenuFases : public Entidades::Ente
	{
	private:
		bool _mudouEstado;

		sf::Mouse mouse;

		sf::Font _fonte;

		sf::Text _textoFases;
		sf::Text _nomeFaseFloresta;
		sf::Text _nomeFaseCastelo;
		sf::Text _textoJogadores;

		sf::RectangleShape _imagemFaseFloresta;
		sf::RectangleShape _imagemFaseCastelo;
		sf::Text _botaoConfirmaFase;
		bool _faseFloresta;
		bool _faseCastelo;
		bool _confirmaFase;

		sf::Text _botaoUmJog;
		sf::Text _botaoDoisJog;
		bool _umJog;
		bool _doisJog;

		sf::RectangleShape _caixaTexto1;
		sf::Text _nomeJog1;
		std::string _nome1;
		bool _estaDigitandoCaixa1;
		bool _primeiraVezCaixa1;

		sf::RectangleShape _caixaTexto2;
		sf::Text _nomeJog2;
		std::string _nome2;
		bool _estaDigitandoCaixa2;
		bool _primeiraVezCaixa2;

		sf::Text _botaoConfirmaNomes;
		bool _confirmaNomes;

		std::vector<std::pair<sf::RectangleShape*, std::function<void()>>> _retangulos;
		std::vector<std::pair<sf::Text*, std::function<void()>>> _textos;
		int sizeRetangulos;
		int sizeTextos;

	protected:
		void executarFaseFloresta();
		void executarFaseCastelo();
		void executarConfirmaFase();
		void executarUmJog();
		void executarDoisJog();
		void executarCaixaTexto1();
		void executarCaixaTexto2();
		void executarConfirmaNomes();

	public:
		MenuFases(Gerenciadores::Gerenciador_Grafico* _pGraf = nullptr);
		~MenuFases();

		void carregarFonte();

		void criaBackground();
		void criaMetadeEsquerda();
		void criaMetadeDireita();

		void carregarObjetos();

		void verificarCliques();
		void verificarConfirma();

		void destacar(sf::Text* texto);
		void destacar(sf::RectangleShape* retangulo);
		void padronizar(sf::Text* texto);
		void padronizar(sf::RectangleShape* retangulo);

		void desenhar();

		void executar();
	};
}
