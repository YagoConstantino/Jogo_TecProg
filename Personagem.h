#pragma once
#include "Entidade.h"

namespace Entidades
{
	class Personagem :public Entidade
	{
	protected:
		int _num_vidas;
		bool onGround;

	public:
		Personagem(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr);
		virtual ~Personagem();

		bool getOnGround()const;
		void setGround(bool ong);

		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void render() = 0;
	};
}