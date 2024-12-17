#pragma once

#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include "Obstaculo.h"

namespace Entidades {
	class BarraMagica : public Obstaculo
	{
	private:
		float _duracaoParalisia;

	public:
		BarraMagica(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr);
		~BarraMagica();

		void executar();
		void obstacular(Entidades::Jogador* pJog);
		//void SalvarDataBuffer();
		
	};
}