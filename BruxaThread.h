#pragma once
#include "Bruxa.h"
#include "Thread.h"

namespace Entidades
{
	class BruxaThread :public Bruxa, public ThreadCPP
	{
	private:
		bool _rodar;
	public:
		BruxaThread(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			Entidades::Jogador* pJog1 = nullptr, Entidades::Jogador* pJog2 = nullptr, int vidas = 5);

		~BruxaThread();
		void setRodar(bool rod);

		void run();
		void executar();
	};
}