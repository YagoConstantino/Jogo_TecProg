#pragma once
#include "Entidade.h"

namespace Entidades
{
	class Personagem :public Entidade
	{
	protected:
		int _num_vidas;
		bool _onGround;
		bool _vivo;
		sf::Vector2f _speed;

	public:
		Personagem(float inicialX = 0, float inicialY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr, int vidas=1 );
		
		virtual ~Personagem();

		bool getOnGround()const;
		void setGround(bool ong);

		bool getVivo()const;
		void setVivo(bool ong);

		int getVidas()const;
		void setVidas(int vid);

		virtual void sofrerGravidade(float gravidade);

		virtual void pular();

		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void render() = 0;
	};
}