#pragma once

#include <vector>
#include "Fase.h"
#include "Bruxa.h"
#include "BarraMagica.h"
#include "Inimigo.h"

namespace Fases
{
	class Floresta :public Fase
	{
	private:
		const int maxBruxas;
		const int maxBarraMagicas;

		std::vector<Entidades::Inimigo*> _inimigos;

	public:
		Floresta(Gerenciadores::Gerenciador_Grafico* pgra = nullptr, Entidades::Jogador* jog1 = nullptr,Entidades::Jogador* jog2 = nullptr);
		~Floresta();

		void criaBarrasMagicas();
		void criarCavaleiros();
		void criaBruxas();

		void executar();
		void criarInimigos();
		void criarObstaculos();
		void criarCenario();

		void verificarInimigos();
	};
}