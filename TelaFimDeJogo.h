#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"

class TelaFimDeJogo : public Entidades::Ente {
private:
	bool _mudouEstado;

	sf::Color cor;

	sf::Mouse _mouse;

	sf::Font _fonte;

	sf::Text _titulo;
	sf::Text _subTitulo;
	sf::Text _botaoVoltarAoMenu;

	Entidades::Jogador* _jogador1;
	Entidades::Jogador* _jogador2;

public:
	TelaFimDeJogo(Gerenciadores::Gerenciador_Grafico* _pGraf = nullptr, Entidades::Jogador* jog1 = nullptr, Entidades::Jogador* jog2 = nullptr);
	~TelaFimDeJogo();

	void carregarFonte();

	void criaBackground();
	void criarTitulo();
	void criarSubTitulo();
	void criarBotao();

	void verificarMouse();

	void destacar();
	void padronizar();
	void reposicionar();

	void desenharTela();

	void executar();
};