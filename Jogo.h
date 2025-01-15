#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Floresta.h"
#include "Castelo.h"
#include "Menu.h"
#include "MenuFases.h"
#include "MenuJogadores.h"
#include "Ranking.h"
#include "TelaFimDeJogo.h"

class Jogo
{
private:
	Entidades::Jogador* _jogador1;
	Entidades::Jogador* _jogador2;
	Gerenciadores::Gerenciador_Grafico* _GerenciadorGrafico;
	Menu* _menu;
	MenuJogadores* _menuJogadores;
	MenuFases* _menuFases;
	Fases::Floresta* _florest;
	Fases::Castelo* _castelo;
	Ranking* rank;
	TelaFimDeJogo* _telaFimDeJogo;

	static int stateNum;

public:
	Jogo();
	~Jogo();

	void criaCastelo();
	void criaFloresta();
	void criaMenu();
	void criaMenuFases();
	void criaMenuJogadores();
	void criaTelaFimDeJogo();

	void JogarCastelo();
	void JogarFloresta();
	void JogarMenu();
	void JogarMenuFases();
	void JogarMenuJogadores();
	void JogarTelaFimDeJogo();

	void executar();

	static void mudarStateNum(int state);

	bool criarJogador1(string nome);
	bool criarJogador2(string nome);
};