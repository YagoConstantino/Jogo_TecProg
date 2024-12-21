#pragma once
#include "Personagem.h"
#include <iostream>
#include<SFML/Graphics.hpp>
namespace Entidades
{
	class Jogador :public Entidades::Personagem
	{
	private:
		// Estado de paralisia
		sf::Sprite telaParalisada; // pode criar uma classe figura para o sprite e a textura
		sf::Texture* texturaTela;
		sf::Clock _clockParalisia; // clock diferente do clock pulo
		float _duracaoParalisia;
		float _tempoParalisado;
		bool _paralisado;
		//

		sf::Clock _clockAtaque;
		bool _atacando;
		float _tempoAtaque;
		int _direcao;

		float tempoPulo;
		int _pontos;

		std::string nome;
		float _velocidade;
		std::vector<sf::Texture*> _texturas;
	public:
		Jogador(float inlX = 0, float inY = 0, Gerenciadores::Gerenciador_Grafico* pgra = nullptr,
			std::string name = "");

		~Jogador();

		void setNome(std::string& name);
		std::string getNome()const;

		void setParalisado(const bool para, float duracao);

		void SetPontos(int pont);
		int getPontos()const;

		void pular();
		void mover();
		void setTexture(int direcao);
		void adicionarTextura(const std::string& path);

		bool getAtacando()const;
		void setAtacando(bool atac);


		void executar();
		//void SalvarDataBuffer();

	};

}