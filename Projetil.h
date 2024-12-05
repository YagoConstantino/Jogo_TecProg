#pragma once

#include "Entidade.h"
#include "Gerenciador_Grafico.h"

namespace Entidades {
	class Projetil : public Entidade{
	protected:
		int _dano;
		float _speed;
		bool _lancar;

	public:
		Projetil(int dano = 1, float speed = 1.f, Gerenciadores::Gerenciador_Grafico* pGraf = nullptr);
		~Projetil();

		const int getDano() const;

		void executar();
		void render();
		void salvar();
	};
}