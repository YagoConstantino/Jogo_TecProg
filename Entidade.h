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
		

	public:
		Entidade() :_x(0), _y(0) {};
		~Entidade() {};

		virtual void executar() = 0;
		virtual void salvar() = 0;
		
	};
}