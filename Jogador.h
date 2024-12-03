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
		const char* nome;
	public:
		Jogador(float inlX = 0, float inY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,const char* name = "");
		
		~Jogador();

		void setPosition(float x, float y);
		sf::Vector2f getPosition()const;

		void executar() ;
		void salvar();
		void render() ;
	};

}

