#pragma once
#include "Personagem.h"
#include <iostream>
#include<SFML/Graphics.hpp>
namespace Entidades
{
	class Jogador :public Entidades::Personagem
	{
	private:
		int tempoPulo;
		int _pontos;
		//sf::Vector2f _speed; // Sera que pode ser um sf::vector2f ?
		std::string nome;
		float _velocidade;
	public:
		Jogador(float inlX = 0, float inY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,std::string name = "");
	
		
		~Jogador();

		void setNome(std::string& name);
		std::string& getNome();

		void setPosition(float x, float y);
		sf::Vector2f getPosition()const;

		void operator++();
		void operator--();

		void knockBack();
		void mover();

		void executar();
		void salvar();
		void render();
	};

}

