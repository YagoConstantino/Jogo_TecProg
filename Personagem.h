#pragma once
#include "Entidade.h"

namespace Entidades
{
	class Personagem :public Entidade
	{
	protected:
		int _num_vidas;

	public:
		Personagem(float inicialX = 0, float inicialY = 0, 
			float Heigth = 0, float Width = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr);
		virtual ~Personagem();

		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void render() = 0;
	};
}