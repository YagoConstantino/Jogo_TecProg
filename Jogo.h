#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Floresta.h"

class Jogo
{
private:
	Entidades::Jogador* _jogador1;
	Gerenciadores::Gerenciador_Grafico* _GerenciadorGráfico;
	Fases::Floresta* _florest;

public:
	Jogo(std::string nome = "");
	~Jogo();
	void executar();
	void Menu();
};