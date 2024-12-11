#pragma once
#include "Personagem.h"
#include <iostream>
#include<SFML/Graphics.hpp>
namespace Entidades
{
	class Jogador :public Entidades::Personagem
	{
	private:
		bool _mover;

		int tempoPulo;
		int _pontos;
		
		std::string nome;
		float _velocidade;
	public:
		Jogador(float inlX = 0, float inY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			std::string name = "");
		
		~Jogador();

		void setNome(std::string& name);
		std::string getNome()const;
		
		void setMover(const bool mover);
		
		void AumentarPontos(int i);
		int getPontos()const;

		void knockBack(Entidades::Entidade* ente);
		void mover();

		void executar();
		void salvar();
		void render();
	};

}

