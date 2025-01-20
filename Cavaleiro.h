#pragma once
#include "Inimigo.h"
#include "Constantes.h"
namespace Entidades
{
	class Cavaleiro :public Inimigo
	{
	private:

	public:
		Cavaleiro(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			Entidades::Jogador* pJog1 = nullptr, Entidades::Jogador* pJog2 = nullptr, int vidas = Constantes::VIDAS_CAVALEIRO);
		~Cavaleiro();



		void executar();
		//void SalvarDataBuffer();
		void mover();
		void danificar(Entidades::Jogador* pJog);
	};
}