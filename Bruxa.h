#pragma once
#include "Inimigo.h"

namespace Entidades
{
	class Bruxa :public Inimigo
	{
	private:
		
	public:
		Bruxa(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			Entidades::Jogador* pJog = nullptr, int vidas = 3);
		~Bruxa();

		void executar();
		//void SalvarDataBuffer();
		void mover();
		void danificar(Entidades::Jogador* pJog);
	};
}