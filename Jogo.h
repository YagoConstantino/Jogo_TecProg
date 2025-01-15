#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Floresta.h"
#include "Castelo.h"
#include "Menu.h"
#include "MenuFases.h"
#include "MenuJogadores.h"
#include "MenuRanking.h"
#include "Ranking.h"
#include "TelaFimDeJogo.h"

class Jogo
{
private:
	Entidades::Jogador* _jogador1;
	Entidades::Jogador* _jogador2;

	Gerenciadores::Gerenciador_Grafico* _GerenciadorGrafico;
	Menus::Menu* _menu;
	MenuJogadores* _menuJogadores;
	Menus::MenuFases* _menuFases;
	Menus::MenuRanking* _menuRanking;
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
	void criaMenuRanking();

	void JogarCastelo();
	void JogarFloresta();
	void JogarMenu();
	void JogarMenuFases();
	void JogarMenuJogadores();
	void JogarTelaFimDeJogo();
	void JogarMenuRanking();

	void deletarJogadores();

	void executar();
	void destroiEstadosAnteriores();
	void atualizaRanking();

	static void mudarStateNum(int state);

	bool criarJogador1(string nome);
	bool criarJogador2(string nome);
};