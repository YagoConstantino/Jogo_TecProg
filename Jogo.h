#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Floresta.h"
#include "Menu.h"
#include "MenuFases.h"

class Jogo
{
private:
	Entidades::Jogador* _jogador1;
	Gerenciadores::Gerenciador_Grafico* _GerenciadorGráfico;
	Menu* _menu;
	MenuFases* _menuFases;
	Fases::Floresta* _florest;

	static int stateNum;

public:
	Jogo(std::string nome = "");
	~Jogo();

	void criaFloresta();
	void criaMenu();
	void criaMenuFases();

	void JogarFloresta();
	void JogarMenu();
	void JogarMenuFases();

	void executar();

	static void mudarStateNum(int state);
};