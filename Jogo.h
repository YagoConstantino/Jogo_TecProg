#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Floresta.h"
#include "Menu.h"

class Jogo
{
private:
	Entidades::Jogador* _jogador1;
	Gerenciadores::Gerenciador_Grafico* _GerenciadorGráfico;
	Menu* _menu;
	Fases::Floresta* _florest;

	int stateNum;

public:
	Jogo(std::string nome = "");
	~Jogo();

	void criaFloresta();
	void criaMenu();

	void executar();

	void JogarFloresta();
	void JogarMenu();

};