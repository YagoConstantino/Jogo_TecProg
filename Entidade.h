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
		//sf::Vector2f Size;
		
	public:
		Entidade(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra=nullptr);
		virtual ~Entidade() {};

		float getPositionX()const { return Position.x; }
		void setPositionX(float x) { Position.x = x; }

		float getPositionY()const { return Position.y; }
		void setPositionY(float y) { Position.y = y; }

		/*
		float getSizeWIDTH()const { return Size.x; }
		void setSizeWIDTH(float x) { Size.x = x; }

		float getSizeHeight()const { return Size.y; }
		void setSizeHeight(float y) { Size.y = y; }
		*/

		sf::Sprite getBody()const { return _body; }

		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void render() = 0;
		
	};
}