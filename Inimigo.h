#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include <iostream>
#include <math.h>
namespace Entidades
{
	class Inimigo :public Entidades::Personagem
	{
	protected:

		bool atacar;
		int _nivel_maldade;
		Entidades::Jogador* _pJog;

		float posInicialX;
		float posInicialY;
	public:
		Inimigo(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			Entidades::Jogador*pJog=nullptr,int vidas = 1);
		virtual ~Inimigo();

		void setMaldade(int mal);
		int getMaldade()const;

		void setJogador(Entidades::Jogador* pJog);
		//Entidades::Jogador* getJogador()const;

		double getDistanciaJogador();
		double getDistanciaoInicio();
		sf::Vector2f getDistanciaInicioVector();

		virtual void executar() = 0;
		//void SalvarDataBuffer();
		virtual void mover() = 0;
		virtual void danificar(Entidades::Jogador* pJog) = 0;
	};
}