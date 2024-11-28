#pragma once
#include "Personagem.h"
#include<SFML/Graphics.hpp>
namespace Entidades
{
	class Jogador :public Entidades::Personagem
	{
	private:
		int _pontos;
		float _speed; // Sera que pode ser um sf::vector2f ?
	public:
		Jogador(float inlX = 0, float inY = 0,
			float H = 0, float W = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr);
		~Jogador();

		void executar() ;
		void salvar();
		void render() ;
	};

}

