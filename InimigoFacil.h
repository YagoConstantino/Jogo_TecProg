#pragma once
#include "Inimigo.h"

namespace Entidades
{
	class InimigoFacil :public Inimigo
	{
	private:
		
	public:
		InimigoFacil(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			Entidades::Jogador* pJog = nullptr, int vidas = 1);
		~InimigoFacil();

		

		void executar();
		//void SalvarDataBuffer();
		void mover();
		void danificar(Entidades::Jogador* pJog);
	};
}