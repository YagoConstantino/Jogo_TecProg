#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ente.h"

namespace Entidades
{
	class Entidade:public Entidades::Ente
	{
	protected:
		int _x;
		int _y;
		//sf vector?

		sf::Vector2f Position;
		sf::Vector2f Size;
		

	public:
		Entidade(float inicialX = 0, float inicialY = 0,float Heigth,float Width);
		~Entidade() {};

		float getX()const { return Position.x; }
		void setX(int x) { Position.x = x; }

		float getY()const { return Position.y; }
		void setY(int y) { Position.y = y; }

		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void render() = 0;
		
	};
}