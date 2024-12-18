#pragma once
#include "Fase.h"
#include "Bruxa.h"
#include "BarraMagica.h"
namespace Fases
{
	class Floresta :public Fase
	{
	private:
		const int maxBruxas = 4;
		const int maxBarraMagicas = 2;
	public:
		Floresta(Gerenciadores::Gerenciador_Grafico* pgra = nullptr, Entidades::Jogador* jog = nullptr);
		~Floresta();

		void criaBarrasMagicas();
		void criaBruxas();

		void executar();
		void criarInimigos();
		void criarObstaculos();


	};
}