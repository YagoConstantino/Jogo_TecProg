#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ente.h"

namespace Entidades
{
	class Entidade:public Entidades::Ente
	{
	protected:

		
		sf::Vector2f Position;
		sf::Vector2f Size;
		

	public:
		Entidade(float inicialX = 0, float inicialY = 0, 
			float Heigth = 0, float Width = 0, Gerenciadores::Gerenciador_Grafico* pgra=nullptr);
		virtual ~Entidade() {};

		float getX()const { return Position.x; }
		void setX(float x) { Position.x = x; }

		float getY()const { return Position.y; }
		void setY(float y) { Position.y = y; }

		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void render() = 0;
		
	};
}