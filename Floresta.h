#pragma once

#include "Fase.h"
#include "MortoVivo.h"

#include "BarraMagica.h"
namespace Fases
{
	class Floresta :public Fase
	{
	private:
		const int maxMortovivo;
		const int maxBarraMagicas;
	public:
		Floresta(Gerenciadores::Gerenciador_Grafico* pgra = nullptr, Entidades::Jogador* jog1 = nullptr,Entidades::Jogador* jog2 = nullptr);
		~Floresta();

		void criaBarrasMagicas();
		void criaBruxas();

		void executar();
		void criarInimigos();
		void criarObstaculos();
		void criarCenario();
	};
}