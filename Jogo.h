#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Floresta.h"
#include "Menu.h"
#include "Ranking.h"

class Jogo
{
private:
	Entidades::Jogador* _jogador1;
	Gerenciadores::Gerenciador_Grafico* _GerenciadorGráfico;
	Menu* _menu;
	Fases::Floresta* _florest;
	Ranking* rank;

	static int stateNum;

public:
	Jogo(std::string nome = "");
	~Jogo();

	void criaFloresta();
	void criaMenu();

	void JogarFloresta();
	void JogarMenu();

	void executar();

	static void mudarStateNum(int state);
};