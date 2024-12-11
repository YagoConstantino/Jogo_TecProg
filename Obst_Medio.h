#pragma once

#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include "Obstaculo.h"

namespace Entidades {
	class Obst_Medio : public Obstaculo
	{
	private:
		float _duracaoParalisia;

	public:
		Obst_Medio(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr);
		~Obst_Medio();

		void executar();
		void obstacular(Entidades::Jogador* pJog);

		void salvar();
		void render();
	};
}