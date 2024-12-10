#pragma once
#include "Inimigo.h"

namespace Entidades
{
	class InimigoFacil :public Inimigo
	{
	private:
		float posInicialX;
		float posInicialY;
	public:
		InimigoFacil(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			Entidades::Jogador* pJog = nullptr, int vidas = 1);
		~InimigoFacil();

		double getDistanciaoInicio();

		void executar();
		void salvar();
		void render();
		void danificar(Entidades::Jogador* pJog);
	};
}