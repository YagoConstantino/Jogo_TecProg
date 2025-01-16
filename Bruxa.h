#pragma once
#include "Inimigo.h"

namespace Entidades
{
	class Bruxa :public Inimigo
	{
	private:
	public:
		Bruxa(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			Entidades::Jogador* pJog1 = nullptr, Entidades::Jogador* pJog2 = nullptr, int vidas = 5);
		virtual ~Bruxa();

		virtual void executar();
	
		//void SalvarDataBuffer();
		virtual void mover();
		virtual void danificar(Entidades::Jogador* pJog);
	};
}