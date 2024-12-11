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
			Gerenciadores::Gerenciador_Grafico* pgra = nullptr, int vidas = 10 );
		
		virtual ~Personagem();


		int getVidas()const;
		void setVidas(int vid);
		
		void operator++();
		void operator--();

		void pular();

		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void render() = 0;
	};
}