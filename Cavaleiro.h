#pragma once
#include "Inimigo.h"

namespace Entidades
{
	class Cavaleiro :public Inimigo
	{
	private:
		
	public:
		Cavaleiro(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			Entidades::Jogador* pJog = nullptr, int vidas = 1);
		~Cavaleiro();

		

		void executar();
		//void SalvarDataBuffer();
		void mover();
		void danificar(Entidades::Jogador* pJog);
	};
}