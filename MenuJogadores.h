#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Gerenciador_Grafico.h"

class MenuJogadores : public Entidades::Ente {
private:
	bool _mudouEstado;

	sf::Mouse _mouse;

	sf::Font _fonte;

	sf::Text _textoJogadores;

	sf::Text _botaoUmJog;
	sf::Text _botaoDoisJog;

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

private:
	void executarCaixaTexto1();
	void executarCaixaTexto2();
	void executarConfirmaNomes();


public:
	MenuJogadores(Gerenciadores::Gerenciador_Grafico* pGraf = nullptr);
	~MenuJogadores();

	void carregarFonte();

	void criaBackground();
	void criaResto();

	void destacar(sf::RectangleShape* retangulo);
	void padronizar(sf::RectangleShape* retangulo);

	void desenhar();

	void verificarCliques();

	void executar();
};